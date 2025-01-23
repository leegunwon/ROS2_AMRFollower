// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_interfaces:msg/ObjectData.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__STRUCT_HPP_
#define MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "std_msgs/msg/detail/int32_multi_array__struct.hpp"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_interfaces__msg__ObjectData __attribute__((deprecated))
#else
# define DEPRECATED__my_interfaces__msg__ObjectData __declspec(deprecated)
#endif

namespace my_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectData_
{
  using Type = ObjectData_<ContainerAllocator>;

  explicit ObjectData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init),
    image(_init)
  {
    (void)_init;
  }

  explicit ObjectData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init),
    image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _position_type =
    std_msgs::msg::Int32MultiArray_<ContainerAllocator>;
  _position_type position;
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__position(
    const std_msgs::msg::Int32MultiArray_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_interfaces::msg::ObjectData_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_interfaces::msg::ObjectData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::ObjectData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_interfaces::msg::ObjectData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_interfaces__msg__ObjectData
    std::shared_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_interfaces__msg__ObjectData
    std::shared_ptr<my_interfaces::msg::ObjectData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectData_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectData_

// alias to use template instance with default allocator
using ObjectData =
  my_interfaces::msg::ObjectData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_interfaces

#endif  // MY_INTERFACES__MSG__DETAIL__OBJECT_DATA__STRUCT_HPP_
