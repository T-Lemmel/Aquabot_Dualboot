// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/CentroidWithRadius.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/centroid_with_radius__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
my_robot_interfaces__msg__CentroidWithRadius__init(my_robot_interfaces__msg__CentroidWithRadius * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    my_robot_interfaces__msg__CentroidWithRadius__fini(msg);
    return false;
  }
  // radius
  return true;
}

void
my_robot_interfaces__msg__CentroidWithRadius__fini(my_robot_interfaces__msg__CentroidWithRadius * msg)
{
  if (!msg) {
    return;
  }
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // radius
}

bool
my_robot_interfaces__msg__CentroidWithRadius__are_equal(const my_robot_interfaces__msg__CentroidWithRadius * lhs, const my_robot_interfaces__msg__CentroidWithRadius * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__CentroidWithRadius__copy(
  const my_robot_interfaces__msg__CentroidWithRadius * input,
  my_robot_interfaces__msg__CentroidWithRadius * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  return true;
}

my_robot_interfaces__msg__CentroidWithRadius *
my_robot_interfaces__msg__CentroidWithRadius__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__CentroidWithRadius * msg = (my_robot_interfaces__msg__CentroidWithRadius *)allocator.allocate(sizeof(my_robot_interfaces__msg__CentroidWithRadius), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__CentroidWithRadius));
  bool success = my_robot_interfaces__msg__CentroidWithRadius__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__CentroidWithRadius__destroy(my_robot_interfaces__msg__CentroidWithRadius * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__CentroidWithRadius__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__CentroidWithRadius__Sequence__init(my_robot_interfaces__msg__CentroidWithRadius__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__CentroidWithRadius * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__CentroidWithRadius *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__CentroidWithRadius), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__CentroidWithRadius__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__CentroidWithRadius__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_robot_interfaces__msg__CentroidWithRadius__Sequence__fini(my_robot_interfaces__msg__CentroidWithRadius__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__CentroidWithRadius__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_robot_interfaces__msg__CentroidWithRadius__Sequence *
my_robot_interfaces__msg__CentroidWithRadius__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__CentroidWithRadius__Sequence * array = (my_robot_interfaces__msg__CentroidWithRadius__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__CentroidWithRadius__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__CentroidWithRadius__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__CentroidWithRadius__Sequence__destroy(my_robot_interfaces__msg__CentroidWithRadius__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__CentroidWithRadius__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__CentroidWithRadius__Sequence__are_equal(const my_robot_interfaces__msg__CentroidWithRadius__Sequence * lhs, const my_robot_interfaces__msg__CentroidWithRadius__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__CentroidWithRadius__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__CentroidWithRadius__Sequence__copy(
  const my_robot_interfaces__msg__CentroidWithRadius__Sequence * input,
  my_robot_interfaces__msg__CentroidWithRadius__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__CentroidWithRadius);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__CentroidWithRadius * data =
      (my_robot_interfaces__msg__CentroidWithRadius *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__CentroidWithRadius__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__CentroidWithRadius__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__CentroidWithRadius__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
