; Auto-generated. Do not edit!


(cl:in-package rosplan_knowledge_msgs-msg)


;//! \htmlinclude ProbabilisticEffect.msg.html

(cl:defclass <ProbabilisticEffect> (roslisp-msg-protocol:ros-message)
  ((probability
    :reader probability
    :initarg :probability
    :type rosplan_knowledge_msgs-msg:ExprComposite
    :initform (cl:make-instance 'rosplan_knowledge_msgs-msg:ExprComposite))
   (add_effects
    :reader add_effects
    :initarg :add_effects
    :type (cl:vector rosplan_knowledge_msgs-msg:DomainFormula)
   :initform (cl:make-array 0 :element-type 'rosplan_knowledge_msgs-msg:DomainFormula :initial-element (cl:make-instance 'rosplan_knowledge_msgs-msg:DomainFormula)))
   (del_effects
    :reader del_effects
    :initarg :del_effects
    :type (cl:vector rosplan_knowledge_msgs-msg:DomainFormula)
   :initform (cl:make-array 0 :element-type 'rosplan_knowledge_msgs-msg:DomainFormula :initial-element (cl:make-instance 'rosplan_knowledge_msgs-msg:DomainFormula)))
   (assign_effects
    :reader assign_effects
    :initarg :assign_effects
    :type (cl:vector rosplan_knowledge_msgs-msg:DomainAssignment)
   :initform (cl:make-array 0 :element-type 'rosplan_knowledge_msgs-msg:DomainAssignment :initial-element (cl:make-instance 'rosplan_knowledge_msgs-msg:DomainAssignment))))
)

(cl:defclass ProbabilisticEffect (<ProbabilisticEffect>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ProbabilisticEffect>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ProbabilisticEffect)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosplan_knowledge_msgs-msg:<ProbabilisticEffect> is deprecated: use rosplan_knowledge_msgs-msg:ProbabilisticEffect instead.")))

(cl:ensure-generic-function 'probability-val :lambda-list '(m))
(cl:defmethod probability-val ((m <ProbabilisticEffect>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-msg:probability-val is deprecated.  Use rosplan_knowledge_msgs-msg:probability instead.")
  (probability m))

(cl:ensure-generic-function 'add_effects-val :lambda-list '(m))
(cl:defmethod add_effects-val ((m <ProbabilisticEffect>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-msg:add_effects-val is deprecated.  Use rosplan_knowledge_msgs-msg:add_effects instead.")
  (add_effects m))

(cl:ensure-generic-function 'del_effects-val :lambda-list '(m))
(cl:defmethod del_effects-val ((m <ProbabilisticEffect>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-msg:del_effects-val is deprecated.  Use rosplan_knowledge_msgs-msg:del_effects instead.")
  (del_effects m))

(cl:ensure-generic-function 'assign_effects-val :lambda-list '(m))
(cl:defmethod assign_effects-val ((m <ProbabilisticEffect>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosplan_knowledge_msgs-msg:assign_effects-val is deprecated.  Use rosplan_knowledge_msgs-msg:assign_effects instead.")
  (assign_effects m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ProbabilisticEffect>) ostream)
  "Serializes a message object of type '<ProbabilisticEffect>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'probability) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'add_effects))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'add_effects))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'del_effects))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'del_effects))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'assign_effects))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'assign_effects))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ProbabilisticEffect>) istream)
  "Deserializes a message object of type '<ProbabilisticEffect>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'probability) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'add_effects) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'add_effects)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'rosplan_knowledge_msgs-msg:DomainFormula))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'del_effects) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'del_effects)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'rosplan_knowledge_msgs-msg:DomainFormula))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'assign_effects) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'assign_effects)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'rosplan_knowledge_msgs-msg:DomainAssignment))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ProbabilisticEffect>)))
  "Returns string type for a message object of type '<ProbabilisticEffect>"
  "rosplan_knowledge_msgs/ProbabilisticEffect")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ProbabilisticEffect)))
  "Returns string type for a message object of type 'ProbabilisticEffect"
  "rosplan_knowledge_msgs/ProbabilisticEffect")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ProbabilisticEffect>)))
  "Returns md5sum for a message object of type '<ProbabilisticEffect>"
  "38057e6bf125b030ee96bd190e741d81")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ProbabilisticEffect)))
  "Returns md5sum for a message object of type 'ProbabilisticEffect"
  "38057e6bf125b030ee96bd190e741d81")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ProbabilisticEffect>)))
  "Returns full string definition for message of type '<ProbabilisticEffect>"
  (cl:format cl:nil "# Message used to represent a Probabilistic effect ~%rosplan_knowledge_msgs/ExprComposite   probability~%rosplan_knowledge_msgs/DomainFormula[] add_effects # Add effects~%rosplan_knowledge_msgs/DomainFormula[] del_effects # Del effects~%rosplan_knowledge_msgs/DomainAssignment[] assign_effects # Assign effects, mainly used for RDDL Discrete distribution~%================================================================================~%MSG: rosplan_knowledge_msgs/ExprComposite~%# A message used to represent a numerical expression; composite type (2/2)~%# stores an array of ExprBase as prefix notation~%~%# components~%ExprBase[] tokens~%~%================================================================================~%MSG: rosplan_knowledge_msgs/ExprBase~%# A message used to represent a numerical expression; base types (1/2)~%~%# expression types~%uint8 CONSTANT = 0~%uint8 FUNCTION = 1~%uint8 OPERATOR = 2~%uint8 SPECIAL  = 3~%~%# operators~%uint8 ADD    = 0~%uint8 SUB    = 1~%uint8 MUL    = 2~%uint8 DIV    = 3~%uint8 UMINUS = 4~%~%# special types~%uint8 HASHT      = 0~%uint8 TOTAL_TIME = 1~%uint8 DURATION   = 2~%~%# expression base type~%uint8 expr_type~%~%# constant value~%float64 constant~%~%# function~%rosplan_knowledge_msgs/DomainFormula function~%~%# operator~%uint8 op~%~%# special~%uint8 special_type~%~%================================================================================~%MSG: rosplan_knowledge_msgs/DomainFormula~%# A message used to represent an atomic formula from the domain.~%# typed_parameters matches label -> type~%string name~%diagnostic_msgs/KeyValue[] typed_parameters~%~%================================================================================~%MSG: diagnostic_msgs/KeyValue~%string key # what to label this value when viewing~%string value # a value to track over time~%~%================================================================================~%MSG: rosplan_knowledge_msgs/DomainAssignment~%# A message used to store the numeric effects of an action~%# Can be grounded or ungrounded~%~%uint8 ASSIGN   = 0~%uint8 INCREASE  = 1~%uint8 DECREASE = 2~%uint8 SCALE_UP = 3~%uint8 SCALE_DOWN = 4~%uint8 ASSIGN_CTS = 5~%~%uint8 assign_type~%~%rosplan_knowledge_msgs/DomainFormula LHS~%rosplan_knowledge_msgs/ExprComposite RHS~%~%bool grounded~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ProbabilisticEffect)))
  "Returns full string definition for message of type 'ProbabilisticEffect"
  (cl:format cl:nil "# Message used to represent a Probabilistic effect ~%rosplan_knowledge_msgs/ExprComposite   probability~%rosplan_knowledge_msgs/DomainFormula[] add_effects # Add effects~%rosplan_knowledge_msgs/DomainFormula[] del_effects # Del effects~%rosplan_knowledge_msgs/DomainAssignment[] assign_effects # Assign effects, mainly used for RDDL Discrete distribution~%================================================================================~%MSG: rosplan_knowledge_msgs/ExprComposite~%# A message used to represent a numerical expression; composite type (2/2)~%# stores an array of ExprBase as prefix notation~%~%# components~%ExprBase[] tokens~%~%================================================================================~%MSG: rosplan_knowledge_msgs/ExprBase~%# A message used to represent a numerical expression; base types (1/2)~%~%# expression types~%uint8 CONSTANT = 0~%uint8 FUNCTION = 1~%uint8 OPERATOR = 2~%uint8 SPECIAL  = 3~%~%# operators~%uint8 ADD    = 0~%uint8 SUB    = 1~%uint8 MUL    = 2~%uint8 DIV    = 3~%uint8 UMINUS = 4~%~%# special types~%uint8 HASHT      = 0~%uint8 TOTAL_TIME = 1~%uint8 DURATION   = 2~%~%# expression base type~%uint8 expr_type~%~%# constant value~%float64 constant~%~%# function~%rosplan_knowledge_msgs/DomainFormula function~%~%# operator~%uint8 op~%~%# special~%uint8 special_type~%~%================================================================================~%MSG: rosplan_knowledge_msgs/DomainFormula~%# A message used to represent an atomic formula from the domain.~%# typed_parameters matches label -> type~%string name~%diagnostic_msgs/KeyValue[] typed_parameters~%~%================================================================================~%MSG: diagnostic_msgs/KeyValue~%string key # what to label this value when viewing~%string value # a value to track over time~%~%================================================================================~%MSG: rosplan_knowledge_msgs/DomainAssignment~%# A message used to store the numeric effects of an action~%# Can be grounded or ungrounded~%~%uint8 ASSIGN   = 0~%uint8 INCREASE  = 1~%uint8 DECREASE = 2~%uint8 SCALE_UP = 3~%uint8 SCALE_DOWN = 4~%uint8 ASSIGN_CTS = 5~%~%uint8 assign_type~%~%rosplan_knowledge_msgs/DomainFormula LHS~%rosplan_knowledge_msgs/ExprComposite RHS~%~%bool grounded~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ProbabilisticEffect>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'probability))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'add_effects) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'del_effects) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'assign_effects) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ProbabilisticEffect>))
  "Converts a ROS message object to a list"
  (cl:list 'ProbabilisticEffect
    (cl:cons ':probability (probability msg))
    (cl:cons ':add_effects (add_effects msg))
    (cl:cons ':del_effects (del_effects msg))
    (cl:cons ':assign_effects (assign_effects msg))
))
