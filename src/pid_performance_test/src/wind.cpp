#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("float32_publisher");
    auto publisher = node->create_publisher<std_msgs::msg::Float32>("/vrx/debug/wind/speed", 10);

    rclcpp::Rate rate(10); // Publish at 10 Hz

    while (rclcpp::ok()) {
        auto message = std_msgs::msg::Float32();
        message.data = 10000.0; // Replace with your desired float64 value

        publisher->publish(message);

        rclcpp::spin_some(node);
        rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}

