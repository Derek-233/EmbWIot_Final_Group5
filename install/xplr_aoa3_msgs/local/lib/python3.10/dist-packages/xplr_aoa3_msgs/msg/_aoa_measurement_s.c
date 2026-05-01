// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "xplr_aoa3_msgs/msg/detail/aoa_measurement__struct.h"
#include "xplr_aoa3_msgs/msg/detail/aoa_measurement__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool xplr_aoa3_msgs__msg__aoa_measurement__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("xplr_aoa3_msgs.msg._aoa_measurement.AoaMeasurement", full_classname_dest, 50) == 0);
  }
  xplr_aoa3_msgs__msg__AoaMeasurement * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // tag_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "tag_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->tag_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // anchor_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "anchor_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->anchor_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // azimuth
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->azimuth = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // elevation
    PyObject * field = PyObject_GetAttrString(_pymsg, "elevation");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->elevation = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // rssi
    PyObject * field = PyObject_GetAttrString(_pymsg, "rssi");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rssi = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // channel
    PyObject * field = PyObject_GetAttrString(_pymsg, "channel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->channel = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // seq
    PyObject * field = PyObject_GetAttrString(_pymsg, "seq");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->seq = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * xplr_aoa3_msgs__msg__aoa_measurement__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AoaMeasurement */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("xplr_aoa3_msgs.msg._aoa_measurement");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AoaMeasurement");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  xplr_aoa3_msgs__msg__AoaMeasurement * ros_message = (xplr_aoa3_msgs__msg__AoaMeasurement *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tag_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->tag_id.data,
      strlen(ros_message->tag_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tag_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // anchor_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->anchor_id.data,
      strlen(ros_message->anchor_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "anchor_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // azimuth
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->azimuth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azimuth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // elevation
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->elevation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "elevation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rssi
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->rssi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rssi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // channel
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->channel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "channel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->timestamp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // seq
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->seq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "seq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
