// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_interfaces:msg/ObjectData.idl
// generated code does not contain a copyright notice
#include "my_interfaces/msg/detail/object_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
#include "std_msgs/msg/detail/int32_multi_array__functions.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
my_interfaces__msg__ObjectData__init(my_interfaces__msg__ObjectData * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!std_msgs__msg__Int32MultiArray__init(&msg->position)) {
    my_interfaces__msg__ObjectData__fini(msg);
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    my_interfaces__msg__ObjectData__fini(msg);
    return false;
  }
  return true;
}

void
my_interfaces__msg__ObjectData__fini(my_interfaces__msg__ObjectData * msg)
{
  if (!msg) {
    return;
  }
  // position
  std_msgs__msg__Int32MultiArray__fini(&msg->position);
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
my_interfaces__msg__ObjectData__are_equal(const my_interfaces__msg__ObjectData * lhs, const my_interfaces__msg__ObjectData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (!std_msgs__msg__Int32MultiArray__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
my_interfaces__msg__ObjectData__copy(
  const my_interfaces__msg__ObjectData * input,
  my_interfaces__msg__ObjectData * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  if (!std_msgs__msg__Int32MultiArray__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

my_interfaces__msg__ObjectData *
my_interfaces__msg__ObjectData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__ObjectData * msg = (my_interfaces__msg__ObjectData *)allocator.allocate(sizeof(my_interfaces__msg__ObjectData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_interfaces__msg__ObjectData));
  bool success = my_interfaces__msg__ObjectData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_interfaces__msg__ObjectData__destroy(my_interfaces__msg__ObjectData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_interfaces__msg__ObjectData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_interfaces__msg__ObjectData__Sequence__init(my_interfaces__msg__ObjectData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__ObjectData * data = NULL;

  if (size) {
    data = (my_interfaces__msg__ObjectData *)allocator.zero_allocate(size, sizeof(my_interfaces__msg__ObjectData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_interfaces__msg__ObjectData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_interfaces__msg__ObjectData__fini(&data[i - 1]);
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
my_interfaces__msg__ObjectData__Sequence__fini(my_interfaces__msg__ObjectData__Sequence * array)
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
      my_interfaces__msg__ObjectData__fini(&array->data[i]);
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

my_interfaces__msg__ObjectData__Sequence *
my_interfaces__msg__ObjectData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_interfaces__msg__ObjectData__Sequence * array = (my_interfaces__msg__ObjectData__Sequence *)allocator.allocate(sizeof(my_interfaces__msg__ObjectData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_interfaces__msg__ObjectData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_interfaces__msg__ObjectData__Sequence__destroy(my_interfaces__msg__ObjectData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_interfaces__msg__ObjectData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_interfaces__msg__ObjectData__Sequence__are_equal(const my_interfaces__msg__ObjectData__Sequence * lhs, const my_interfaces__msg__ObjectData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_interfaces__msg__ObjectData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_interfaces__msg__ObjectData__Sequence__copy(
  const my_interfaces__msg__ObjectData__Sequence * input,
  my_interfaces__msg__ObjectData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_interfaces__msg__ObjectData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_interfaces__msg__ObjectData * data =
      (my_interfaces__msg__ObjectData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_interfaces__msg__ObjectData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_interfaces__msg__ObjectData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_interfaces__msg__ObjectData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
