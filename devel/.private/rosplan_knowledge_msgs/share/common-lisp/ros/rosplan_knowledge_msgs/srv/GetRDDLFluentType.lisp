; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-srv)


;//! \htmlinclude GetRDDLFluentType-request.msg.html

(cl:defclass <GetRDDLFluentType-request> (roslisp-msg-protocol:ros-message)
  ((fluent_name
    :reader fluent_name
    :initarg :fluent_name
    :type cl:string
    :initform ""))
)

(cl:defclass GetRDDLFluentType-request (<GetRDDLFluentType-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRDDLFluentType-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRDDLFluentType-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetRDDLFluentType-request> is deprecated: use rosplan_knowledge_msgs-srv:GetRDDLFluentType-request instead.")))

(cl:ensure-generic-function 'fluent_name-val :lambda-list '(m))
(cl:defmethod fluent_name-val ((m <GetRDDLFluentType-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:fluent_name-val is deprecated.  Use rosplan_knowledge_msgs-srv:fluent_name instead.")
  (fluent_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRDDLFluentType-request>) ostream)
  "Serializes a message object of type '<GetRDDLFluentType-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'fluent_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'fluent_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRDDLFluentType-request>) istream)
  "Deserializes a message object of type '<GetRDDLFluentType-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'fluent_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'fluent_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRDDLFluentType-request>)))
  "Returns string type for a service object of type '<GetRDDLFluentType-request>"
  "rosplan_knowledge_msgs/GetRDDLFluentTypeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLFluentType-request)))
  "Returns string type for a service object of type 'GetRDDLFluentType-request"
  "rosplan_knowledge_msgs/GetRDDLFluentTypeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRDDLFluentType-request>)))
  "Returns md5sum for a message object of type '<GetRDDLFluentType-request>"
  "8b1465b2af1b2d6bd749f28c18e9cc8e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRDDLFluentType-request)))
  "Returns md5sum for a message object of type 'GetRDDLFluentType-request"
  "8b1465b2af1b2d6bd749f28c18e9cc8e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRDDLFluentType-request>)))
  "Returns full string definition for message of type '<GetRDDLFluentType-request>"
  (cl:format cl:nil "# Get all values of the enumeration type with the name 'typeName'.~%string fluent_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRDDLFluentType-request)))
  "Returns full string definition for message of type 'GetRDDLFluentType-request"
  (cl:format cl:nil "# Get all values of the enumeration type with the name 'typeName'.~%string fluent_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRDDLFluentType-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'fluent_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRDDLFluentType-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRDDLFluentType-request
    (cl:cons ':fluent_name (fluent_name msg))
))
;//! \htmlinclude GetRDDLFluentType-response.msg.html

(cl:defclass <GetRDDLFluentType-response> (roslisp-msg-protocol:ros-message)
  ((type
    :reader type
    :initarg :type
    :type cl:string
    :initform ""))
)

(cl:defclass GetRDDLFluentType-response (<GetRDDLFluentType-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRDDLFluentType-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRDDLFluentType-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetRDDLFluentType-response> is deprecated: use rosplan_knowledge_msgs-srv:GetRDDLFluentType-response instead.")))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <GetRDDLFluentType-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:type-val is deprecated.  Use rosplan_knowledge_msgs-srv:type instead.")
  (type m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRDDLFluentType-response>) ostream)
  "Serializes a message object of type '<GetRDDLFluentType-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'type))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRDDLFluentType-response>) istream)
  "Deserializes a message object of type '<GetRDDLFluentType-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRDDLFluentType-response>)))
  "Returns string type for a service object of type '<GetRDDLFluentType-response>"
  "rosplan_knowledge_msgs/GetRDDLFluentTypeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLFluentType-response)))
  "Returns string type for a service object of type 'GetRDDLFluentType-response"
  "rosplan_knowledge_msgs/GetRDDLFluentTypeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRDDLFluentType-response>)))
  "Returns md5sum for a message object of type '<GetRDDLFluentType-response>"
  "8b1465b2af1b2d6bd749f28c18e9cc8e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRDDLFluentType-response)))
  "Returns md5sum for a message object of type 'GetRDDLFluentType-response"
  "8b1465b2af1b2d6bd749f28c18e9cc8e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRDDLFluentType-response>)))
  "Returns full string definition for message of type '<GetRDDLFluentType-response>"
  (cl:format cl:nil "string type~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRDDLFluentType-response)))
  "Returns full string definition for message of type 'GetRDDLFluentType-response"
  (cl:format cl:nil "string type~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRDDLFluentType-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'type))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRDDLFluentType-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRDDLFluentType-response
    (cl:cons ':type (type msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetRDDLFluentType)))
  'GetRDDLFluentType-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetRDDLFluentType)))
  'GetRDDLFluentType-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRDDLFluentType)))
  "Returns string type for a service object of type '<GetRDDLFluentType>"
  "rosplan_knowledge_msgs/GetRDDLFluentType")