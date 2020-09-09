; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-srv)


;//! \htmlinclude ReloadRDDLDomainProblem-request.msg.html

(cl:defclass <ReloadRDDLDomainProblem-request> (roslisp-msg-protocol:ros-message)
  ((problem_path
    :reader problem_path
    :initarg :problem_path
    :type cl:string
    :initform ""))
)

(cl:defclass ReloadRDDLDomainProblem-request (<ReloadRDDLDomainProblem-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReloadRDDLDomainProblem-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReloadRDDLDomainProblem-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<ReloadRDDLDomainProblem-request> is deprecated: use rosplan_knowledge_msgs-srv:ReloadRDDLDomainProblem-request instead.")))

(cl:ensure-generic-function 'problem_path-val :lambda-list '(m))
(cl:defmethod problem_path-val ((m <ReloadRDDLDomainProblem-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:problem_path-val is deprecated.  Use rosplan_knowledge_msgs-srv:problem_path instead.")
  (problem_path m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReloadRDDLDomainProblem-request>) ostream)
  "Serializes a message object of type '<ReloadRDDLDomainProblem-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'problem_path))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'problem_path))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReloadRDDLDomainProblem-request>) istream)
  "Deserializes a message object of type '<ReloadRDDLDomainProblem-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'problem_path) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'problem_path) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReloadRDDLDomainProblem-request>)))
  "Returns string type for a service object of type '<ReloadRDDLDomainProblem-request>"
  "rosplan_knowledge_msgs/ReloadRDDLDomainProblemRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReloadRDDLDomainProblem-request)))
  "Returns string type for a service object of type 'ReloadRDDLDomainProblem-request"
  "rosplan_knowledge_msgs/ReloadRDDLDomainProblemRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReloadRDDLDomainProblem-request>)))
  "Returns md5sum for a message object of type '<ReloadRDDLDomainProblem-request>"
  "46f5005f9ac31164db24c532bfe60e3b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReloadRDDLDomainProblem-request)))
  "Returns md5sum for a message object of type 'ReloadRDDLDomainProblem-request"
  "46f5005f9ac31164db24c532bfe60e3b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReloadRDDLDomainProblem-request>)))
  "Returns full string definition for message of type '<ReloadRDDLDomainProblem-request>"
  (cl:format cl:nil "string problem_path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReloadRDDLDomainProblem-request)))
  "Returns full string definition for message of type 'ReloadRDDLDomainProblem-request"
  (cl:format cl:nil "string problem_path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReloadRDDLDomainProblem-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'problem_path))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReloadRDDLDomainProblem-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ReloadRDDLDomainProblem-request
    (cl:cons ':problem_path (problem_path msg))
))
;//! \htmlinclude ReloadRDDLDomainProblem-response.msg.html

(cl:defclass <ReloadRDDLDomainProblem-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ReloadRDDLDomainProblem-response (<ReloadRDDLDomainProblem-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReloadRDDLDomainProblem-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReloadRDDLDomainProblem-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-srv:<ReloadRDDLDomainProblem-response> is deprecated: use rosplan_knowledge_msgs-srv:ReloadRDDLDomainProblem-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <ReloadRDDLDomainProblem-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-srv:success-val is deprecated.  Use rosplan_knowledge_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReloadRDDLDomainProblem-response>) ostream)
  "Serializes a message object of type '<ReloadRDDLDomainProblem-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReloadRDDLDomainProblem-response>) istream)
  "Deserializes a message object of type '<ReloadRDDLDomainProblem-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReloadRDDLDomainProblem-response>)))
  "Returns string type for a service object of type '<ReloadRDDLDomainProblem-response>"
  "rosplan_knowledge_msgs/ReloadRDDLDomainProblemResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReloadRDDLDomainProblem-response)))
  "Returns string type for a service object of type 'ReloadRDDLDomainProblem-response"
  "rosplan_knowledge_msgs/ReloadRDDLDomainProblemResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReloadRDDLDomainProblem-response>)))
  "Returns md5sum for a message object of type '<ReloadRDDLDomainProblem-response>"
  "46f5005f9ac31164db24c532bfe60e3b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReloadRDDLDomainProblem-response)))
  "Returns md5sum for a message object of type 'ReloadRDDLDomainProblem-response"
  "46f5005f9ac31164db24c532bfe60e3b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReloadRDDLDomainProblem-response>)))
  "Returns full string definition for message of type '<ReloadRDDLDomainProblem-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReloadRDDLDomainProblem-response)))
  "Returns full string definition for message of type 'ReloadRDDLDomainProblem-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReloadRDDLDomainProblem-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReloadRDDLDomainProblem-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ReloadRDDLDomainProblem-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ReloadRDDLDomainProblem)))
  'ReloadRDDLDomainProblem-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ReloadRDDLDomainProblem)))
  'ReloadRDDLDomainProblem-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReloadRDDLDomainProblem)))
  "Returns string type for a service object of type '<ReloadRDDLDomainProblem>"
  "rosplan_knowledge_msgs/ReloadRDDLDomainProblem")