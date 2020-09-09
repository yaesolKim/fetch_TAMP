# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from occupancy_grid_utils/OverlayClouds.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy
import geometry_msgs.msg
import nav_msgs.msg
import std_msgs.msg

class OverlayClouds(genpy.Message):
  _md5sum = "a1dfac662600ca9b91b434a76485a5d9"
  _type = "occupancy_grid_utils/OverlayClouds"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """nav_msgs/OccupancyGrid grid
string frame_id
float32 occupancy_threshold
float32 max_distance
float32 min_pass_through
int32[] hit_counts
int32[] pass_through_counts
================================================================================
MSG: nav_msgs/OccupancyGrid
# This represents a 2-D grid map, in which each cell represents the probability of
# occupancy.

Header header 

#MetaData for the map
MapMetaData info

# The map data, in row-major order, starting with (0,0).  Occupancy
# probabilities are in the range [0,100].  Unknown is -1.
int8[] data

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: nav_msgs/MapMetaData
# This hold basic information about the characterists of the OccupancyGrid

# The time at which the map was loaded
time map_load_time
# The map resolution [m/cell]
float32 resolution
# Map width [cells]
uint32 width
# Map height [cells]
uint32 height
# The origin of the map [m, m, rad].  This is the real-world pose of the
# cell (0,0) in the map.
geometry_msgs/Pose origin
================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
"""
  __slots__ = ['grid','frame_id','occupancy_threshold','max_distance','min_pass_through','hit_counts','pass_through_counts']
  _slot_types = ['nav_msgs/OccupancyGrid','string','float32','float32','float32','int32[]','int32[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       grid,frame_id,occupancy_threshold,max_distance,min_pass_through,hit_counts,pass_through_counts

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(OverlayClouds, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.grid is None:
        self.grid = nav_msgs.msg.OccupancyGrid()
      if self.frame_id is None:
        self.frame_id = ''
      if self.occupancy_threshold is None:
        self.occupancy_threshold = 0.
      if self.max_distance is None:
        self.max_distance = 0.
      if self.min_pass_through is None:
        self.min_pass_through = 0.
      if self.hit_counts is None:
        self.hit_counts = []
      if self.pass_through_counts is None:
        self.pass_through_counts = []
    else:
      self.grid = nav_msgs.msg.OccupancyGrid()
      self.frame_id = ''
      self.occupancy_threshold = 0.
      self.max_distance = 0.
      self.min_pass_through = 0.
      self.hit_counts = []
      self.pass_through_counts = []

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
      buff.write(_get_struct_3I().pack(_x.grid.header.seq, _x.grid.header.stamp.secs, _x.grid.header.stamp.nsecs))
      _x = self.grid.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2If2I7d().pack(_x.grid.info.map_load_time.secs, _x.grid.info.map_load_time.nsecs, _x.grid.info.resolution, _x.grid.info.width, _x.grid.info.height, _x.grid.info.origin.position.x, _x.grid.info.origin.position.y, _x.grid.info.origin.position.z, _x.grid.info.origin.orientation.x, _x.grid.info.origin.orientation.y, _x.grid.info.origin.orientation.z, _x.grid.info.origin.orientation.w))
      length = len(self.grid.data)
      buff.write(_struct_I.pack(length))
      pattern = '<%sb'%length
      buff.write(struct.pack(pattern, *self.grid.data))
      _x = self.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3f().pack(_x.occupancy_threshold, _x.max_distance, _x.min_pass_through))
      length = len(self.hit_counts)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(struct.pack(pattern, *self.hit_counts))
      length = len(self.pass_through_counts)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(struct.pack(pattern, *self.pass_through_counts))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.grid is None:
        self.grid = nav_msgs.msg.OccupancyGrid()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.grid.header.seq, _x.grid.header.stamp.secs, _x.grid.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.grid.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.grid.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 76
      (_x.grid.info.map_load_time.secs, _x.grid.info.map_load_time.nsecs, _x.grid.info.resolution, _x.grid.info.width, _x.grid.info.height, _x.grid.info.origin.position.x, _x.grid.info.origin.position.y, _x.grid.info.origin.position.z, _x.grid.info.origin.orientation.x, _x.grid.info.origin.orientation.y, _x.grid.info.origin.orientation.z, _x.grid.info.origin.orientation.w,) = _get_struct_2If2I7d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sb'%length
      start = end
      end += struct.calcsize(pattern)
      self.grid.data = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.frame_id = str[start:end].decode('utf-8')
      else:
        self.frame_id = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.occupancy_threshold, _x.max_distance, _x.min_pass_through,) = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.hit_counts = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.pass_through_counts = struct.unpack(pattern, str[start:end])
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
      buff.write(_get_struct_3I().pack(_x.grid.header.seq, _x.grid.header.stamp.secs, _x.grid.header.stamp.nsecs))
      _x = self.grid.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_2If2I7d().pack(_x.grid.info.map_load_time.secs, _x.grid.info.map_load_time.nsecs, _x.grid.info.resolution, _x.grid.info.width, _x.grid.info.height, _x.grid.info.origin.position.x, _x.grid.info.origin.position.y, _x.grid.info.origin.position.z, _x.grid.info.origin.orientation.x, _x.grid.info.origin.orientation.y, _x.grid.info.origin.orientation.z, _x.grid.info.origin.orientation.w))
      length = len(self.grid.data)
      buff.write(_struct_I.pack(length))
      pattern = '<%sb'%length
      buff.write(self.grid.data.tostring())
      _x = self.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_3f().pack(_x.occupancy_threshold, _x.max_distance, _x.min_pass_through))
      length = len(self.hit_counts)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(self.hit_counts.tostring())
      length = len(self.pass_through_counts)
      buff.write(_struct_I.pack(length))
      pattern = '<%si'%length
      buff.write(self.pass_through_counts.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.grid is None:
        self.grid = nav_msgs.msg.OccupancyGrid()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.grid.header.seq, _x.grid.header.stamp.secs, _x.grid.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.grid.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.grid.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 76
      (_x.grid.info.map_load_time.secs, _x.grid.info.map_load_time.nsecs, _x.grid.info.resolution, _x.grid.info.width, _x.grid.info.height, _x.grid.info.origin.position.x, _x.grid.info.origin.position.y, _x.grid.info.origin.position.z, _x.grid.info.origin.orientation.x, _x.grid.info.origin.orientation.y, _x.grid.info.origin.orientation.z, _x.grid.info.origin.orientation.w,) = _get_struct_2If2I7d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sb'%length
      start = end
      end += struct.calcsize(pattern)
      self.grid.data = numpy.frombuffer(str[start:end], dtype=numpy.int8, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.frame_id = str[start:end].decode('utf-8')
      else:
        self.frame_id = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.occupancy_threshold, _x.max_distance, _x.min_pass_through,) = _get_struct_3f().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.hit_counts = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%si'%length
      start = end
      end += struct.calcsize(pattern)
      self.pass_through_counts = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=length)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2If2I7d = None
def _get_struct_2If2I7d():
    global _struct_2If2I7d
    if _struct_2If2I7d is None:
        _struct_2If2I7d = struct.Struct("<2If2I7d")
    return _struct_2If2I7d
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_3f = None
def _get_struct_3f():
    global _struct_3f
    if _struct_3f is None:
        _struct_3f = struct.Struct("<3f")
    return _struct_3f
