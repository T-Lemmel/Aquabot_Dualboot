#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

void messageCallback(const std_msgs::msg::Float64::SharedPtr msg) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Received: %f", msg->data);
}

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("float64_subscriber");
    auto subscription = node->create_subscription<std_msgs::msg::Float64>(
        "topic_float",
        10,
        messageCallback
    );

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

