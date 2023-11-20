cmake_minimum_required(VERSION 3.5)
project(pid_performance_test)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(wind src/wind.cpp)
ament_target_dependencies(wind rclcpp std_msgs)

install(TARGETS
    wind
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()

