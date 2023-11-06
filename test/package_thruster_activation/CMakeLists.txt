cmake_minimum_required(VERSION 3.5)
project(package_thruster_activation)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(thruster_activation src/thruster_activation.cpp)
ament_target_dependencies(thruster_activation rclcpp std_msgs)

install(TARGETS
    thruster_activation
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()

