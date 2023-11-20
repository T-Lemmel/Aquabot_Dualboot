#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, NavSatFix
from geometry_msgs.msg import TransformStamped, PoseArray
from rclpy.parameter import Parameter
from geometry_msgs.msg import Quaternion
from tf2_ros import TransformBroadcaster, TransformListener, TransformException, Buffer
from ros_gz_interfaces.msg import ParamVec
import utm
from copy import deepcopy
from rcl_interfaces.msg import SetParametersResult
from std_msgs.msg import Float64
import math


me = 'wamv/wamv/base_link'

def clamp(val, high):
    if abs(val) > high:
        return val * high / abs(val)
    return val


class Waypoint:
    E = None
    N = None
    z = None
    Z = None
    br = None
    moving = False
    distance_to_keep = 0.0
    already_placed_x = False
    already_placed_y = False

    def __init__(self, link):

        # store info about previous
        self.t0 = None
        self.heading = None
        self.pose = TransformStamped()
        self.pose.header.frame_id = 'world'
        self.pose.child_frame_id = link

    def update(self, now = None, latitude=None, longitude=None, orientation=None):
        if latitude is not None:
            E,N,_,_ = utm.from_latlon(latitude, longitude, self.z, self.Z)

            x = E - self.E
            y = N - self.N

            # estim velocity heading
            if now is not None and self.t0 is None:
                self.t0 = now
            elif self.t0 is not None:
                # previous pose is valid: estimate heading
                dt = (now.nanoseconds - self.t0.nanoseconds) * 1e-9
                self.heading = [(x - self.pose.transform.translation.x) / dt,
                                (y - self.pose.transform.translation.y) / dt]
                self.t0 = now
                
            self.pose.transform.translation.x = x
            self.pose.transform.translation.y = y

        if orientation is not None:
            self.pose.transform.rotation = orientation

    def publish(self, now):

        self.pose.header.stamp = now.to_msg()

        if self.heading is not None: #estimate pose if moving
            pose = deepcopy(self.pose)
            dt = (now.nanoseconds - self.t0.nanoseconds) * 1e-9
            pose.transform.translation.x += self.heading[0]*dt 
            pose.transform.translation.y += self.heading[1]*dt 
            self.br.sendTransform(pose) #move frame
        else:
            self.br.sendTransform(self.pose) #move frame

class Tracker(Node):
    
    def __init__(self):

        super().__init__('tracker')

        #waypoint
        self.target = Waypoint('waypoint')
        
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.angle_pub = self.create_publisher(Float64, '/wamv/thrusters/main/pos', 10)
        self.thruster_angle = 0.0
        self.angle_sub = self.create_subscription(Float64,'/wamv/thrusters/main/pos', self.update_thruster_angle, 10)
        
        self.thrust_pub = self.create_publisher(Float64, '/wamv/thrusters/main/thrust', 10)

        self.angle_error_pub = self.create_publisher(Float64, 'angle/error', 10)

        # initialization of Pid internal variables
        self.old_error_angle = 0.0
        self.old_error_distance = 0.0
        self.error_angle_integer = 0.0
        self.error_angle_derivative = 0.0
        self.error_distance_integer = 0.0
        self.error_distance_derivative = 0.0

        self.orientation = Quaternion()#relative orientation of boat frame to fixed world frame (quaternions) 
        self.imu_sub = self.create_subscription(Imu, '/wamv/sensors/imu/imu/data', self.update_orientation, 10)

        # control gains Aiming to work fine for waypoints at max pi/3 relative orientation to the boat 
        self.Kx = 75.
        self.Kw = 1.0
        self.Kxi = 10.0
        self.Kwi = 0.0005
        self.Kxd = 0.1
        self.Kwd = 0.5 

        self.timer = self.create_timer(0.1, self.control_loop)

    def update_thruster_angle(self, msg: Float64):
        self.thruster_angle = msg.data

    def update_orientation(self, msg: Imu):
        self.orientation = msg.orientation

    def control_loop(self):

        # get pose error

        try:
            if ' ' in self.target.pose.header.frame_id:
                # given as (x,y) in world frame
                pose = self.tf_buffer.lookup_transform('world', me,
                            rclpy.time.Time()).transform
                x, y = map(float, self.target.split())
                dx = x - pose.translation.x
                dy = y - pose.translation.y
                theta = 2*math.atan2(pose.rotation.z, pose.rotation.w)
                c, s = math.cos(theta), math.sin(theta)

                err = pose.translation
                err.x = dx*c - dy*s
                err.y = dx*s + dy*c 

            else :
                
                if self.target.pose.header.frame_id == 'world':
                        
                    err_world_target = self.tf_buffer.lookup_transform(
                        'world',
                        self.target.pose.child_frame_id,
                        rclpy.time.Time()).transform.translation
                    err_world_boat = self.tf_buffer.lookup_transform(
                        'world',
                        me,
                        rclpy.time.Time()).transform.translation
                
                    err = deepcopy(err_world_boat)
                    err.x = err_world_target.x - err_world_boat.x #from boat to target by chasles relation
                    err.y = err_world_target.y - err_world_boat.y #from boat to target by chasles relation

                else : #because the buoy is defined relative to the boat 

                        err = self.tf_buffer.lookup_transform(
                            me,
                            self.target.pose.child_frame_id,
                            rclpy.time.Time()).transform.translation

        except TransformException:
            self.get_logger().info(
                f'Could not transform {me} to {self.target.pose.header.frame_id}')
            self.thrust_pub.publish(Float64())
            self.angle_pub.publish(Float64())
            return
        except ValueError:
            self.get_logger().info(
                f'{self.target} are invalid coordinates')
            self.thrust_pub.publish(Float64())
            self.angle_pub.publish(Float64())
            return

        msg = Float64()

        theta_boat_target = math.atan2(err.y, err.x)
        error_angle = self.orientation.z - theta_boat_target
        self.get_logger().info("error angle = %f" % error_angle)
        msg.data = error_angle
        self.angle_error_pub.publish(msg)

        msg.data = angle = self.Kw*error_angle + self.Kwi*self.error_angle_integer + self.Kwd*self.error_angle_derivative
        self.angle_pub.publish(msg)

        error_distance = math.sqrt(err.x**2+err.y**2) - self.target.distance_to_keep

        self.get_logger().info("distance = %f" % error_distance)
        self.get_logger().info("error x = %f" % err.x)
        self.get_logger().info("error y = %f" % err.y)
        self.error_distance_integer = self.error_distance_integer+error_distance
        self.error_distance_derivative = self.error_distance_derivative + (error_distance - self.old_error_distance)
        self.old_error_distance = error_distance;
        msg.data = self.Kx *error_distance + self.Kxi*self.error_distance_integer + self.Kxd*self.error_distance_derivative

	    # adapt thrust, not too much when rotating
        
        #msg.data = msg.data*(1-0.9*abs(self.thruster_angle)/(math.pi/2))
        if abs(error_angle)>0.4 :
            msg.data = clamp(msg.data, 1000.0)
        elif abs(error_angle)>0.2 :
            msg.data = clamp(msg.data, 6000.0)
        else : 
            msg.data = clamp(msg.data, 12000.0)

        #in cause we went too far, stop the thruster and stop accelerating
        if error_distance < 0 :
            msg.data = abs(msg.data)
            self.error_distance_integer = 0.0

        self.thrust_pub.publish(msg)

def main():
    rclpy.init()

    try:
        tracker = Tracker()

        while rclpy.ok():
            rclpy.spin_once(tracker)

    finally:
        # Cleanup and shutdown when the loop is interrupted
        tracker.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

