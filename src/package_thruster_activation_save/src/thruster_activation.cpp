#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"


// THIS CODE PUBLISHES A 12000.0 VALUE TO THE THRUSTER

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // Create a ROS 2 node
    auto node = rclcpp::Node::make_shared("thruster_activation");

    // Create a publisher for the "my_topic" topic
    auto publisher = node->create_publisher<std_msgs::msg::Float64>("/wamv/thrusters/main/thrust", 10);

    // Define a rate at which to publish messages (e.g., 1 Hz)
    rclcpp::Rate rate(1);

    auto speed = 12000.0;
    while (rclcpp::ok()) {
    
        auto message = std_msgs::msg::Float64();
        message.data = speed;

        // Publish the message
        RCLCPP_INFO(node->get_logger(), "Publish: %.2f", message.data);
        publisher->publish(message);

        // Spin the node
        rclcpp::spin_some(node);

        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}

