; Auto-generated. Do not edit!


(cl:in-package rosplan_dispatch_msgs-msg)


;//! \htmlinclude NonBlockingDispatchResult.msg.html

(cl:defclass <NonBlockingDispatchResult> (roslisp-msg-protocol:ros-message)
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

(cl:defclass NonBlockingDispatchResult (<NonBlockingDispatchResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NonBlockingDispatchResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NonBlockingDispatchResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_dispatch_msgs-msg:<NonBlockingDispatchResult> is deprecated: use rosplan_dispatch_msgs-msg:NonBlockingDispatchResult instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <NonBlockingDispatchResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_dispatch_msgs-msg:success-val is deprecated.  Use rosplan_dispatch_msgs-msg:success instead.")
  (success m))

(cl:ensure-generic-function 'goal_achieved-val :lambda-list '(m))
(cl:defmethod goal_achieved-val ((m <NonBlockingDispatchResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_dispatch_msgs-msg:goal_achieved-val is deprecated.  Use rosplan_dispatch_msgs-msg:goal_achieved instead.")
  (goal_achieved m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NonBlockingDispatchResult>) ostream)
  "Serializes a message object of type '<NonBlockingDispatchResult>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'goal_achieved) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NonBlockingDispatchResult>) istream)
  "Deserializes a message object of type '<NonBlockingDispatchResult>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'goal_achieved) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NonBlockingDispatchResult>)))
  "Returns string type for a message object of type '<NonBlockingDispatchResult>"
  "rosplan_dispatch_msgs/NonBlockingDispatchResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NonBlockingDispatchResult)))
  "Returns string type for a message object of type 'NonBlockingDispatchResult"
  "rosplan_dispatch_msgs/NonBlockingDispatchResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NonBlockingDispatchResult>)))
  "Returns md5sum for a message object of type '<NonBlockingDispatchResult>"
  "7e14a3412cb82ba736fcf0fad2853ed3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NonBlockingDispatchResult)))
  "Returns md5sum for a message object of type 'NonBlockingDispatchResult"
  "7e14a3412cb82ba736fcf0fad2853ed3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NonBlockingDispatchResult>)))
  "Returns full string definition for message of type '<NonBlockingDispatchResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%bool success # True if the dispatch was successful~%bool goal_achieved # True if the goal is achieved after the dispatching~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NonBlockingDispatchResult)))
  "Returns full string definition for message of type 'NonBlockingDispatchResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%bool success # True if the dispatch was successful~%bool goal_achieved # True if the goal is achieved after the dispatching~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NonBlockingDispatchResult>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NonBlockingDispatchResult>))
  "Converts a ROS message object to a list"
  (cl:list 'NonBlockingDispatchResult
    (cl:cons ':success (success msg))
    (cl:cons ':goal_achieved (goal_achieved msg))
))
