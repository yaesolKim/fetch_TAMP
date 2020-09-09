;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::GetRDDLFluentType)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'GetRDDLFluentType (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLFLUENTTYPE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLFLUENTTYPE"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLFLUENTTYPEREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLFLUENTTYPEREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLFLUENTTYPERESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLFLUENTTYPERESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::GetRDDLFluentTypeRequest
  :super ros::object
  :slots (_fluent_name ))

(defmethod rosplan_knowledge_msgs::GetRDDLFluentTypeRequest
  (:init
   (&key
    ((:fluent_name __fluent_name) "")
    )
   (send-super :init)
   (setq _fluent_name (string __fluent_name))
   self)
  (:fluent_name
   (&optional __fluent_name)
   (if __fluent_name (setq _fluent_name __fluent_name)) _fluent_name)
  (:serialization-length
   ()
   (+
    ;; string _fluent_name
    4 (length _fluent_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _fluent_name
       (write-long (length _fluent_name) s) (princ _fluent_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _fluent_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _fluent_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetRDDLFluentTypeResponse
  :super ros::object
  :slots (_type ))

(defmethod rosplan_knowledge_msgs::GetRDDLFluentTypeResponse
  (:init
   (&key
    ((:type __type) "")
    )
   (send-super :init)
   (setq _type (string __type))
   self)
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:serialization-length
   ()
   (+
    ;; string _type
    4 (length _type)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _type
       (write-long (length _type) s) (princ _type s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetRDDLFluentType
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::GetRDDLFluentType :md5sum-) "8b1465b2af1b2d6bd749f28c18e9cc8e")
(setf (get rosplan_knowledge_msgs::GetRDDLFluentType :datatype-) "rosplan_knowledge_msgs/GetRDDLFluentType")
(setf (get rosplan_knowledge_msgs::GetRDDLFluentType :request) rosplan_knowledge_msgs::GetRDDLFluentTypeRequest)
(setf (get rosplan_knowledge_msgs::GetRDDLFluentType :response) rosplan_knowledge_msgs::GetRDDLFluentTypeResponse)

(defmethod rosplan_knowledge_msgs::GetRDDLFluentTypeRequest
  (:response () (instance rosplan_knowledge_msgs::GetRDDLFluentTypeResponse :init)))

(setf (get rosplan_knowledge_msgs::GetRDDLFluentTypeRequest :md5sum-) "8b1465b2af1b2d6bd749f28c18e9cc8e")
(setf (get rosplan_knowledge_msgs::GetRDDLFluentTypeRequest :datatype-) "rosplan_knowledge_msgs/GetRDDLFluentTypeRequest")
(setf (get rosplan_knowledge_msgs::GetRDDLFluentTypeRequest :definition-)
      "# Get all values of the enumeration type with the name 'typeName'.
string fluent_name
---
string type

")

(setf (get rosplan_knowledge_msgs::GetRDDLFluentTypeResponse :md5sum-) "8b1465b2af1b2d6bd749f28c18e9cc8e")
(setf (get rosplan_knowledge_msgs::GetRDDLFluentTypeResponse :datatype-) "rosplan_knowledge_msgs/GetRDDLFluentTypeResponse")
(setf (get rosplan_knowledge_msgs::GetRDDLFluentTypeResponse :definition-)
      "# Get all values of the enumeration type with the name 'typeName'.
string fluent_name
---
string type

")



(provide :rosplan_knowledge_msgs/GetRDDLFluentType "8b1465b2af1b2d6bd749f28c18e9cc8e")


