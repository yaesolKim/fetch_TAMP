;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::SetNamedBool)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'SetNamedBool (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETNAMEDBOOL")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETNAMEDBOOL"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETNAMEDBOOLREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETNAMEDBOOLREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::SETNAMEDBOOLRESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::SETNAMEDBOOLRESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::SetNamedBoolRequest
  :super ros::object
  :slots (_name _value ))

(defmethod rosplan_knowledge_msgs::SetNamedBoolRequest
  (:init
   (&key
    ((:name __name) "")
    ((:value __value) nil)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _value __value)
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; bool _value
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; bool _value
       (if _value (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _value
     (setq _value (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::SetNamedBoolResponse
  :super ros::object
  :slots (_success ))

(defmethod rosplan_knowledge_msgs::SetNamedBoolResponse
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

(defclass rosplan_knowledge_msgs::SetNamedBool
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::SetNamedBool :md5sum-) "c7f243f8c6655aded1b4e1f571c7cee3")
(setf (get rosplan_knowledge_msgs::SetNamedBool :datatype-) "rosplan_knowledge_msgs/SetNamedBool")
(setf (get rosplan_knowledge_msgs::SetNamedBool :request) rosplan_knowledge_msgs::SetNamedBoolRequest)
(setf (get rosplan_knowledge_msgs::SetNamedBool :response) rosplan_knowledge_msgs::SetNamedBoolResponse)

(defmethod rosplan_knowledge_msgs::SetNamedBoolRequest
  (:response () (instance rosplan_knowledge_msgs::SetNamedBoolResponse :init)))

(setf (get rosplan_knowledge_msgs::SetNamedBoolRequest :md5sum-) "c7f243f8c6655aded1b4e1f571c7cee3")
(setf (get rosplan_knowledge_msgs::SetNamedBoolRequest :datatype-) "rosplan_knowledge_msgs/SetNamedBoolRequest")
(setf (get rosplan_knowledge_msgs::SetNamedBoolRequest :definition-)
      "string name
bool value
---
bool success

")

(setf (get rosplan_knowledge_msgs::SetNamedBoolResponse :md5sum-) "c7f243f8c6655aded1b4e1f571c7cee3")
(setf (get rosplan_knowledge_msgs::SetNamedBoolResponse :datatype-) "rosplan_knowledge_msgs/SetNamedBoolResponse")
(setf (get rosplan_knowledge_msgs::SetNamedBoolResponse :definition-)
      "string name
bool value
---
bool success

")



(provide :rosplan_knowledge_msgs/SetNamedBool "c7f243f8c6655aded1b4e1f571c7cee3")


