// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_interfaces:msg/ObjectData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_interfaces/msg/detail/object_data__rosidl_typesupport_introspection_c.h"
#include "my_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_interfaces/msg/detail/object_data__functions.h"
#include "my_interfaces/msg/detail/object_data__struct.h"


// Include directives for member types
// Member `position`
#include "std_msgs/msg/int32_multi_array.h"
// Member `position`
#include "std_msgs/msg/detail/int32_multi_array__rosidl_typesupport_introspection_c.h"
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_interfaces__msg__ObjectData__init(message_memory);
}

void my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_fini_function(void * message_memory)
{
  my_interfaces__msg__ObjectData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_member_array[2] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__ObjectData, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_interfaces__msg__ObjectData, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_members = {
  "my_interfaces__msg",  // message namespace
  "ObjectData",  // message name
  2,  // number of fields
  sizeof(my_interfaces__msg__ObjectData),
  my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_member_array,  // message members
  my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_init_function,  // function to initialize message memory (memory has to be allocated)
  my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_type_support_handle = {
  0,
  &my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_interfaces, msg, ObjectData)() {
  my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Int32MultiArray)();
  my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_type_support_handle.typesupport_identifier) {
    my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_interfaces__msg__ObjectData__rosidl_typesupport_introspection_c__ObjectData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
