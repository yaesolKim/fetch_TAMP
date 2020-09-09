; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-msg)


;//! \htmlinclude StatusUpdate.msg.html

(cl:defclass <StatusUpdate> (roslisp-msg-protocol:ros-message)
  ((last_update_client
    :reader last_update_client
    :initarg :last_update_client
    :type cl:string
    :initform "")
   (last_update_time
    :reader last_update_time
    :initarg :last_update_time
    :type cl:real
    :initform 0))
)

(cl:defclass StatusUpdate (<StatusUpdate>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StatusUpdate>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StatusUpdate)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-msg:<StatusUpdate> is deprecated: use rosplan_knowledge_msgs-msg:StatusUpdate instead.")))

(cl:ensure-generic-function 'last_update_client-val :lambda-list '(m))
(cl:defmethod last_update_client-val ((m <StatusUpdate>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-msg:last_update_client-val is deprecated.  Use rosplan_knowledge_msgs-msg:last_update_client instead.")
  (last_update_client m))

(cl:ensure-generic-function 'last_update_time-val :lambda-list '(m))
(cl:defmethod last_update_time-val ((m <StatusUpdate>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-msg:last_update_time-val is deprecated.  Use rosplan_knowledge_msgs-msg:last_update_time instead.")
  (last_update_time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StatusUpdate>) ostream)
  "Serializes a message object of type '<StatusUpdate>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'last_update_client))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'last_update_client))
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'last_update_time)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'last_update_time) (cl:floor (cl:slot-value msg 'last_update_time)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StatusUpdate>) istream)
  "Deserializes a message object of type '<StatusUpdate>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'last_update_client) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'last_update_client) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'last_update_time) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StatusUpdate>)))
  "Returns string type for a message object of type '<StatusUpdate>"
  "rosplan_knowledge_msgs/StatusUpdate")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StatusUpdate)))
  "Returns string type for a message object of type 'StatusUpdate"
  "rosplan_knowledge_msgs/StatusUpdate")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StatusUpdate>)))
  "Returns md5sum for a message object of type '<StatusUpdate>"
  "184cadf1052e240c262af1a764339990")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StatusUpdate)))
  "Returns md5sum for a message object of type 'StatusUpdate"
  "184cadf1052e240c262af1a764339990")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StatusUpdate>)))
  "Returns full string definition for message of type '<StatusUpdate>"
  (cl:format cl:nil "# A message used to publish a status notification from the Knowledge Base~%# This status notifies that the KB has been updated.~%~%string last_update_client~%time last_update_time~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StatusUpdate)))
  "Returns full string definition for message of type 'StatusUpdate"
  (cl:format cl:nil "# A message used to publish a status notification from the Knowledge Base~%# This status notifies that the KB has been updated.~%~%string last_update_client~%time last_update_time~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StatusUpdate>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'last_update_client))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StatusUpdate>))
  "Converts a ROS message object to a list"
  (cl:list 'StatusUpdate
    (cl:cons ':last_update_client (last_update_client msg))
    (cl:cons ':last_update_time (last_update_time msg))
))
