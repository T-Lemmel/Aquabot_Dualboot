// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_robot_interfaces:msg/CentroidArrayWithRadius.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_robot_interfaces/msg/detail/centroid_array_with_radius__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_robot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CentroidArrayWithRadius_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_robot_interfaces::msg::CentroidArrayWithRadius(_init);
}

void CentroidArrayWithRadius_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_robot_interfaces::msg::CentroidArrayWithRadius *>(message_memory);
  typed_message->~CentroidArrayWithRadius();
}

size_t size_function__CentroidArrayWithRadius__centroids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<my_robot_interfaces::msg::CentroidWithRadius> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CentroidArrayWithRadius__centroids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<my_robot_interfaces::msg::CentroidWithRadius> *>(untyped_member);
  return &member[index];
}

void * get_function__CentroidArrayWithRadius__centroids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<my_robot_interfaces::msg::CentroidWithRadius> *>(untyped_member);
  return &member[index];
}

void fetch_function__CentroidArrayWithRadius__centroids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const my_robot_interfaces::msg::CentroidWithRadius *>(
    get_const_function__CentroidArrayWithRadius__centroids(untyped_member, index));
  auto & value = *reinterpret_cast<my_robot_interfaces::msg::CentroidWithRadius *>(untyped_value);
  value = item;
}

void assign_function__CentroidArrayWithRadius__centroids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<my_robot_interfaces::msg::CentroidWithRadius *>(
    get_function__CentroidArrayWithRadius__centroids(untyped_member, index));
  const auto & value = *reinterpret_cast<const my_robot_interfaces::msg::CentroidWithRadius *>(untyped_value);
  item = value;
}

void resize_function__CentroidArrayWithRadius__centroids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<my_robot_interfaces::msg::CentroidWithRadius> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CentroidArrayWithRadius_message_member_array[1] = {
  {
    "centroids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<my_robot_interfaces::msg::CentroidWithRadius>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces::msg::CentroidArrayWithRadius, centroids),  // bytes offset in struct
    nullptr,  // default value
    size_function__CentroidArrayWithRadius__centroids,  // size() function pointer
    get_const_function__CentroidArrayWithRadius__centroids,  // get_const(index) function pointer
    get_function__CentroidArrayWithRadius__centroids,  // get(index) function pointer
    fetch_function__CentroidArrayWithRadius__centroids,  // fetch(index, &value) function pointer
    assign_function__CentroidArrayWithRadius__centroids,  // assign(index, value) function pointer
    resize_function__CentroidArrayWithRadius__centroids  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CentroidArrayWithRadius_message_members = {
  "my_robot_interfaces::msg",  // message namespace
  "CentroidArrayWithRadius",  // message name
  1,  // number of fields
  sizeof(my_robot_interfaces::msg::CentroidArrayWithRadius),
  CentroidArrayWithRadius_message_member_array,  // message members
  CentroidArrayWithRadius_init_function,  // function to initialize message memory (memory has to be allocated)
  CentroidArrayWithRadius_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CentroidArrayWithRadius_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CentroidArrayWithRadius_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_robot_interfaces::msg::CentroidArrayWithRadius>()
{
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::CentroidArrayWithRadius_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_robot_interfaces, msg, CentroidArrayWithRadius)() {
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::CentroidArrayWithRadius_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
