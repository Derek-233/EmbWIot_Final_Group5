// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
// generated code does not contain a copyright notice

#ifndef XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__STRUCT_H_
#define XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'tag_id'
// Member 'anchor_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AoaMeasurement in the package xplr_aoa3_msgs.
typedef struct xplr_aoa3_msgs__msg__AoaMeasurement
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String tag_id;
  rosidl_runtime_c__String anchor_id;
  int32_t azimuth;
  int32_t elevation;
  int32_t rssi;
  int32_t channel;
  uint32_t timestamp;
  uint32_t seq;
} xplr_aoa3_msgs__msg__AoaMeasurement;

// Struct for a sequence of xplr_aoa3_msgs__msg__AoaMeasurement.
typedef struct xplr_aoa3_msgs__msg__AoaMeasurement__Sequence
{
  xplr_aoa3_msgs__msg__AoaMeasurement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xplr_aoa3_msgs__msg__AoaMeasurement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__STRUCT_H_
