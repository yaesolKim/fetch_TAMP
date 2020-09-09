; Auto-generated. Do not edit!


(cl:in-package rosplan_interface_mapping-srv)


;//! \htmlinclude AddWaypoint-request.msg.html

(cl:defclass <AddWaypoint-request> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:string
    :initform "")
   (waypoint
    :reader waypoint
    :initarg :waypoint
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped))
   (connecting_distance
    :reader connecting_distance
    :initarg :connecting_distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass AddWaypoint-request (<AddWaypoint-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AddWaypoint-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AddWaypoint-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_interface_mapping-srv:<AddWaypoint-request> is deprecated: use rosplan_interface_mapping-srv:AddWaypoint-request instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <AddWaypoint-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_interface_mapping-srv:id-val is deprecated.  Use rosplan_interface_mapping-srv:id instead.")
  (id m))

(cl:ensure-generic-function 'waypoint-val :lambda-list '(m))
(cl:defmethod waypoint-val ((m <AddWaypoint-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_interface_mapping-srv:waypoint-val is deprecated.  Use rosplan_interface_mapping-srv:waypoint instead.")
  (waypoint m))

(cl:ensure-generic-function 'connecting_distance-val :lambda-list '(m))
(cl:defmethod connecting_distance-val ((m <AddWaypoint-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_interface_mapping-srv:connecting_distance-val is deprecated.  Use rosplan_interface_mapping-srv:connecting_distance instead.")
  (connecting_distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AddWaypoint-request>) ostream)
  "Serializes a message object of type '<AddWaypoint-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'id))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'id))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'waypoint) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'connecting_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AddWaypoint-request>) istream)
  "Deserializes a message object of type '<AddWaypoint-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'id) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'waypoint) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'connecting_distance) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AddWaypoint-request>)))
  "Returns string type for a service object of type '<AddWaypoint-request>"
  "rosplan_interface_mapping/AddWaypointRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddWaypoint-request)))
  "Returns string type for a service object of type 'AddWaypoint-request"
  "rosplan_interface_mapping/AddWaypointRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AddWaypoint-request>)))
  "Returns md5sum for a message object of type '<AddWaypoint-request>"
  "bd9af2cdf47b3141d3559a7b37e0fa5a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AddWaypoint-request)))
  "Returns md5sum for a message object of type 'AddWaypoint-request"
  "bd9af2cdf47b3141d3559a7b37e0fa5a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AddWaypoint-request>)))
  "Returns full string definition for message of type '<AddWaypoint-request>"
  (cl:format cl:nil "string id~%geometry_msgs/PoseStamped waypoint~%float32 connecting_distance~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AddWaypoint-request)))
  "Returns full string definition for message of type 'AddWaypoint-request"
  (cl:format cl:nil "string id~%geometry_msgs/PoseStamped waypoint~%float32 connecting_distance~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AddWaypoint-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'waypoint))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AddWaypoint-request>))
  "Converts a ROS message object to a list"
  (cl:list 'AddWaypoint-request
    (cl:cons ':id (id msg))
    (cl:cons ':waypoint (waypoint msg))
    (cl:cons ':connecting_distance (connecting_distance msg))
))
;//! \htmlinclude AddWaypoint-response.msg.html

(cl:defclass <AddWaypoint-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass AddWaypoint-response (<AddWaypoint-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AddWaypoint-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AddWaypoint-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_interface_mapping-srv:<AddWaypoint-response> is deprecated: use rosplan_interface_mapping-srv:AddWaypoint-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AddWaypoint-response>) ostream)
  "Serializes a message object of type '<AddWaypoint-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AddWaypoint-response>) istream)
  "Deserializes a message object of type '<AddWaypoint-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AddWaypoint-response>)))
  "Returns string type for a service object of type '<AddWaypoint-response>"
  "rosplan_interface_mapping/AddWaypointResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddWaypoint-response)))
  "Returns string type for a service object of type 'AddWaypoint-response"
  "rosplan_interface_mapping/AddWaypointResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AddWaypoint-response>)))
  "Returns md5sum for a message object of type '<AddWaypoint-response>"
  "bd9af2cdf47b3141d3559a7b37e0fa5a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AddWaypoint-response)))
  "Returns md5sum for a message object of type 'AddWaypoint-response"
  "bd9af2cdf47b3141d3559a7b37e0fa5a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AddWaypoint-response>)))
  "Returns full string definition for message of type '<AddWaypoint-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AddWaypoint-response)))
  "Returns full string definition for message of type 'AddWaypoint-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AddWaypoint-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AddWaypoint-response>))
  "Converts a ROS message object to a list"
  (cl:list 'AddWaypoint-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'AddWaypoint)))
  'AddWaypoint-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'AddWaypoint)))
  'AddWaypoint-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddWaypoint)))
  "Returns string type for a service object of type '<AddWaypoint>"
  "rosplan_interface_mapping/AddWaypoint")