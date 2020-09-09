;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::GetRDDLParams)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'GetRDDLParams (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLPARAMS")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLPARAMS"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLPARAMSREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLPARAMSREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLPARAMSRESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLPARAMSRESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::GetRDDLParamsRequest
  :super ros::object
  :slots ())

(defmethod rosplan_knowledge_msgs::GetRDDLParamsRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetRDDLParamsResponse
  :super ros::object
  :slots (_horizon _discount_factor _max_nondef_actions ))

(defmethod rosplan_knowledge_msgs::GetRDDLParamsResponse
  (:init
   (&key
    ((:horizon __horizon) 0)
    ((:discount_factor __discount_factor) 0.0)
    ((:max_nondef_actions __max_nondef_actions) 0)
    )
   (send-super :init)
   (setq _horizon (round __horizon))
   (setq _discount_factor (float __discount_factor))
   (setq _max_nondef_actions (round __max_nondef_actions))
   self)
  (:horizon
   (&optional __horizon)
   (if __horizon (setq _horizon __horizon)) _horizon)
  (:discount_factor
   (&optional __discount_factor)
   (if __discount_factor (setq _discount_factor __discount_factor)) _discount_factor)
  (:max_nondef_actions
   (&optional __max_nondef_actions)
   (if __max_nondef_actions (setq _max_nondef_actions __max_nondef_actions)) _max_nondef_actions)
  (:serialization-length
   ()
   (+
    ;; int32 _horizon
    4
    ;; float32 _discount_factor
    4
    ;; int32 _max_nondef_actions
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _horizon
       (write-long _horizon s)
     ;; float32 _discount_factor
       (sys::poke _discount_factor (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _max_nondef_actions
       (write-long _max_nondef_actions s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _horizon
     (setq _horizon (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _discount_factor
     (setq _discount_factor (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _max_nondef_actions
     (setq _max_nondef_actions (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetRDDLParams
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::GetRDDLParams :md5sum-) "0cf0ef8b4c4b342e8f951535dfe54dba")
(setf (get rosplan_knowledge_msgs::GetRDDLParams :datatype-) "rosplan_knowledge_msgs/GetRDDLParams")
(setf (get rosplan_knowledge_msgs::GetRDDLParams :request) rosplan_knowledge_msgs::GetRDDLParamsRequest)
(setf (get rosplan_knowledge_msgs::GetRDDLParams :response) rosplan_knowledge_msgs::GetRDDLParamsResponse)

(defmethod rosplan_knowledge_msgs::GetRDDLParamsRequest
  (:response () (instance rosplan_knowledge_msgs::GetRDDLParamsResponse :init)))

(setf (get rosplan_knowledge_msgs::GetRDDLParamsRequest :md5sum-) "0cf0ef8b4c4b342e8f951535dfe54dba")
(setf (get rosplan_knowledge_msgs::GetRDDLParamsRequest :datatype-) "rosplan_knowledge_msgs/GetRDDLParamsRequest")
(setf (get rosplan_knowledge_msgs::GetRDDLParamsRequest :definition-)
      "---
int32 horizon
float32 discount_factor
int32 max_nondef_actions


")

(setf (get rosplan_knowledge_msgs::GetRDDLParamsResponse :md5sum-) "0cf0ef8b4c4b342e8f951535dfe54dba")
(setf (get rosplan_knowledge_msgs::GetRDDLParamsResponse :datatype-) "rosplan_knowledge_msgs/GetRDDLParamsResponse")
(setf (get rosplan_knowledge_msgs::GetRDDLParamsResponse :definition-)
      "---
int32 horizon
float32 discount_factor
int32 max_nondef_actions


")



(provide :rosplan_knowledge_msgs/GetRDDLParams "0cf0ef8b4c4b342e8f951535dfe54dba")


