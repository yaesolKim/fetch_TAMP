; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-srv)


;//! \htmlinclude SetNamedBool-request.msg.html

(cl:defclass <SetNamedBool-request> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (value
    :reader value
    :initarg :value
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SetNamedBool-request (<SetNamedBool-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetNamedBool-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetNamedBool-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<SetNamedBool-request> is deprecated: use rosplan_knowledge_msgs-srv:SetNamedBool-request instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <SetNamedBool-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:name-val is deprecated.  Use rosplan_knowledge_msgs-srv:name instead.")
  (name m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <SetNamedBool-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:value-val is deprecated.  Use rosplan_knowledge_msgs-srv:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetNamedBool-request>) ostream)
  "Serializes a message object of type '<SetNamedBool-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'value) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetNamedBool-request>) istream)
  "Deserializes a message object of type '<SetNamedBool-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'value) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetNamedBool-request>)))
  "Returns string type for a service object of type '<SetNamedBool-request>"
  "rosplan_knowledge_msgs/SetNamedBoolRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetNamedBool-request)))
  "Returns string type for a service object of type 'SetNamedBool-request"
  "rosplan_knowledge_msgs/SetNamedBoolRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetNamedBool-request>)))
  "Returns md5sum for a message object of type '<SetNamedBool-request>"
  "c7f243f8c6655aded1b4e1f571c7cee3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetNamedBool-request)))
  "Returns md5sum for a message object of type 'SetNamedBool-request"
  "c7f243f8c6655aded1b4e1f571c7cee3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetNamedBool-request>)))
  "Returns full string definition for message of type '<SetNamedBool-request>"
  (cl:format cl:nil "string name~%bool value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetNamedBool-request)))
  "Returns full string definition for message of type 'SetNamedBool-request"
  (cl:format cl:nil "string name~%bool value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetNamedBool-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetNamedBool-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetNamedBool-request
    (cl:cons ':name (name msg))
    (cl:cons ':value (value msg))
))
;//! \htmlinclude SetNamedBool-response.msg.html

(cl:defclass <SetNamedBool-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SetNamedBool-response (<SetNamedBool-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetNamedBool-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetNamedBool-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<SetNamedBool-response> is deprecated: use rosplan_knowledge_msgs-srv:SetNamedBool-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetNamedBool-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:success-val is deprecated.  Use rosplan_knowledge_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetNamedBool-response>) ostream)
  "Serializes a message object of type '<SetNamedBool-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetNamedBool-response>) istream)
  "Deserializes a message object of type '<SetNamedBool-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetNamedBool-response>)))
  "Returns string type for a service object of type '<SetNamedBool-response>"
  "rosplan_knowledge_msgs/SetNamedBoolResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetNamedBool-response)))
  "Returns string type for a service object of type 'SetNamedBool-response"
  "rosplan_knowledge_msgs/SetNamedBoolResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetNamedBool-response>)))
  "Returns md5sum for a message object of type '<SetNamedBool-response>"
  "c7f243f8c6655aded1b4e1f571c7cee3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetNamedBool-response)))
  "Returns md5sum for a message object of type 'SetNamedBool-response"
  "c7f243f8c6655aded1b4e1f571c7cee3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetNamedBool-response>)))
  "Returns full string definition for message of type '<SetNamedBool-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetNamedBool-response)))
  "Returns full string definition for message of type 'SetNamedBool-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetNamedBool-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetNamedBool-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetNamedBool-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetNamedBool)))
  'SetNamedBool-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetNamedBool)))
  'SetNamedBool-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetNamedBool)))
  "Returns string type for a service object of type '<SetNamedBool>"
  "rosplan_knowledge_msgs/SetNamedBool")