;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::GetRDDLImmediateReward)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'GetRDDLImmediateReward (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLIMMEDIATEREWARD")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLIMMEDIATEREWARD"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLIMMEDIATEREWARDREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLIMMEDIATEREWARDREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLIMMEDIATEREWARDRESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETRDDLIMMEDIATEREWARDRESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass rosplan_knowledge_msgs::GetRDDLImmediateRewardRequest
  :super ros::object
  :slots (_action ))

(defmethod rosplan_knowledge_msgs::GetRDDLImmediateRewardRequest
  (:init
   (&key
    ((:action __action) (let (r) (dotimes (i 0) (push (instance std_msgs::String :init) r)) r))
    )
   (send-super :init)
   (setq _action __action)
   self)
  (:action
   (&rest __action)
   (if (keywordp (car __action))
       (send* _action __action)
     (progn
       (if __action (setq _action (car __action)))
       _action)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/String[] _action
    (apply #'+ (send-all _action :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/String[] _action
     (write-long (length _action) s)
     (dolist (elem _action)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/String[] _action
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _action (let (r) (dotimes (i n) (push (instance std_msgs::String :init) r)) r))
     (dolist (elem- _action)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetRDDLImmediateRewardResponse
  :super ros::object
  :slots (_reward ))

(defmethod rosplan_knowledge_msgs::GetRDDLImmediateRewardResponse
  (:init
   (&key
    ((:reward __reward) 0.0)
    )
   (send-super :init)
   (setq _reward (float __reward))
   self)
  (:reward
   (&optional __reward)
   (if __reward (setq _reward __reward)) _reward)
  (:serialization-length
   ()
   (+
    ;; float64 _reward
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _reward
       (sys::poke _reward (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _reward
     (setq _reward (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetRDDLImmediateReward
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::GetRDDLImmediateReward :md5sum-) "837ccfec14d9d69a332bf7294d27c502")
(setf (get rosplan_knowledge_msgs::GetRDDLImmediateReward :datatype-) "rosplan_knowledge_msgs/GetRDDLImmediateReward")
(setf (get rosplan_knowledge_msgs::GetRDDLImmediateReward :request) rosplan_knowledge_msgs::GetRDDLImmediateRewardRequest)
(setf (get rosplan_knowledge_msgs::GetRDDLImmediateReward :response) rosplan_knowledge_msgs::GetRDDLImmediateRewardResponse)

(defmethod rosplan_knowledge_msgs::GetRDDLImmediateRewardRequest
  (:response () (instance rosplan_knowledge_msgs::GetRDDLImmediateRewardResponse :init)))

(setf (get rosplan_knowledge_msgs::GetRDDLImmediateRewardRequest :md5sum-) "837ccfec14d9d69a332bf7294d27c502")
(setf (get rosplan_knowledge_msgs::GetRDDLImmediateRewardRequest :datatype-) "rosplan_knowledge_msgs/GetRDDLImmediateRewardRequest")
(setf (get rosplan_knowledge_msgs::GetRDDLImmediateRewardRequest :definition-)
      "std_msgs/String[] action # Instantiated actions in the last timestep (i.e. goto_Waypoint(kenny, printer)

================================================================================
MSG: std_msgs/String
string data
---
float64 reward

")

(setf (get rosplan_knowledge_msgs::GetRDDLImmediateRewardResponse :md5sum-) "837ccfec14d9d69a332bf7294d27c502")
(setf (get rosplan_knowledge_msgs::GetRDDLImmediateRewardResponse :datatype-) "rosplan_knowledge_msgs/GetRDDLImmediateRewardResponse")
(setf (get rosplan_knowledge_msgs::GetRDDLImmediateRewardResponse :definition-)
      "std_msgs/String[] action # Instantiated actions in the last timestep (i.e. goto_Waypoint(kenny, printer)

================================================================================
MSG: std_msgs/String
string data
---
float64 reward

")



(provide :rosplan_knowledge_msgs/GetRDDLImmediateReward "837ccfec14d9d69a332bf7294d27c502")


