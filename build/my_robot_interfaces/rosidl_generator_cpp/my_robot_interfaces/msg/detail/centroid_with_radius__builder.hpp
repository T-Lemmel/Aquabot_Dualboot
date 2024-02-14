// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/CentroidWithRadius.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_WITH_RADIUS__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_WITH_RADIUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/centroid_with_radius__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_CentroidWithRadius_radius
{
public:
  explicit Init_CentroidWithRadius_radius(::my_robot_interfaces::msg::CentroidWithRadius & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::CentroidWithRadius radius(::my_robot_interfaces::msg::CentroidWithRadius::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::CentroidWithRadius msg_;
};

class Init_CentroidWithRadius_position
{
public:
  Init_CentroidWithRadius_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CentroidWithRadius_radius position(::my_robot_interfaces::msg::CentroidWithRadius::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_CentroidWithRadius_radius(msg_);
  }

private:
  ::my_robot_interfaces::msg::CentroidWithRadius msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::CentroidWithRadius>()
{
  return my_robot_interfaces::msg::builder::Init_CentroidWithRadius_position();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_WITH_RADIUS__BUILDER_HPP_
