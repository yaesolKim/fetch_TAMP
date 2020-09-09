;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::ProbabilisticEffect)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'ProbabilisticEffect (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::PROBABILISTICEFFECT")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::PROBABILISTICEFFECT"))

(in-package "ROS")
;;//! \htmlinclude ProbabilisticEffect.msg.html


(defclass rosplan_knowledge_msgs::ProbabilisticEffect
  :super ros::object
  :slots (_probability _add_effects _del_effects _assign_effects ))

(defmethod rosplan_knowledge_msgs::ProbabilisticEffect
  (:init
   (&key
    ((:probability __probability) (instance rosplan_knowledge_msgs::ExprComposite :init))
    ((:add_effects __add_effects) (let (r) (dotimes (i 0) (push (instance rosplan_knowledge_msgs::DomainFormula :init) r)) r))
    ((:del_effects __del_effects) (let (r) (dotimes (i 0) (push (instance rosplan_knowledge_msgs::DomainFormula :init) r)) r))
    ((:assign_effects __assign_effects) (let (r) (dotimes (i 0) (push (instance rosplan_knowledge_msgs::DomainAssignment :init) r)) r))
    )
   (send-super :init)
   (setq _probability __probability)
   (setq _add_effects __add_effects)
   (setq _del_effects __del_effects)
   (setq _assign_effects __assign_effects)
   self)
  (:probability
   (&rest __probability)
   (if (keywordp (car __probability))
       (send* _probability __probability)
     (progn
       (if __probability (setq _probability (car __probability)))
       _probability)))
  (:add_effects
   (&rest __add_effects)
   (if (keywordp (car __add_effects))
       (send* _add_effects __add_effects)
     (progn
       (if __add_effects (setq _add_effects (car __add_effects)))
       _add_effects)))
  (:del_effects
   (&rest __del_effects)
   (if (keywordp (car __del_effects))
       (send* _del_effects __del_effects)
     (progn
       (if __del_effects (setq _del_effects (car __del_effects)))
       _del_effects)))
  (:assign_effects
   (&rest __assign_effects)
   (if (keywordp (car __assign_effects))
       (send* _assign_effects __assign_effects)
     (progn
       (if __assign_effects (setq _assign_effects (car __assign_effects)))
       _assign_effects)))
  (:serialization-length
   ()
   (+
    ;; rosplan_knowledge_msgs/ExprComposite _probability
    (send _probability :serialization-length)
    ;; rosplan_knowledge_msgs/DomainFormula[] _add_effects
    (apply #'+ (send-all _add_effects :serialization-length)) 4
    ;; rosplan_knowledge_msgs/DomainFormula[] _del_effects
    (apply #'+ (send-all _del_effects :serialization-length)) 4
    ;; rosplan_knowledge_msgs/DomainAssignment[] _assign_effects
    (apply #'+ (send-all _assign_effects :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; rosplan_knowledge_msgs/ExprComposite _probability
       (send _probability :serialize s)
     ;; rosplan_knowledge_msgs/DomainFormula[] _add_effects
     (write-long (length _add_effects) s)
     (dolist (elem _add_effects)
       (send elem :serialize s)
       )
     ;; rosplan_knowledge_msgs/DomainFormula[] _del_effects
     (write-long (length _del_effects) s)
     (dolist (elem _del_effects)
       (send elem :serialize s)
       )
     ;; rosplan_knowledge_msgs/DomainAssignment[] _assign_effects
     (write-long (length _assign_effects) s)
     (dolist (elem _assign_effects)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; rosplan_knowledge_msgs/ExprComposite _probability
     (send _probability :deserialize buf ptr-) (incf ptr- (send _probability :serialization-length))
   ;; rosplan_knowledge_msgs/DomainFormula[] _add_effects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _add_effects (let (r) (dotimes (i n) (push (instance rosplan_knowledge_msgs::DomainFormula :init) r)) r))
     (dolist (elem- _add_effects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; rosplan_knowledge_msgs/DomainFormula[] _del_effects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _del_effects (let (r) (dotimes (i n) (push (instance rosplan_knowledge_msgs::DomainFormula :init) r)) r))
     (dolist (elem- _del_effects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; rosplan_knowledge_msgs/DomainAssignment[] _assign_effects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _assign_effects (let (r) (dotimes (i n) (push (instance rosplan_knowledge_msgs::DomainAssignment :init) r)) r))
     (dolist (elem- _assign_effects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get rosplan_knowledge_msgs::ProbabilisticEffect :md5sum-) "38057e6bf125b030ee96bd190e741d81")
(setf (get rosplan_knowledge_msgs::ProbabilisticEffect :datatype-) "rosplan_knowledge_msgs/ProbabilisticEffect")
(setf (get rosplan_knowledge_msgs::ProbabilisticEffect :definition-)
      "# Message used to represent a Probabilistic effect 
rosplan_knowledge_msgs/ExprComposite   probability
rosplan_knowledge_msgs/DomainFormula[] add_effects # Add effects
rosplan_knowledge_msgs/DomainFormula[] del_effects # Del effects
rosplan_knowledge_msgs/DomainAssignment[] assign_effects # Assign effects, mainly used for RDDL Discrete distribution
================================================================================
MSG: rosplan_knowledge_msgs/ExprComposite
# A message used to represent a numerical expression; composite type (2/2)
# stores an array of ExprBase as prefix notation

# components
ExprBase[] tokens

================================================================================
MSG: rosplan_knowledge_msgs/ExprBase
# A message used to represent a numerical expression; base types (1/2)

# expression types
uint8 CONSTANT = 0
uint8 FUNCTION = 1
uint8 OPERATOR = 2
uint8 SPECIAL  = 3

# operators
uint8 ADD    = 0
uint8 SUB    = 1
uint8 MUL    = 2
uint8 DIV    = 3
uint8 UMINUS = 4

# special types
uint8 HASHT      = 0
uint8 TOTAL_TIME = 1
uint8 DURATION   = 2

# expression base type
uint8 expr_type

# constant value
float64 constant

# function
rosplan_knowledge_msgs/DomainFormula function

# operator
uint8 op

# special
uint8 special_type

================================================================================
MSG: rosplan_knowledge_msgs/DomainFormula
# A message used to represent an atomic formula from the domain.
# typed_parameters matches label -> type
string name
diagnostic_msgs/KeyValue[] typed_parameters

================================================================================
MSG: diagnostic_msgs/KeyValue
string key # what to label this value when viewing
string value # a value to track over time

================================================================================
MSG: rosplan_knowledge_msgs/DomainAssignment
# A message used to store the numeric effects of an action
# Can be grounded or ungrounded

uint8 ASSIGN   = 0
uint8 INCREASE  = 1
uint8 DECREASE = 2
uint8 SCALE_UP = 3
uint8 SCALE_DOWN = 4
uint8 ASSIGN_CTS = 5

uint8 assign_type

rosplan_knowledge_msgs/DomainFormula LHS
rosplan_knowledge_msgs/ExprComposite RHS

bool grounded

")



(provide :rosplan_knowledge_msgs/ProbabilisticEffect "38057e6bf125b030ee96bd190e741d81")


