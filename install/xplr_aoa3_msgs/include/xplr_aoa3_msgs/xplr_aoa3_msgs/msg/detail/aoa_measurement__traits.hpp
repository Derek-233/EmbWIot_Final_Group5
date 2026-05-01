// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
// generated code does not contain a copyright notice

#ifndef XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__TRAITS_HPP_
#define XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xplr_aoa3_msgs/msg/detail/aoa_measurement__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace xplr_aoa3_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AoaMeasurement & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: tag_id
  {
    out << "tag_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tag_id, out);
    out << ", ";
  }

  // member: anchor_id
  {
    out << "anchor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.anchor_id, out);
    out << ", ";
  }

  // member: azimuth
  {
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << ", ";
  }

  // member: elevation
  {
    out << "elevation: ";
    rosidl_generator_traits::value_to_yaml(msg.elevation, out);
    out << ", ";
  }

  // member: rssi
  {
    out << "rssi: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi, out);
    out << ", ";
  }

  // member: channel
  {
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: seq
  {
    out << "seq: ";
    rosidl_generator_traits::value_to_yaml(msg.seq, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AoaMeasurement & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: tag_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tag_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tag_id, out);
    out << "\n";
  }

  // member: anchor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "anchor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.anchor_id, out);
    out << "\n";
  }

  // member: azimuth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << "\n";
  }

  // member: elevation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elevation: ";
    rosidl_generator_traits::value_to_yaml(msg.elevation, out);
    out << "\n";
  }

  // member: rssi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rssi: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi, out);
    out << "\n";
  }

  // member: channel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: seq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seq: ";
    rosidl_generator_traits::value_to_yaml(msg.seq, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AoaMeasurement & msg, bool use_flow_style = false)
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

}  // namespace xplr_aoa3_msgs

namespace rosidl_generator_traits
{

[[deprecated("use xplr_aoa3_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xplr_aoa3_msgs::msg::AoaMeasurement & msg,
  std::ostream & out, size_t indentation = 0)
{
  xplr_aoa3_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xplr_aoa3_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const xplr_aoa3_msgs::msg::AoaMeasurement & msg)
{
  return xplr_aoa3_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xplr_aoa3_msgs::msg::AoaMeasurement>()
{
  return "xplr_aoa3_msgs::msg::AoaMeasurement";
}

template<>
inline const char * name<xplr_aoa3_msgs::msg::AoaMeasurement>()
{
  return "xplr_aoa3_msgs/msg/AoaMeasurement";
}

template<>
struct has_fixed_size<xplr_aoa3_msgs::msg::AoaMeasurement>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<xplr_aoa3_msgs::msg::AoaMeasurement>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<xplr_aoa3_msgs::msg::AoaMeasurement>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__TRAITS_HPP_
