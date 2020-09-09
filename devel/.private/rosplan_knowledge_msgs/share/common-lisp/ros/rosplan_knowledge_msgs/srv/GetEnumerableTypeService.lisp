; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-srv)


;//! \htmlinclude GetEnumerableTypeService-request.msg.html

(cl:defclass <GetEnumerableTypeService-request> (roslisp-msg-protocol:ros-message)
  ((type_name
    :reader type_name
    :initarg :type_name
    :type cl:string
    :initform ""))
)

(cl:defclass GetEnumerableTypeService-request (<GetEnumerableTypeService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetEnumerableTypeService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetEnumerableTypeService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetEnumerableTypeService-request> is deprecated: use rosplan_knowledge_msgs-srv:GetEnumerableTypeService-request instead.")))

(cl:ensure-generic-function 'type_name-val :lambda-list '(m))
(cl:defmethod type_name-val ((m <GetEnumerableTypeService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:type_name-val is deprecated.  Use rosplan_knowledge_msgs-srv:type_name instead.")
  (type_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetEnumerableTypeService-request>) ostream)
  "Serializes a message object of type '<GetEnumerableTypeService-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'type_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'type_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetEnumerableTypeService-request>) istream)
  "Deserializes a message object of type '<GetEnumerableTypeService-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'type_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'type_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetEnumerableTypeService-request>)))
  "Returns string type for a service object of type '<GetEnumerableTypeService-request>"
  "rosplan_knowledge_msgs/GetEnumerableTypeServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetEnumerableTypeService-request)))
  "Returns string type for a service object of type 'GetEnumerableTypeService-request"
  "rosplan_knowledge_msgs/GetEnumerableTypeServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetEnumerableTypeService-request>)))
  "Returns md5sum for a message object of type '<GetEnumerableTypeService-request>"
  "620e0db27dedf37a3e89c5aaa3324d1b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetEnumerableTypeService-request)))
  "Returns md5sum for a message object of type 'GetEnumerableTypeService-request"
  "620e0db27dedf37a3e89c5aaa3324d1b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetEnumerableTypeService-request>)))
  "Returns full string definition for message of type '<GetEnumerableTypeService-request>"
  (cl:format cl:nil "# Get all values of the enumeration type with the name 'typeName'.~%string type_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetEnumerableTypeService-request)))
  "Returns full string definition for message of type 'GetEnumerableTypeService-request"
  (cl:format cl:nil "# Get all values of the enumeration type with the name 'typeName'.~%string type_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetEnumerableTypeService-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'type_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetEnumerableTypeService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetEnumerableTypeService-request
    (cl:cons ':type_name (type_name msg))
))
;//! \htmlinclude GetEnumerableTypeService-response.msg.html

(cl:defclass <GetEnumerableTypeService-response> (roslisp-msg-protocol:ros-message)
  ((values
    :reader values
    :initarg :values
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass GetEnumerableTypeService-response (<GetEnumerableTypeService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetEnumerableTypeService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetEnumerableTypeService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<GetEnumerableTypeService-response> is deprecated: use rosplan_knowledge_msgs-srv:GetEnumerableTypeService-response instead.")))

(cl:ensure-generic-function 'values-val :lambda-list '(m))
(cl:defmethod values-val ((m <GetEnumerableTypeService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:values-val is deprecated.  Use rosplan_knowledge_msgs-srv:values instead.")
  (values m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetEnumerableTypeService-response>) ostream)
  "Serializes a message object of type '<GetEnumerableTypeService-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'values))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'values))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetEnumerableTypeService-response>) istream)
  "Deserializes a message object of type '<GetEnumerableTypeService-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'values) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'values)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetEnumerableTypeService-response>)))
  "Returns string type for a service object of type '<GetEnumerableTypeService-response>"
  "rosplan_knowledge_msgs/GetEnumerableTypeServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetEnumerableTypeService-response)))
  "Returns string type for a service object of type 'GetEnumerableTypeService-response"
  "rosplan_knowledge_msgs/GetEnumerableTypeServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetEnumerableTypeService-response>)))
  "Returns md5sum for a message object of type '<GetEnumerableTypeService-response>"
  "620e0db27dedf37a3e89c5aaa3324d1b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetEnumerableTypeService-response)))
  "Returns md5sum for a message object of type 'GetEnumerableTypeService-response"
  "620e0db27dedf37a3e89c5aaa3324d1b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetEnumerableTypeService-response>)))
  "Returns full string definition for message of type '<GetEnumerableTypeService-response>"
  (cl:format cl:nil "string[] values~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetEnumerableTypeService-response)))
  "Returns full string definition for message of type 'GetEnumerableTypeService-response"
  (cl:format cl:nil "string[] values~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetEnumerableTypeService-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'values) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetEnumerableTypeService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetEnumerableTypeService-response
    (cl:cons ':values (values msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetEnumerableTypeService)))
  'GetEnumerableTypeService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetEnumerableTypeService)))
  'GetEnumerableTypeService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetEnumerableTypeService)))
  "Returns string type for a service object of type '<GetEnumerableTypeService>"
  "rosplan_knowledge_msgs/GetEnumerableTypeService")