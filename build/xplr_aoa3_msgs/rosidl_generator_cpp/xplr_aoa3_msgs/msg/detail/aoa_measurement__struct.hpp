// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
// generated code does not contain a copyright notice

#ifndef XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__STRUCT_HPP_
#define XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__xplr_aoa3_msgs__msg__AoaMeasurement __attribute__((deprecated))
#else
# define DEPRECATED__xplr_aoa3_msgs__msg__AoaMeasurement __declspec(deprecated)
#endif

namespace xplr_aoa3_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AoaMeasurement_
{
  using Type = AoaMeasurement_<ContainerAllocator>;

  explicit AoaMeasurement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag_id = "";
      this->anchor_id = "";
      this->azimuth = 0l;
      this->elevation = 0l;
      this->rssi = 0l;
      this->channel = 0l;
      this->timestamp = 0ul;
      this->seq = 0ul;
    }
  }

  explicit AoaMeasurement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    tag_id(_alloc),
    anchor_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag_id = "";
      this->anchor_id = "";
      this->azimuth = 0l;
      this->elevation = 0l;
      this->rssi = 0l;
      this->channel = 0l;
      this->timestamp = 0ul;
      this->seq = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _tag_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tag_id_type tag_id;
  using _anchor_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _anchor_id_type anchor_id;
  using _azimuth_type =
    int32_t;
  _azimuth_type azimuth;
  using _elevation_type =
    int32_t;
  _elevation_type elevation;
  using _rssi_type =
    int32_t;
  _rssi_type rssi;
  using _channel_type =
    int32_t;
  _channel_type channel;
  using _timestamp_type =
    uint32_t;
  _timestamp_type timestamp;
  using _seq_type =
    uint32_t;
  _seq_type seq;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__tag_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tag_id = _arg;
    return *this;
  }
  Type & set__anchor_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->anchor_id = _arg;
    return *this;
  }
  Type & set__azimuth(
    const int32_t & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__elevation(
    const int32_t & _arg)
  {
    this->elevation = _arg;
    return *this;
  }
  Type & set__rssi(
    const int32_t & _arg)
  {
    this->rssi = _arg;
    return *this;
  }
  Type & set__channel(
    const int32_t & _arg)
  {
    this->channel = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint32_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__seq(
    const uint32_t & _arg)
  {
    this->seq = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator> *;
  using ConstRawPtr =
    const xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xplr_aoa3_msgs__msg__AoaMeasurement
    std::shared_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xplr_aoa3_msgs__msg__AoaMeasurement
    std::shared_ptr<xplr_aoa3_msgs::msg::AoaMeasurement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AoaMeasurement_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->tag_id != other.tag_id) {
      return false;
    }
    if (this->anchor_id != other.anchor_id) {
      return false;
    }
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->elevation != other.elevation) {
      return false;
    }
    if (this->rssi != other.rssi) {
      return false;
    }
    if (this->channel != other.channel) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->seq != other.seq) {
      return false;
    }
    return true;
  }
  bool operator!=(const AoaMeasurement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AoaMeasurement_

// alias to use template instance with default allocator
using AoaMeasurement =
  xplr_aoa3_msgs::msg::AoaMeasurement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xplr_aoa3_msgs

#endif  // XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__STRUCT_HPP_
