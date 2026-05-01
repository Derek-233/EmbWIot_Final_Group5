// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
// generated code does not contain a copyright notice

#ifndef XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__FUNCTIONS_H_
#define XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xplr_aoa3_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "xplr_aoa3_msgs/msg/detail/aoa_measurement__struct.h"

/// Initialize msg/AoaMeasurement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xplr_aoa3_msgs__msg__AoaMeasurement
 * )) before or use
 * xplr_aoa3_msgs__msg__AoaMeasurement__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
bool
xplr_aoa3_msgs__msg__AoaMeasurement__init(xplr_aoa3_msgs__msg__AoaMeasurement * msg);

/// Finalize msg/AoaMeasurement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
void
xplr_aoa3_msgs__msg__AoaMeasurement__fini(xplr_aoa3_msgs__msg__AoaMeasurement * msg);

/// Create msg/AoaMeasurement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xplr_aoa3_msgs__msg__AoaMeasurement__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
xplr_aoa3_msgs__msg__AoaMeasurement *
xplr_aoa3_msgs__msg__AoaMeasurement__create();

/// Destroy msg/AoaMeasurement message.
/**
 * It calls
 * xplr_aoa3_msgs__msg__AoaMeasurement__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
void
xplr_aoa3_msgs__msg__AoaMeasurement__destroy(xplr_aoa3_msgs__msg__AoaMeasurement * msg);

/// Check for msg/AoaMeasurement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
bool
xplr_aoa3_msgs__msg__AoaMeasurement__are_equal(const xplr_aoa3_msgs__msg__AoaMeasurement * lhs, const xplr_aoa3_msgs__msg__AoaMeasurement * rhs);

/// Copy a msg/AoaMeasurement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
bool
xplr_aoa3_msgs__msg__AoaMeasurement__copy(
  const xplr_aoa3_msgs__msg__AoaMeasurement * input,
  xplr_aoa3_msgs__msg__AoaMeasurement * output);

/// Initialize array of msg/AoaMeasurement messages.
/**
 * It allocates the memory for the number of elements and calls
 * xplr_aoa3_msgs__msg__AoaMeasurement__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
bool
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__init(xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * array, size_t size);

/// Finalize array of msg/AoaMeasurement messages.
/**
 * It calls
 * xplr_aoa3_msgs__msg__AoaMeasurement__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
void
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__fini(xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * array);

/// Create array of msg/AoaMeasurement messages.
/**
 * It allocates the memory for the array and calls
 * xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence *
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__create(size_t size);

/// Destroy array of msg/AoaMeasurement messages.
/**
 * It calls
 * xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
void
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__destroy(xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * array);

/// Check for msg/AoaMeasurement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
bool
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__are_equal(const xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * lhs, const xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * rhs);

/// Copy an array of msg/AoaMeasurement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_xplr_aoa3_msgs
bool
xplr_aoa3_msgs__msg__AoaMeasurement__Sequence__copy(
  const xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * input,
  xplr_aoa3_msgs__msg__AoaMeasurement__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XPLR_AOA3_MSGS__MSG__DETAIL__AOA_MEASUREMENT__FUNCTIONS_H_
