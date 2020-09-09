;; Auto-generated. Do not edit!


(when (boundp 'rosplan_dispatch_msgs::DispatchService)
  (if (not (find-package "ROSPLAN_DISPATCH_MSGS"))
    (make-package "ROSPLAN_DISPATCH_MSGS"))
  (shadow 'DispatchService (find-package "ROSPLAN_DISPATCH_MSGS")))
(unless (find-package "ROSPLAN_DISPATCH_MSGS::DISPATCHSERVICE")
  (make-package "ROSPLAN_DISPATCH_MSGS::DISPATCHSERVICE"))
(unless (find-package "ROSPLAN_DISPATCH_MSGS::DISPATCHSERVICEREQUEST")
  (make-package "ROSPLAN_DISPATCH_MSGS::DISPATCHSERVICEREQUEST"))
(unless (find-package "ROSPLAN_DISPATCH_MSGS::DISPATCHSERVICERESPONSE")
  (make-package "ROSPLAN_DISPATCH_MSGS::DISPATCHSERVICERESPONSE"))

(in-package "ROS")





(defclass rosplan_dispatch_msgs::DispatchServiceRequest
  :super ros::object
  :slots ())

(defmethod rosplan_dispatch_msgs::DispatchServiceRequest
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

(defclass rosplan_dispatch_msgs::DispatchServiceResponse
  :super ros::object
  :slots (_success _goal_achieved ))

(defmethod rosplan_dispatch_msgs::DispatchServiceResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:goal_achieved __goal_achieved) nil)
    )
   (send-super :init)
   (setq _success __success)
   (setq _goal_achieved __goal_achieved)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:goal_achieved
   (&optional __goal_achieved)
   (if __goal_achieved (setq _goal_achieved __goal_achieved)) _goal_achieved)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; bool _goal_achieved
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; bool _goal_achieved
       (if _goal_achieved (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _goal_achieved
     (setq _goal_achieved (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass rosplan_dispatch_msgs::DispatchService
  :super ros::object
  :slots ())

(setf (get rosplan_dispatch_msgs::DispatchService :md5sum-) "7e14a3412cb82ba736fcf0fad2853ed3")
(setf (get rosplan_dispatch_msgs::DispatchService :datatype-) "rosplan_dispatch_msgs/DispatchService")
(setf (get rosplan_dispatch_msgs::DispatchService :request) rosplan_dispatch_msgs::DispatchServiceRequest)
(setf (get rosplan_dispatch_msgs::DispatchService :response) rosplan_dispatch_msgs::DispatchServiceResponse)

(defmethod rosplan_dispatch_msgs::DispatchServiceRequest
  (:response () (instance rosplan_dispatch_msgs::DispatchServiceResponse :init)))

(setf (get rosplan_dispatch_msgs::DispatchServiceRequest :md5sum-) "7e14a3412cb82ba736fcf0fad2853ed3")
(setf (get rosplan_dispatch_msgs::DispatchServiceRequest :datatype-) "rosplan_dispatch_msgs/DispatchServiceRequest")
(setf (get rosplan_dispatch_msgs::DispatchServiceRequest :definition-)
      "---
bool success # True if the dispatch was successful
bool goal_achieved # True if the goal is achieved after the dispatching

")

(setf (get rosplan_dispatch_msgs::DispatchServiceResponse :md5sum-) "7e14a3412cb82ba736fcf0fad2853ed3")
(setf (get rosplan_dispatch_msgs::DispatchServiceResponse :datatype-) "rosplan_dispatch_msgs/DispatchServiceResponse")
(setf (get rosplan_dispatch_msgs::DispatchServiceResponse :definition-)
      "---
bool success # True if the dispatch was successful
bool goal_achieved # True if the goal is achieved after the dispatching

")



(provide :rosplan_dispatch_msgs/DispatchService "7e14a3412cb82ba736fcf0fad2853ed3")


