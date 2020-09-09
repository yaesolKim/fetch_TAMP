; Auto-generated. Do not edit!


(cl:in-package rosplan_dispatch_msgs-srv)


;//! \htmlinclude DispatchService-request.msg.html

(cl:defclass <DispatchService-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass DispatchService-request (<DispatchService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DispatchService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DispatchService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_dispatch_msgs-srv:<DispatchService-request> is deprecated: use rosplan_dispatch_msgs-srv:DispatchService-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DispatchService-request>) ostream)
  "Serializes a message object of type '<DispatchService-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DispatchService-request>) istream)
  "Deserializes a message object of type '<DispatchService-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DispatchService-request>)))
  "Returns string type for a service object of type '<DispatchService-request>"
  "rosplan_dispatch_msgs/DispatchServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DispatchService-request)))
  "Returns string type for a service object of type 'DispatchService-request"
  "rosplan_dispatch_msgs/DispatchServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DispatchService-request>)))
  "Returns md5sum for a message object of type '<DispatchService-request>"
  "7e14a3412cb82ba736fcf0fad2853ed3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DispatchService-request)))
  "Returns md5sum for a message object of type 'DispatchService-request"
  "7e14a3412cb82ba736fcf0fad2853ed3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DispatchService-request>)))
  "Returns full string definition for message of type '<DispatchService-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DispatchService-request)))
  "Returns full string definition for message of type 'DispatchService-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DispatchService-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DispatchService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'DispatchService-request
))
;//! \htmlinclude DispatchService-response.msg.html

(cl:defclass <DispatchService-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (goal_achieved
    :reader goal_achieved
    :initarg :goal_achieved
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass DispatchService-response (<DispatchService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DispatchService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DispatchService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_dispatch_msgs-srv:<DispatchService-response> is deprecated: use rosplan_dispatch_msgs-srv:DispatchService-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <DispatchService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_dispatch_msgs-srv:success-val is deprecated.  Use rosplan_dispatch_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'goal_achieved-val :lambda-list '(m))
(cl:defmethod goal_achieved-val ((m <DispatchService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_dispatch_msgs-srv:goal_achieved-val is deprecated.  Use rosplan_dispatch_msgs-srv:goal_achieved instead.")
  (goal_achieved m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DispatchService-response>) ostream)
  "Serializes a message object of type '<DispatchService-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'goal_achieved) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DispatchService-response>) istream)
  "Deserializes a message object of type '<DispatchService-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'goal_achieved) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DispatchService-response>)))
  "Returns string type for a service object of type '<DispatchService-response>"
  "rosplan_dispatch_msgs/DispatchServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DispatchService-response)))
  "Returns string type for a service object of type 'DispatchService-response"
  "rosplan_dispatch_msgs/DispatchServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DispatchService-response>)))
  "Returns md5sum for a message object of type '<DispatchService-response>"
  "7e14a3412cb82ba736fcf0fad2853ed3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DispatchService-response)))
  "Returns md5sum for a message object of type 'DispatchService-response"
  "7e14a3412cb82ba736fcf0fad2853ed3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DispatchService-response>)))
  "Returns full string definition for message of type '<DispatchService-response>"
  (cl:format cl:nil "bool success # True if the dispatch was successful~%bool goal_achieved # True if the goal is achieved after the dispatching~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DispatchService-response)))
  "Returns full string definition for message of type 'DispatchService-response"
  (cl:format cl:nil "bool success # True if the dispatch was successful~%bool goal_achieved # True if the goal is achieved after the dispatching~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DispatchService-response>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DispatchService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'DispatchService-response
    (cl:cons ':success (success msg))
    (cl:cons ':goal_achieved (goal_achieved msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'DispatchService)))
  'DispatchService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'DispatchService)))
  'DispatchService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DispatchService)))
  "Returns string type for a service object of type '<DispatchService>"
  "rosplan_dispatch_msgs/DispatchService")