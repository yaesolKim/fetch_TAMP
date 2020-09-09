; Auto-generated. Do not edit!


(cl:in-package rosplan_dispatch_msgs-srv)


;//! \htmlinclude GetPlanningParams-request.msg.html

(cl:defclass <GetPlanningParams-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass GetPlanningParams-request (<GetPlanningParams-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetPlanningParams-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetPlanningParams-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_dispatch_msgs-srv:<GetPlanningParams-request> is deprecated: use rosplan_dispatch_msgs-srv:GetPlanningParams-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetPlanningParams-request>) ostream)
  "Serializes a message object of type '<GetPlanningParams-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetPlanningParams-request>) istream)
  "Deserializes a message object of type '<GetPlanningParams-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetPlanningParams-request>)))
  "Returns string type for a service object of type '<GetPlanningParams-request>"
  "rosplan_dispatch_msgs/GetPlanningParamsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetPlanningParams-request)))
  "Returns string type for a service object of type 'GetPlanningParams-request"
  "rosplan_dispatch_msgs/GetPlanningParamsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetPlanningParams-request>)))
  "Returns md5sum for a message object of type '<GetPlanningParams-request>"
  "b809da7a1aeeaa475218aad83ae1b3c4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetPlanningParams-request)))
  "Returns md5sum for a message object of type 'GetPlanningParams-request"
  "b809da7a1aeeaa475218aad83ae1b3c4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetPlanningParams-request>)))
  "Returns full string definition for message of type '<GetPlanningParams-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetPlanningParams-request)))
  "Returns full string definition for message of type 'GetPlanningParams-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetPlanningParams-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetPlanningParams-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetPlanningParams-request
))
;//! \htmlinclude GetPlanningParams-response.msg.html

(cl:defclass <GetPlanningParams-response> (roslisp-msg-protocol:ros-message)
  ((domain_path
    :reader domain_path
    :initarg :domain_path
    :type cl:string
    :initform "")
   (problem_path
    :reader problem_path
    :initarg :problem_path
    :type cl:string
    :initform "")
   (planner_ready
    :reader planner_ready
    :initarg :planner_ready
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass GetPlanningParams-response (<GetPlanningParams-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetPlanningParams-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetPlanningParams-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_dispatch_msgs-srv:<GetPlanningParams-response> is deprecated: use rosplan_dispatch_msgs-srv:GetPlanningParams-response instead.")))

(cl:ensure-generic-function 'domain_path-val :lambda-list '(m))
(cl:defmethod domain_path-val ((m <GetPlanningParams-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_dispatch_msgs-srv:domain_path-val is deprecated.  Use rosplan_dispatch_msgs-srv:domain_path instead.")
  (domain_path m))

(cl:ensure-generic-function 'problem_path-val :lambda-list '(m))
(cl:defmethod problem_path-val ((m <GetPlanningParams-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_dispatch_msgs-srv:problem_path-val is deprecated.  Use rosplan_dispatch_msgs-srv:problem_path instead.")
  (problem_path m))

(cl:ensure-generic-function 'planner_ready-val :lambda-list '(m))
(cl:defmethod planner_ready-val ((m <GetPlanningParams-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_dispatch_msgs-srv:planner_ready-val is deprecated.  Use rosplan_dispatch_msgs-srv:planner_ready instead.")
  (planner_ready m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetPlanningParams-response>) ostream)
  "Serializes a message object of type '<GetPlanningParams-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'domain_path))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'domain_path))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'problem_path))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'problem_path))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'planner_ready) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetPlanningParams-response>) istream)
  "Deserializes a message object of type '<GetPlanningParams-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'domain_path) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'domain_path) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'problem_path) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'problem_path) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'planner_ready) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetPlanningParams-response>)))
  "Returns string type for a service object of type '<GetPlanningParams-response>"
  "rosplan_dispatch_msgs/GetPlanningParamsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetPlanningParams-response)))
  "Returns string type for a service object of type 'GetPlanningParams-response"
  "rosplan_dispatch_msgs/GetPlanningParamsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetPlanningParams-response>)))
  "Returns md5sum for a message object of type '<GetPlanningParams-response>"
  "b809da7a1aeeaa475218aad83ae1b3c4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetPlanningParams-response)))
  "Returns md5sum for a message object of type 'GetPlanningParams-response"
  "b809da7a1aeeaa475218aad83ae1b3c4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetPlanningParams-response>)))
  "Returns full string definition for message of type '<GetPlanningParams-response>"
  (cl:format cl:nil "string domain_path~%string problem_path~%bool planner_ready # True if the planner thread is started~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetPlanningParams-response)))
  "Returns full string definition for message of type 'GetPlanningParams-response"
  (cl:format cl:nil "string domain_path~%string problem_path~%bool planner_ready # True if the planner thread is started~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetPlanningParams-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'domain_path))
     4 (cl:length (cl:slot-value msg 'problem_path))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetPlanningParams-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetPlanningParams-response
    (cl:cons ':domain_path (domain_path msg))
    (cl:cons ':problem_path (problem_path msg))
    (cl:cons ':planner_ready (planner_ready msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetPlanningParams)))
  'GetPlanningParams-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetPlanningParams)))
  'GetPlanningParams-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetPlanningParams)))
  "Returns string type for a service object of type '<GetPlanningParams>"
  "rosplan_dispatch_msgs/GetPlanningParams")