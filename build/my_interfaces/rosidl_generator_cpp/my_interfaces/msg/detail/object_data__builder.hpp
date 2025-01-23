// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_interfaces:msg/ObjectData.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__BUILDER_HPP_
#define MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_interfaces/msg/detail/object_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectData_image
{
public:
  explicit Init_ObjectData_image(::my_interfaces::msg::ObjectData & msg)
  : msg_(msg)
  {}
  ::my_interfaces::msg::ObjectData image(::my_interfaces::msg::ObjectData::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_interfaces::msg::ObjectData msg_;
};

class Init_ObjectData_position
{
public:
  Init_ObjectData_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectData_image position(::my_interfaces::msg::ObjectData::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_ObjectData_image(msg_);
  }

private:
  ::my_interfaces::msg::ObjectData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_interfaces::msg::ObjectData>()
{
  return my_interfaces::msg::builder::Init_ObjectData_position();
}

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__BUILDER_HPP_
