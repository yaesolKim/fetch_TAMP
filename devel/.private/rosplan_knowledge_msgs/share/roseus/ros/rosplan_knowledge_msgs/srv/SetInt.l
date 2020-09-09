;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::SetInt)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'SetInt (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETINT")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETINT"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETINTREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETINTREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETINTRESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETINTRESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::SetIntRequest
  :super ros::object
  :slots (_value ))

(defmethod rosplan_knowledge_msgs::SetIntRequest
  (:init
   (&key
    ((:value __value) 0)
    )
   (send-super :init)
   (setq _value (round __value))
   self)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; int32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _value
       (write-long _value s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _value
     (setq _value (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::SetIntResponse
  :super ros::object
  :slots (_success ))

(defmethod rosplan_knowledge_msgs::SetIntResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::SetInt
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::SetInt :md5sum-) "bc437afb45673379bdb9f299f9cbbc9e")
(setf (get rosplan_knowledge_msgs::SetInt :datatype-) "rosplan_knowledge_msgs/SetInt")
(setf (get rosplan_knowledge_msgs::SetInt :request) rosplan_knowledge_msgs::SetIntRequest)
(setf (get rosplan_knowledge_msgs::SetInt :response) rosplan_knowledge_msgs::SetIntResponse)

(defmethod rosplan_knowledge_msgs::SetIntRequest
  (:response () (instance rosplan_knowledge_msgs::SetIntResponse :init)))

(setf (get rosplan_knowledge_msgs::SetIntRequest :md5sum-) "bc437afb45673379bdb9f299f9cbbc9e")
(setf (get rosplan_knowledge_msgs::SetIntRequest :datatype-) "rosplan_knowledge_msgs/SetIntRequest")
(setf (get rosplan_knowledge_msgs::SetIntRequest :definition-)
      "int32 value
---
bool success

")

(setf (get rosplan_knowledge_msgs::SetIntResponse :md5sum-) "bc437afb45673379bdb9f299f9cbbc9e")
(setf (get rosplan_knowledge_msgs::SetIntResponse :datatype-) "rosplan_knowledge_msgs/SetIntResponse")
(setf (get rosplan_knowledge_msgs::SetIntResponse :definition-)
      "int32 value
---
bool success

")



(provide :rosplan_knowledge_msgs/SetInt "bc437afb45673379bdb9f299f9cbbc9e")


