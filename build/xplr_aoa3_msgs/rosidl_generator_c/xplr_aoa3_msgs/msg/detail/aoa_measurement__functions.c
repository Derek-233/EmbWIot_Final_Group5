// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
// generated code does not contain a copyright notice
#include "xplr_aoa3_msgs/msg/detail/aoa_measurement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `tag_id`
// Member `anchor_id`
#include "rosidl_runtime_c/string_functions.h"

bool
xplr_aoa3_msgs__msg__AoaMeasurement__init(xplr_aoa3_msgs__msg__AoaMeasurement * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    xplr_aoa3_msgs__msg__AoaMeasurement__fini(msg);
    return false;
  }
  // tag_id
  if (!rosidl_runtime_c__String__init(&msg->tag_id)) {
    xplr_aoa3_msgs__msg__AoaMeasurement__fini(msg);
    return false;
  }
  // anchor_id
  if (!rosidl_runtime_c__String__init(&msg->anchor_id)) {
    xplr_aoa3_msgs__msg__AoaMeasurement__fini(msg);
    return false;
  }
  // azimuth
  // elevation
  // rssi
  // channel
  // timestamp
  // seq
  return true;
}

void
xplr_aoa3_msgs__msg__AoaMeasurement__fini(xplr_aoa3_msgs__msg__AoaMeasurement * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // tag_id
  rosidl_runtime_c__String__fini(&msg->tag_id);
  // anchor_id
  rosidl_runtime_c__String__fini(&msg->anchor_id);
  // azimuth
  // elevation
  // rssi
  // channel
  // timestamp
  // seq
}

bool
xplr_aoa3_msgs__msg__AoaMeasurement__are_equal(const xplr_aoa3_msgs__msg__AoaMeasurement * lhs, const xplr_aoa3_msgs__msg__AoaMeasurement * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // tag_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tag_id), &(rhs->tag_id)))
  {
    return false;
  }
  // anchor_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->anchor_id), &(rhs->anchor_id)))
  {
    return false;
  }
  // azimuth
  if (lhs->azimuth != rhs->azimuth) {
    return false;
  }
  // elevation
  if (lhs->elevation != rhs->elevation) {
    return false;
  }
  // rssi
  if (lhs->rssi != rhs->rssi) {
    return false;
  }
  // channel
  if (lhs->channel != rhs->channel) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // seq
  if (lhs->seq != rhs->seq) {
    return false;
  }
  return true;
}

bool
xplr_aoa3_msgs__msg__AoaMeasurement__copy(
  const xplr_aoa3_msgs__msg__AoaMeasurement * input,
  xplr_aoa3_msgs__msg__AoaMeasurement * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // tag_id
  if (!rosidl_runtime_c__String__copy(
      &(input->tag_id), &(output->tag_id)))
  {
    return false;
  }
  // anchor_id
  if (!rosidl_runtime_c__String__copy(
      &(input->anchor_id), &(output->anchor_id)))
  {
    return false;
  }
  // azimuth
  output->azimuth = input->azimuth;
  // elevation
  output->elevation = input->elevation;
  // rssi
  output->rssi = input->rssi;
  // channel
  output->channel = input->channel;
  // timestamp
  output->timestamp = input->timestamp;
  // seq
  output->seq = input->seq;
  return true;
}

xplr_aoa3_msgs__msg__AoaMeasurement *
xplr_aoa3_msgs__msg__AoaMeasurement__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xplr_aoa3_msgs__msg__AoaMeasurement * msg = (xplr_aoa3_msgs__msg__AoaMeasurement *)allocator.allocate(sizeof(xplr_aoa3_msgs__msg__AoaMeasurement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xplr_aoa3_msgs__msg__AoaMeasurement));
  bool success = xplr_aoa3_msgs__msg__AoaMeasurement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xplr_aoa3_msgs__msg__AoaMeasurement__destroy(xplr_aoa3_msgs__msg__AoaMeasurement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xplr_aoa3_msgs__msg__AoaMeasurement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__init(xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xplr_aoa3_msgs__msg__AoaMeasurement * data = NULL;

  if (size) {
    data = (xplr_aoa3_msgs__msg__AoaMeasurement *)allocator.zero_allocate(size, sizeof(xplr_aoa3_msgs__msg__AoaMeasurement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xplr_aoa3_msgs__msg__AoaMeasurement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xplr_aoa3_msgs__msg__AoaMeasurement__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__fini(xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      xplr_aoa3_msgs__msg__AoaMeasurement__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

xplr_aoa3_msgs__msg__AoaMeasurement__Sequence *
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * array = (xplr_aoa3_msgs__msg__AoaMeasurement__Sequence *)allocator.allocate(sizeof(xplr_aoa3_msgs__msg__AoaMeasurement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__destroy(xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__are_equal(const xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * lhs, const xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xplr_aoa3_msgs__msg__AoaMeasurement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__copy(
  const xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * input,
  xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xplr_aoa3_msgs__msg__AoaMeasurement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xplr_aoa3_msgs__msg__AoaMeasurement * data =
      (xplr_aoa3_msgs__msg__AoaMeasurement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xplr_aoa3_msgs__msg__AoaMeasurement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xplr_aoa3_msgs__msg__AoaMeasurement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xplr_aoa3_msgs__msg__AoaMeasurement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
