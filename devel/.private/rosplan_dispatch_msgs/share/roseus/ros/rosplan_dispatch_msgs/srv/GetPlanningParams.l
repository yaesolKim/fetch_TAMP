;; Auto-generated. Do not edit!


(when (boundp 'rosplan_dispatch_msgs::GetPlanningParams)
  (if (not (find-package "ROSPLAN_DISPATCH_MSGS"))
    (make-package "ROSPLAN_DISPATCH_MSGS"))
  (shadow 'GetPlanningParams (find-package "ROSPLAN_DISPATCH_MSGS")))
(unless (find-package "ROSPLAN_DISPATCH_MSGS::GETPLANNINGPARAMS")
  (make-package "ROSPLAN_DISPATCH_MSGS::GETPLANNINGPARAMS"))
(unless (find-package "ROSPLAN_DISPATCH_MSGS::GETPLANNINGPARAMSREQUEST")
  (make-package "ROSPLAN_DISPATCH_MSGS::GETPLANNINGPARAMSREQUEST"))
(unless (find-package "ROSPLAN_DISPATCH_MSGS::GETPLANNINGPARAMSRESPONSE")
  (make-package "ROSPLAN_DISPATCH_MSGS::GETPLANNINGPARAMSRESPONSE"))

(in-package "ROS")





(defclass rosplan_dispatch_msgs::GetPlanningParamsRequest
  :super ros::object
  :slots ())

(defmethod rosplan_dispatch_msgs::GetPlanningParamsRequest
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

(defclass rosplan_dispatch_msgs::GetPlanningParamsResponse
  :super ros::object
  :slots (_domain_path _problem_path _planner_ready ))

(defmethod rosplan_dispatch_msgs::GetPlanningParamsResponse
  (:init
   (&key
    ((:domain_path __domain_path) "")
    ((:problem_path __problem_path) "")
    ((:planner_ready __planner_ready) nil)
    )
   (send-super :init)
   (setq _domain_path (string __domain_path))
   (setq _problem_path (string __problem_path))
   (setq _planner_ready __planner_ready)
   self)
  (:domain_path
   (&optional __domain_path)
   (if __domain_path (setq _domain_path __domain_path)) _domain_path)
  (:problem_path
   (&optional __problem_path)
   (if __problem_path (setq _problem_path __problem_path)) _problem_path)
  (:planner_ready
   (&optional __planner_ready)
   (if __planner_ready (setq _planner_ready __planner_ready)) _planner_ready)
  (:serialization-length
   ()
   (+
    ;; string _domain_path
    4 (length _domain_path)
    ;; string _problem_path
    4 (length _problem_path)
    ;; bool _planner_ready
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _domain_path
       (write-long (length _domain_path) s) (princ _domain_path s)
     ;; string _problem_path
       (write-long (length _problem_path) s) (princ _problem_path s)
     ;; bool _planner_ready
       (if _planner_ready (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _domain_path
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _domain_path (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _problem_path
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _problem_path (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _planner_ready
     (setq _planner_ready (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass rosplan_dispatch_msgs::GetPlanningParams
  :super ros::object
  :slots ())

(setf (get rosplan_dispatch_msgs::GetPlanningParams :md5sum-) "b809da7a1aeeaa475218aad83ae1b3c4")
(setf (get rosplan_dispatch_msgs::GetPlanningParams :datatype-) "rosplan_dispatch_msgs/GetPlanningParams")
(setf (get rosplan_dispatch_msgs::GetPlanningParams :request) rosplan_dispatch_msgs::GetPlanningParamsRequest)
(setf (get rosplan_dispatch_msgs::GetPlanningParams :response) rosplan_dispatch_msgs::GetPlanningParamsResponse)

(defmethod rosplan_dispatch_msgs::GetPlanningParamsRequest
  (:response () (instance rosplan_dispatch_msgs::GetPlanningParamsResponse :init)))

(setf (get rosplan_dispatch_msgs::GetPlanningParamsRequest :md5sum-) "b809da7a1aeeaa475218aad83ae1b3c4")
(setf (get rosplan_dispatch_msgs::GetPlanningParamsRequest :datatype-) "rosplan_dispatch_msgs/GetPlanningParamsRequest")
(setf (get rosplan_dispatch_msgs::GetPlanningParamsRequest :definition-)
      "---
string domain_path
string problem_path
bool planner_ready # True if the planner thread is started

")

(setf (get rosplan_dispatch_msgs::GetPlanningParamsResponse :md5sum-) "b809da7a1aeeaa475218aad83ae1b3c4")
(setf (get rosplan_dispatch_msgs::GetPlanningParamsResponse :datatype-) "rosplan_dispatch_msgs/GetPlanningParamsResponse")
(setf (get rosplan_dispatch_msgs::GetPlanningParamsResponse :definition-)
      "---
string domain_path
string problem_path
bool planner_ready # True if the planner thread is started

")



(provide :rosplan_dispatch_msgs/GetPlanningParams "b809da7a1aeeaa475218aad83ae1b3c4")


