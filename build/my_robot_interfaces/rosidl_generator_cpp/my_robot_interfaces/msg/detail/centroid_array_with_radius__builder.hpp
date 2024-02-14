// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/CentroidArrayWithRadius.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_ARRAY_WITH_RADIUS__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_ARRAY_WITH_RADIUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/centroid_array_with_radius__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_CentroidArrayWithRadius_centroids
{
public:
  Init_CentroidArrayWithRadius_centroids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::CentroidArrayWithRadius centroids(::my_robot_interfaces::msg::CentroidArrayWithRadius::_centroids_type arg)
  {
    msg_.centroids = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::CentroidArrayWithRadius msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::CentroidArrayWithRadius>()
{
  return my_robot_interfaces::msg::builder::Init_CentroidArrayWithRadius_centroids();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_ARRAY_WITH_RADIUS__BUILDER_HPP_
