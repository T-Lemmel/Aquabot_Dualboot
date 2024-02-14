// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/CentroidWithRadius.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_WITH_RADIUS__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_WITH_RADIUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/CentroidWithRadius in the package my_robot_interfaces.
/**
  * CentroidWithRadius.msg
 */
typedef struct my_robot_interfaces__msg__CentroidWithRadius
{
  /// to store x, y, z coordinates of the centroid
  geometry_msgs__msg__Point position;
  /// to store the radius
  double radius;
} my_robot_interfaces__msg__CentroidWithRadius;

// Struct for a sequence of my_robot_interfaces__msg__CentroidWithRadius.
typedef struct my_robot_interfaces__msg__CentroidWithRadius__Sequence
{
  my_robot_interfaces__msg__CentroidWithRadius * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__CentroidWithRadius__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_WITH_RADIUS__STRUCT_H_
