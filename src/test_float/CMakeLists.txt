cmake_minimum_required(VERSION 3.8)
project(test_float)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

##find dependencies

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros_gz_interfaces REQUIRED)

add_executable(talkerfloat src/publisher_float.cpp)
add_executable(listenerfloat src/subscriber_float.cpp)
add_executable(state_publisher src/state_publisher.cpp)
add_executable(isolating_bearing src/isolating_bearing.cpp)

ament_target_dependencies(listenerfloat rclcpp std_msgs)
ament_target_dependencies(talkerfloat rclcpp std_msgs)
ament_target_dependencies(state_publisher rclcpp std_msgs)
ament_target_dependencies(isolating_bearing rclcpp std_msgs ros_gz_interfaces)


## allows for ros2 run
  
install(TARGETS
  
  isolating_bearing
  state_publisher
  talkerfloat
  listenerfloat
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
