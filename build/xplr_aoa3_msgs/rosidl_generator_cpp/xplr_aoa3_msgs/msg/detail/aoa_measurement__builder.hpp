// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
// generated code does not contain a copyright notice

#ifndef XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__BUILDER_HPP_
#define XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xplr_aoa3_msgs/msg/detail/aoa_measurement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xplr_aoa3_msgs
{

namespace msg
{

namespace builder
{

class Init_AoaMeasurement_seq
{
public:
  explicit Init_AoaMeasurement_seq(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  ::xplr_aoa3_msgs::msg::AoaMeasurement seq(::xplr_aoa3_msgs::msg::AoaMeasurement::_seq_type arg)
  {
    msg_.seq = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_timestamp
{
public:
  explicit Init_AoaMeasurement_timestamp(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  Init_AoaMeasurement_seq timestamp(::xplr_aoa3_msgs::msg::AoaMeasurement::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_AoaMeasurement_seq(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_channel
{
public:
  explicit Init_AoaMeasurement_channel(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  Init_AoaMeasurement_timestamp channel(::xplr_aoa3_msgs::msg::AoaMeasurement::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_AoaMeasurement_timestamp(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_rssi
{
public:
  explicit Init_AoaMeasurement_rssi(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  Init_AoaMeasurement_channel rssi(::xplr_aoa3_msgs::msg::AoaMeasurement::_rssi_type arg)
  {
    msg_.rssi = std::move(arg);
    return Init_AoaMeasurement_channel(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_elevation
{
public:
  explicit Init_AoaMeasurement_elevation(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  Init_AoaMeasurement_rssi elevation(::xplr_aoa3_msgs::msg::AoaMeasurement::_elevation_type arg)
  {
    msg_.elevation = std::move(arg);
    return Init_AoaMeasurement_rssi(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_azimuth
{
public:
  explicit Init_AoaMeasurement_azimuth(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  Init_AoaMeasurement_elevation azimuth(::xplr_aoa3_msgs::msg::AoaMeasurement::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_AoaMeasurement_elevation(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_anchor_id
{
public:
  explicit Init_AoaMeasurement_anchor_id(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  Init_AoaMeasurement_azimuth anchor_id(::xplr_aoa3_msgs::msg::AoaMeasurement::_anchor_id_type arg)
  {
    msg_.anchor_id = std::move(arg);
    return Init_AoaMeasurement_azimuth(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_tag_id
{
public:
  explicit Init_AoaMeasurement_tag_id(::xplr_aoa3_msgs::msg::AoaMeasurement & msg)
  : msg_(msg)
  {}
  Init_AoaMeasurement_anchor_id tag_id(::xplr_aoa3_msgs::msg::AoaMeasurement::_tag_id_type arg)
  {
    msg_.tag_id = std::move(arg);
    return Init_AoaMeasurement_anchor_id(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

class Init_AoaMeasurement_header
{
public:
  Init_AoaMeasurement_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AoaMeasurement_tag_id header(::xplr_aoa3_msgs::msg::AoaMeasurement::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AoaMeasurement_tag_id(msg_);
  }

private:
  ::xplr_aoa3_msgs::msg::AoaMeasurement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xplr_aoa3_msgs::msg::AoaMeasurement>()
{
  return xplr_aoa3_msgs::msg::builder::Init_AoaMeasurement_header();
}

}  // namespace xplr_aoa3_msgs

#endif  // XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__BUILDER_HPP_
