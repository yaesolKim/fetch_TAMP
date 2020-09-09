; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-srv)


;//! \htmlinclude GetRDDLParams-request.msg.html

(cl:defclass <GetRDDLParams-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass GetRDDLParams-request (<GetRDDLParams-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRDDLParams-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRDDLParams-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetRDDLParams-request> is deprecated: use rosplan_knowledge_msgs-srv:GetRDDLParams-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRDDLParams-request>) ostream)
  "Serializes a message object of type '<GetRDDLParams-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRDDLParams-request>) istream)
  "Deserializes a message object of type '<GetRDDLParams-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRDDLParams-request>)))
  "Returns string type for a service object of type '<GetRDDLParams-request>"
  "rosplan_knowledge_msgs/GetRDDLParamsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLParams-request)))
  "Returns string type for a service object of type 'GetRDDLParams-request"
  "rosplan_knowledge_msgs/GetRDDLParamsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRDDLParams-request>)))
  "Returns md5sum for a message object of type '<GetRDDLParams-request>"
  "0cf0ef8b4c4b342e8f951535dfe54dba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRDDLParams-request)))
  "Returns md5sum for a message object of type 'GetRDDLParams-request"
  "0cf0ef8b4c4b342e8f951535dfe54dba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRDDLParams-request>)))
  "Returns full string definition for message of type '<GetRDDLParams-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRDDLParams-request)))
  "Returns full string definition for message of type 'GetRDDLParams-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRDDLParams-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRDDLParams-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRDDLParams-request
))
;//! \htmlinclude GetRDDLParams-response.msg.html

(cl:defclass <GetRDDLParams-response> (roslisp-msg-protocol:ros-message)
  ((horizon
    :reader horizon
    :initarg :horizon
    :type cl:integer
    :initform 0)
   (discount_factor
    :reader discount_factor
    :initarg :discount_factor
    :type cl:float
    :initform 0.0)
   (max_nondef_actions
    :reader max_nondef_actions
    :initarg :max_nondef_actions
    :type cl:integer
    :initform 0))
)

(cl:defclass GetRDDLParams-response (<GetRDDLParams-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRDDLParams-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRDDLParams-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetRDDLParams-response> is deprecated: use rosplan_knowledge_msgs-srv:GetRDDLParams-response instead.")))

(cl:ensure-generic-function 'horizon-val :lambda-list '(m))
(cl:defmethod horizon-val ((m <GetRDDLParams-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:horizon-val is deprecated.  Use rosplan_knowledge_msgs-srv:horizon instead.")
  (horizon m))

(cl:ensure-generic-function 'discount_factor-val :lambda-list '(m))
(cl:defmethod discount_factor-val ((m <GetRDDLParams-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:discount_factor-val is deprecated.  Use rosplan_knowledge_msgs-srv:discount_factor instead.")
  (discount_factor m))

(cl:ensure-generic-function 'max_nondef_actions-val :lambda-list '(m))
(cl:defmethod max_nondef_actions-val ((m <GetRDDLParams-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:max_nondef_actions-val is deprecated.  Use rosplan_knowledge_msgs-srv:max_nondef_actions instead.")
  (max_nondef_actions m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRDDLParams-response>) ostream)
  "Serializes a message object of type '<GetRDDLParams-response>"
  (cl:let* ((signed (cl:slot-value msg 'horizon)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'discount_factor))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'max_nondef_actions)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRDDLParams-response>) istream)
  "Deserializes a message object of type '<GetRDDLParams-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'horizon) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'discount_factor) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'max_nondef_actions) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRDDLParams-response>)))
  "Returns string type for a service object of type '<GetRDDLParams-response>"
  "rosplan_knowledge_msgs/GetRDDLParamsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLParams-response)))
  "Returns string type for a service object of type 'GetRDDLParams-response"
  "rosplan_knowledge_msgs/GetRDDLParamsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRDDLParams-response>)))
  "Returns md5sum for a message object of type '<GetRDDLParams-response>"
  "0cf0ef8b4c4b342e8f951535dfe54dba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRDDLParams-response)))
  "Returns md5sum for a message object of type 'GetRDDLParams-response"
  "0cf0ef8b4c4b342e8f951535dfe54dba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRDDLParams-response>)))
  "Returns full string definition for message of type '<GetRDDLParams-response>"
  (cl:format cl:nil "int32 horizon~%float32 discount_factor~%int32 max_nondef_actions~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRDDLParams-response)))
  "Returns full string definition for message of type 'GetRDDLParams-response"
  (cl:format cl:nil "int32 horizon~%float32 discount_factor~%int32 max_nondef_actions~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRDDLParams-response>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRDDLParams-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRDDLParams-response
    (cl:cons ':horizon (horizon msg))
    (cl:cons ':discount_factor (discount_factor msg))
    (cl:cons ':max_nondef_actions (max_nondef_actions msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetRDDLParams)))
  'GetRDDLParams-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetRDDLParams)))
  'GetRDDLParams-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLParams)))
  "Returns string type for a service object of type '<GetRDDLParams>"
  "rosplan_knowledge_msgs/GetRDDLParams")