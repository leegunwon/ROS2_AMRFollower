// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_interfaces:msg/ObjectData.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__STRUCT_H_
#define MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__STRUCT_H_

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
#include "std_msgs/msg/detail/int32_multi_array__struct.h"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/ObjectData in the package my_interfaces.
/**
  * ObjectData.msg
  * 객체 데이터를 정의하는 메시지
 */
typedef struct my_interfaces__msg__ObjectData
{
  /// 바운딩 박스 좌표 (x1, y1, x2, y2)
  std_msgs__msg__Int32MultiArray position;
  /// 객체의 잘라낸 이미지
  sensor_msgs__msg__Image image;
} my_interfaces__msg__ObjectData;

// Struct for a sequence of my_interfaces__msg__ObjectData.
typedef struct my_interfaces__msg__ObjectData__Sequence
{
  my_interfaces__msg__ObjectData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_interfaces__msg__ObjectData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__STRUCT_H_
