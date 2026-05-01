# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xplr_aoa3_msgs:msg/AoaMeasurement.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AoaMeasurement(type):
    """Metaclass of message 'AoaMeasurement'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('xplr_aoa3_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'xplr_aoa3_msgs.msg.AoaMeasurement')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__aoa_measurement
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__aoa_measurement
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__aoa_measurement
            cls._TYPE_SUPPORT = module.type_support_msg__msg__aoa_measurement
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__aoa_measurement

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AoaMeasurement(metaclass=Metaclass_AoaMeasurement):
    """Message class 'AoaMeasurement'."""

    __slots__ = [
        '_header',
        '_tag_id',
        '_anchor_id',
        '_azimuth',
        '_elevation',
        '_rssi',
        '_channel',
        '_timestamp',
        '_seq',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'tag_id': 'string',
        'anchor_id': 'string',
        'azimuth': 'int32',
        'elevation': 'int32',
        'rssi': 'int32',
        'channel': 'int32',
        'timestamp': 'uint32',
        'seq': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.tag_id = kwargs.get('tag_id', str())
        self.anchor_id = kwargs.get('anchor_id', str())
        self.azimuth = kwargs.get('azimuth', int())
        self.elevation = kwargs.get('elevation', int())
        self.rssi = kwargs.get('rssi', int())
        self.channel = kwargs.get('channel', int())
        self.timestamp = kwargs.get('timestamp', int())
        self.seq = kwargs.get('seq', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.tag_id != other.tag_id:
            return False
        if self.anchor_id != other.anchor_id:
            return False
        if self.azimuth != other.azimuth:
            return False
        if self.elevation != other.elevation:
            return False
        if self.rssi != other.rssi:
            return False
        if self.channel != other.channel:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.seq != other.seq:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def tag_id(self):
        """Message field 'tag_id'."""
        return self._tag_id

    @tag_id.setter
    def tag_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'tag_id' field must be of type 'str'"
        self._tag_id = value

    @builtins.property
    def anchor_id(self):
        """Message field 'anchor_id'."""
        return self._anchor_id

    @anchor_id.setter
    def anchor_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'anchor_id' field must be of type 'str'"
        self._anchor_id = value

    @builtins.property
    def azimuth(self):
        """Message field 'azimuth'."""
        return self._azimuth

    @azimuth.setter
    def azimuth(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'azimuth' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'azimuth' field must be an integer in [-2147483648, 2147483647]"
        self._azimuth = value

    @builtins.property
    def elevation(self):
        """Message field 'elevation'."""
        return self._elevation

    @elevation.setter
    def elevation(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'elevation' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'elevation' field must be an integer in [-2147483648, 2147483647]"
        self._elevation = value

    @builtins.property
    def rssi(self):
        """Message field 'rssi'."""
        return self._rssi

    @rssi.setter
    def rssi(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rssi' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rssi' field must be an integer in [-2147483648, 2147483647]"
        self._rssi = value

    @builtins.property
    def channel(self):
        """Message field 'channel'."""
        return self._channel

    @channel.setter
    def channel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'channel' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'channel' field must be an integer in [-2147483648, 2147483647]"
        self._channel = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'timestamp' field must be an unsigned integer in [0, 4294967295]"
        self._timestamp = value

    @builtins.property
    def seq(self):
        """Message field 'seq'."""
        return self._seq

    @seq.setter
    def seq(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'seq' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'seq' field must be an unsigned integer in [0, 4294967295]"
        self._seq = value
