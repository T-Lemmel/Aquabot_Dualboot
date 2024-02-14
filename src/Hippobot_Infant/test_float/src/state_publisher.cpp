#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("float64_publisher");
    auto publisher = node->create_publisher<std_msgs::msg::Float64>("state_topic", 10);

    rclcpp::Rate rate(1); // Publish at 1 Hz

    auto message = std_msgs::msg::Float64();
    message.data= 12000.0;
    
    while (rclcpp::ok()) {
        
                
        message.data = message.data - 100.0; // Replace with your desired float64 value

	RCLCPP_INFO(node->get_logger(), "Publish: %.2f", message.data);
        publisher->publish(message);

        rclcpp::spin_some(node);
        
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}

