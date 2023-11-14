#include "rclcpp/rclcpp.hpp"
#include "ros_gz_interfaces/msg/param_vec.hpp"
#include "std_msgs/msg/float64.hpp"

rclcpp::Node::SharedPtr node; // Declare node globally
rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher; // Declare publisher globally


void isolate_bearing(const ros_gz_interfaces::msg::ParamVec::SharedPtr msg) {

	
	for (const auto& param : msg->params) {
	        if (param.name == "bearing") {
	            // Access the 'bearing' value
	            auto bearing = param.value.double_value;
	            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Bearing: %f", bearing);
	            auto bearing_msg = std_msgs::msg::Float64(); // Create a Float64 message
    		    bearing_msg.data = bearing; // Set the 'data' field of the message
    		    
	            publisher->publish(bearing_msg); //C'EST CETTE LIGNE QUI POSE PROBLEME
	            
    		    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing Bearing: %f", bearing);
	        }
	    }
    
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    node = rclcpp::Node::make_shared("state_isolated_bearing");
    publisher = node->create_publisher<std_msgs::msg::Float64>("state_isolated_bearing", 10);
    auto subscription = node->create_subscription<ros_gz_interfaces::msg::ParamVec>(
        "/wamv/sensors/acoustics/receiver/range_bearing",
        10,
        isolate_bearing
    );
    rclcpp::Rate rate(1); // Publish at 1 Hz
      
    while (rclcpp::ok()) {
        
        rclcpp::spin_some(node);        
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}

