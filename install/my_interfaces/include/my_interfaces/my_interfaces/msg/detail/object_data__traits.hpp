// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_interfaces:msg/ObjectData.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__TRAITS_HPP_
#define MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_interfaces/msg/detail/object_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "std_msgs/msg/detail/int32_multi_array__traits.hpp"
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace my_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectData & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_interfaces::msg::ObjectData & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_interfaces::msg::ObjectData & msg)
{
  return my_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_interfaces::msg::ObjectData>()
{
  return "my_interfaces::msg::ObjectData";
}

template<>
inline const char * name<my_interfaces::msg::ObjectData>()
{
  return "my_interfaces/msg/ObjectData";
}

template<>
struct has_fixed_size<my_interfaces::msg::ObjectData>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value && has_fixed_size<std_msgs::msg::Int32MultiArray>::value> {};

template<>
struct has_bounded_size<my_interfaces::msg::ObjectData>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value && has_bounded_size<std_msgs::msg::Int32MultiArray>::value> {};

template<>
struct is_message<my_interfaces::msg::ObjectData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__TRAITS_HPP_
