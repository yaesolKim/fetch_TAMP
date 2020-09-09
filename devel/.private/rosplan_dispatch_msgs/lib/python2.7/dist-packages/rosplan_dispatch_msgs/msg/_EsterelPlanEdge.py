# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from rosplan_dispatch_msgs/EsterelPlanEdge.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class EsterelPlanEdge(genpy.Message):
  _md5sum = "1d2c55d97ec5947580a42b9057d254ce"
  _type = "rosplan_dispatch_msgs/EsterelPlanEdge"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """#EsterelPlanEdge message

byte CONDITION_EDGE   = 0
byte START_END_ACTION_EDGE = 1
byte INTERFERENCE_EDGE = 2

byte edge_type
int32 edge_id
string edge_name
int32 signal_type
int32[] source_ids
int32[] sink_ids
float64 duration_lower_bound
float64 duration_upper_bound
"""
  # Pseudo-constants
  CONDITION_EDGE = 0
  START_END_ACTION_EDGE = 1
  INTERFERENCE_EDGE = 2

  __slots__ = ['edge_type','edge_id','edge_name','signal_type','source_ids','sink_ids','duration_lower_bound','duration_upper_bound']
  _slot_types = ['byte','int32','string','int32','int32[]','int32[]','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       edge_type,edge_id,edge_name,signal_type,source_ids,sink_ids,duration_lower_bound,duration_upper_bound

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(EsterelPlanEdge, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.edge_type is None:
        self.edge_type = 0
      if self.edge_id is None:
        self.edge_id = 0
      if self.edge_name is None:
        self.edge_name = ''
      if self.signal_type is None:
        self.signal_type = 0
      if self.source_ids is None:
        self.source_ids = []
      if self.sink_ids is None:
        self.sink_ids = []
      if self.duration_lower_bound is None:
        self.duration_lower_bound = 0.
      if self.duration_upper_bound is None:
        self.duration_upper_bound = 0.
    else:
      self.edge_type = 0
      self.edge_id = 0
      self.edge_name = ''
      self.signal_type = 0
      self.source_ids = []
      self.sink_ids = []
      self.duration_lower_bound = 0.
      self.duration_upper_bound = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_bi().pack(_x.edge_type, _x.edge_id))
      _x = self.edge_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.signal_type
      buff.write(_get_struct_i().pack(_x))
      length = len(self.source_ids)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(struct.pack(pattern, *self.source_ids))
      length = len(self.sink_ids)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(struct.pack(pattern, *self.sink_ids))
      _x = self
      buff.write(_get_struct_2d().pack(_x.duration_lower_bound, _x.duration_upper_bound))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 5
      (_x.edge_type, _x.edge_id,) = _get_struct_bi().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.edge_name = str[start:end].decode('utf-8')
      else:
        self.edge_name = str[start:end]
      start = end
      end += 4
      (self.signal_type,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.source_ids = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.sink_ids = struct.unpack(pattern, str[start:end])
      _x = self
      start = end
      end += 16
      (_x.duration_lower_bound, _x.duration_upper_bound,) = _get_struct_2d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_bi().pack(_x.edge_type, _x.edge_id))
      _x = self.edge_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.signal_type
      buff.write(_get_struct_i().pack(_x))
      length = len(self.source_ids)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(self.source_ids.tostring())
      length = len(self.sink_ids)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(self.sink_ids.tostring())
      _x = self
      buff.write(_get_struct_2d().pack(_x.duration_lower_bound, _x.duration_upper_bound))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 5
      (_x.edge_type, _x.edge_id,) = _get_struct_bi().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.edge_name = str[start:end].decode('utf-8')
      else:
        self.edge_name = str[start:end]
      start = end
      end += 4
      (self.signal_type,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.source_ids = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.sink_ids = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=length)
      _x = self
      start = end
      end += 16
      (_x.duration_lower_bound, _x.duration_upper_bound,) = _get_struct_2d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2d = None
def _get_struct_2d():
    global _struct_2d
    if _struct_2d is None:
        _struct_2d = struct.Struct("<2d")
    return _struct_2d
_struct_bi = None
def _get_struct_bi():
    global _struct_bi
    if _struct_bi is None:
        _struct_bi = struct.Struct("<bi")
    return _struct_bi
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
