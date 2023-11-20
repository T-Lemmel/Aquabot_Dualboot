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

class Place_frame(Node):

    def __init__(self):
        super().__init__("Place_frame")

        # force use_sim_time
        param = Parameter('use_sim_time', Parameter.Type.BOOL, True)
        self.set_parameters([param])

        Waypoint.br = TransformBroadcaster(self)

        # get Waypoint data
        self.Boat = Waypoint('wamv/wamv/base_link')
        self.gps_sub = self.create_subscription(NavSatFix, '/wamv/sensors/gps/gps/fix', self.gps_cb, 10)
        self.imu_sub = self.create_subscription(Imu, '/wamv/sensors/imu/imu/data', self.imu_cb, 10)

        # buoy
        self.buoy = Waypoint('buoy')
        self.buoy.pose.header.frame_id = 'wamv/wamv/base_link'
        self.buoy_sub = self.create_subscription(ParamVec, '/wamv/sensors/acoustics/receiver/range_bearing', self.buoy_cb, 10)
        self.buoy.distance_to_keep = 0.0

        #waypoint
        self.Waypoint = Waypoint('waypoint')
        self.waypoint_x = 0.0
        self.waypoint_y = 0.0
        self.Waypoint_sub_x = self.create_subscription(Float64, 'waypoint_x', self.waypoint_frame_placing_x, 10)
        self.Waypoint_sub_y = self.create_subscription(Float64, 'waypoint_y', self.waypoint_frame_placing_y, 10)
        
        # publishing timer
        self.timer = self.create_timer(0.05, self.loop)
        
    def is_init(self):
        return self.Boat.Z is not None

    def gps_cb(self, msg: NavSatFix):

        if not self.is_init():
            self.Boat.E,self.Boat.N, self.Boat.z,self.Boat.Z = utm.from_latlon(msg.latitude, msg.longitude)
            return
        
        self.Boat.update(latitude = msg.latitude, longitude = msg.longitude)

    def imu_cb(self, msg: Imu):
        self.Boat.update(orientation = msg.orientation)


    def buoy_cb(self, msg: ParamVec):

        rho = None
        theta = None

        for param in msg.params:
            if param.name == 'range':
                rho = param.value.double_value
            elif param.name == 'bearing':
                theta = param.value.double_value

        if rho is None or theta is None:
            return

        self.buoy.pose.transform.translation.x = rho * math.cos(theta)
        self.buoy.pose.transform.translation.y = rho * math.sin(theta)
    
    def waypoint_frame_placing_x(self, msg: Float64):

        if (self.waypoint_x != msg.data) :
            self.Waypoint.pose.transform.translation.x = msg.data
            self.waypoint_x = msg.data
    
    def waypoint_frame_placing_y(self, msg: Float64):

        if (self.waypoint_y != msg.data) :
            self.Waypoint.pose.transform.translation.y = msg.data 
            self.waypoint_y = msg.data

    def loop(self):

        if not self.is_init():
            return

        now = self.get_clock().now()
        self.Boat.publish(now)
            
        self.Waypoint.publish(now)

        self.buoy.publish(now)

def main():
    rclpy.init()

    try:
        place_frame = Place_frame()

        while rclpy.ok():
            rclpy.spin_once(place_frame)

    finally:
        # Cleanup and shutdown when the loop is interrupted
        place_frame.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

