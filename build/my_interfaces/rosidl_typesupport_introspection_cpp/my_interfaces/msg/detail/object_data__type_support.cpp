// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_interfaces:msg/ObjectData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_interfaces/msg/detail/object_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ObjectData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_interfaces::msg::ObjectData(_init);
}

void ObjectData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_interfaces::msg::ObjectData *>(message_memory);
  typed_message->~ObjectData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ObjectData_message_member_array[2] = {
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Int32MultiArray>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::ObjectData, position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces::msg::ObjectData, image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ObjectData_message_members = {
  "my_interfaces::msg",  // message namespace
  "ObjectData",  // message name
  2,  // number of fields
  sizeof(my_interfaces::msg::ObjectData),
  ObjectData_message_member_array,  // message members
  ObjectData_init_function,  // function to initialize message memory (memory has to be allocated)
  ObjectData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ObjectData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ObjectData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_interfaces::msg::ObjectData>()
{
  return &::my_interfaces::msg::rosidl_typesupport_introspection_cpp::ObjectData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_interfaces, msg, ObjectData)() {
  return &::my_interfaces::msg::rosidl_typesupport_introspection_cpp::ObjectData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
