;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::SetFloat)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'SetFloat (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETFLOAT")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETFLOAT"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETFLOATREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETFLOATREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETFLOATRESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETFLOATRESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::SetFloatRequest
  :super ros::object
  :slots (_value ))

(defmethod rosplan_knowledge_msgs::SetFloatRequest
  (:init
   (&key
    ((:value __value) 0.0)
    )
   (send-super :init)
   (setq _value (float __value))
   self)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; float32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _value
       (sys::poke _value (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _value
     (setq _value (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::SetFloatResponse
  :super ros::object
  :slots (_success ))

(defmethod rosplan_knowledge_msgs::SetFloatResponse
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

(defclass rosplan_knowledge_msgs::SetFloat
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::SetFloat :md5sum-) "47e426851263ec40954663841ebdb36b")
(setf (get rosplan_knowledge_msgs::SetFloat :datatype-) "rosplan_knowledge_msgs/SetFloat")
(setf (get rosplan_knowledge_msgs::SetFloat :request) rosplan_knowledge_msgs::SetFloatRequest)
(setf (get rosplan_knowledge_msgs::SetFloat :response) rosplan_knowledge_msgs::SetFloatResponse)

(defmethod rosplan_knowledge_msgs::SetFloatRequest
  (:response () (instance rosplan_knowledge_msgs::SetFloatResponse :init)))

(setf (get rosplan_knowledge_msgs::SetFloatRequest :md5sum-) "47e426851263ec40954663841ebdb36b")
(setf (get rosplan_knowledge_msgs::SetFloatRequest :datatype-) "rosplan_knowledge_msgs/SetFloatRequest")
(setf (get rosplan_knowledge_msgs::SetFloatRequest :definition-)
      "float32 value
---
bool success

")

(setf (get rosplan_knowledge_msgs::SetFloatResponse :md5sum-) "47e426851263ec40954663841ebdb36b")
(setf (get rosplan_knowledge_msgs::SetFloatResponse :datatype-) "rosplan_knowledge_msgs/SetFloatResponse")
(setf (get rosplan_knowledge_msgs::SetFloatResponse :definition-)
      "float32 value
---
bool success

")



(provide :rosplan_knowledge_msgs/SetFloat "47e426851263ec40954663841ebdb36b")


