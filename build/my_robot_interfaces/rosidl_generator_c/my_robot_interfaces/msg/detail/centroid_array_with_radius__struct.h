// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/CentroidArrayWithRadius.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_ARRAY_WITH_RADIUS__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_ARRAY_WITH_RADIUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'centroids'
#include "my_robot_interfaces/msg/detail/centroid_with_radius__struct.h"

/// Struct defined in msg/CentroidArrayWithRadius in the package my_robot_interfaces.
/**
  * CentroidArrayWithRadius.msg
 */
typedef struct my_robot_interfaces__msg__CentroidArrayWithRadius
{
  my_robot_interfaces__msg__CentroidWithRadius__Sequence centroids;
} my_robot_interfaces__msg__CentroidArrayWithRadius;

// Struct for a sequence of my_robot_interfaces__msg__CentroidArrayWithRadius.
typedef struct my_robot_interfaces__msg__CentroidArrayWithRadius__Sequence
{
  my_robot_interfaces__msg__CentroidArrayWithRadius * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__CentroidArrayWithRadius__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__CENTROID_ARRAY_WITH_RADIUS__STRUCT_H_
