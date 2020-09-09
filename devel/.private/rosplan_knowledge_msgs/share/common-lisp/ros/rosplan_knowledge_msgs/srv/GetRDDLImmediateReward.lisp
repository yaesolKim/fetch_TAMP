; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-srv)


;//! \htmlinclude GetRDDLImmediateReward-request.msg.html

(cl:defclass <GetRDDLImmediateReward-request> (roslisp-msg-protocol:ros-message)
  ((action
    :reader action
    :initarg :action
    :type (cl:vector std_msgs-msg:String)
   :initform (cl:make-array 0 :element-type 'std_msgs-msg:String :initial-element (cl:make-instance 'std_msgs-msg:String))))
)

(cl:defclass GetRDDLImmediateReward-request (<GetRDDLImmediateReward-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRDDLImmediateReward-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRDDLImmediateReward-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetRDDLImmediateReward-request> is deprecated: use rosplan_knowledge_msgs-srv:GetRDDLImmediateReward-request instead.")))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <GetRDDLImmediateReward-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:action-val is deprecated.  Use rosplan_knowledge_msgs-srv:action instead.")
  (action m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRDDLImmediateReward-request>) ostream)
  "Serializes a message object of type '<GetRDDLImmediateReward-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'action))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'action))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRDDLImmediateReward-request>) istream)
  "Deserializes a message object of type '<GetRDDLImmediateReward-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'action) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'action)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:String))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRDDLImmediateReward-request>)))
  "Returns string type for a service object of type '<GetRDDLImmediateReward-request>"
  "rosplan_knowledge_msgs/GetRDDLImmediateRewardRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLImmediateReward-request)))
  "Returns string type for a service object of type 'GetRDDLImmediateReward-request"
  "rosplan_knowledge_msgs/GetRDDLImmediateRewardRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRDDLImmediateReward-request>)))
  "Returns md5sum for a message object of type '<GetRDDLImmediateReward-request>"
  "837ccfec14d9d69a332bf7294d27c502")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRDDLImmediateReward-request)))
  "Returns md5sum for a message object of type 'GetRDDLImmediateReward-request"
  "837ccfec14d9d69a332bf7294d27c502")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRDDLImmediateReward-request>)))
  "Returns full string definition for message of type '<GetRDDLImmediateReward-request>"
  (cl:format cl:nil "std_msgs/String[] action # Instantiated actions in the last timestep (i.e. goto_Waypoint(kenny, printer)~%~%================================================================================~%MSG: std_msgs/String~%string data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRDDLImmediateReward-request)))
  "Returns full string definition for message of type 'GetRDDLImmediateReward-request"
  (cl:format cl:nil "std_msgs/String[] action # Instantiated actions in the last timestep (i.e. goto_Waypoint(kenny, printer)~%~%================================================================================~%MSG: std_msgs/String~%string data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRDDLImmediateReward-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'action) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRDDLImmediateReward-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRDDLImmediateReward-request
    (cl:cons ':action (action msg))
))
;//! \htmlinclude GetRDDLImmediateReward-response.msg.html

(cl:defclass <GetRDDLImmediateReward-response> (roslisp-msg-protocol:ros-message)
  ((reward
    :reader reward
    :initarg :reward
    :type cl:float
    :initform 0.0))
)

(cl:defclass GetRDDLImmediateReward-response (<GetRDDLImmediateReward-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRDDLImmediateReward-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRDDLImmediateReward-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetRDDLImmediateReward-response> is deprecated: use rosplan_knowledge_msgs-srv:GetRDDLImmediateReward-response instead.")))

(cl:ensure-generic-function 'reward-val :lambda-list '(m))
(cl:defmethod reward-val ((m <GetRDDLImmediateReward-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:reward-val is deprecated.  Use rosplan_knowledge_msgs-srv:reward instead.")
  (reward m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRDDLImmediateReward-response>) ostream)
  "Serializes a message object of type '<GetRDDLImmediateReward-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'reward))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRDDLImmediateReward-response>) istream)
  "Deserializes a message object of type '<GetRDDLImmediateReward-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'reward) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRDDLImmediateReward-response>)))
  "Returns string type for a service object of type '<GetRDDLImmediateReward-response>"
  "rosplan_knowledge_msgs/GetRDDLImmediateRewardResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLImmediateReward-response)))
  "Returns string type for a service object of type 'GetRDDLImmediateReward-response"
  "rosplan_knowledge_msgs/GetRDDLImmediateRewardResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRDDLImmediateReward-response>)))
  "Returns md5sum for a message object of type '<GetRDDLImmediateReward-response>"
  "837ccfec14d9d69a332bf7294d27c502")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRDDLImmediateReward-response)))
  "Returns md5sum for a message object of type 'GetRDDLImmediateReward-response"
  "837ccfec14d9d69a332bf7294d27c502")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRDDLImmediateReward-response>)))
  "Returns full string definition for message of type '<GetRDDLImmediateReward-response>"
  (cl:format cl:nil "float64 reward~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRDDLImmediateReward-response)))
  "Returns full string definition for message of type 'GetRDDLImmediateReward-response"
  (cl:format cl:nil "float64 reward~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRDDLImmediateReward-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRDDLImmediateReward-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRDDLImmediateReward-response
    (cl:cons ':reward (reward msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetRDDLImmediateReward)))
  'GetRDDLImmediateReward-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetRDDLImmediateReward)))
  'GetRDDLImmediateReward-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLImmediateReward)))
  "Returns string type for a service object of type '<GetRDDLImmediateReward>"
  "rosplan_knowledge_msgs/GetRDDLImmediateReward")