;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::ReloadRDDLDomainProblem)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'ReloadRDDLDomainProblem (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::RELOADRDDLDOMAINPROBLEM")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::RELOADRDDLDOMAINPROBLEM"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::RELOADRDDLDOMAINPROBLEMREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::RELOADRDDLDOMAINPROBLEMREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::RELOADRDDLDOMAINPROBLEMRESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::RELOADRDDLDOMAINPROBLEMRESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::ReloadRDDLDomainProblemRequest
  :super ros::object
  :slots (_problem_path ))

(defmethod rosplan_knowledge_msgs::ReloadRDDLDomainProblemRequest
  (:init
   (&key
    ((:problem_path __problem_path) "")
    )
   (send-super :init)
   (setq _problem_path (string __problem_path))
   self)
  (:problem_path
   (&optional __problem_path)
   (if __problem_path (setq _problem_path __problem_path)) _problem_path)
  (:serialization-length
   ()
   (+
    ;; string _problem_path
    4 (length _problem_path)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _problem_path
       (write-long (length _problem_path) s) (princ _problem_path s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _problem_path
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _problem_path (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::ReloadRDDLDomainProblemResponse
  :super ros::object
  :slots (_success ))

(defmethod rosplan_knowledge_msgs::ReloadRDDLDomainProblemResponse
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

(defclass rosplan_knowledge_msgs::ReloadRDDLDomainProblem
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblem :md5sum-) "46f5005f9ac31164db24c532bfe60e3b")
(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblem :datatype-) "rosplan_knowledge_msgs/ReloadRDDLDomainProblem")
(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblem :request) rosplan_knowledge_msgs::ReloadRDDLDomainProblemRequest)
(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblem :response) rosplan_knowledge_msgs::ReloadRDDLDomainProblemResponse)

(defmethod rosplan_knowledge_msgs::ReloadRDDLDomainProblemRequest
  (:response () (instance rosplan_knowledge_msgs::ReloadRDDLDomainProblemResponse :init)))

(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblemRequest :md5sum-) "46f5005f9ac31164db24c532bfe60e3b")
(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblemRequest :datatype-) "rosplan_knowledge_msgs/ReloadRDDLDomainProblemRequest")
(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblemRequest :definition-)
      "string problem_path
---
bool success

")

(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblemResponse :md5sum-) "46f5005f9ac31164db24c532bfe60e3b")
(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblemResponse :datatype-) "rosplan_knowledge_msgs/ReloadRDDLDomainProblemResponse")
(setf (get rosplan_knowledge_msgs::ReloadRDDLDomainProblemResponse :definition-)
      "string problem_path
---
bool success

")



(provide :rosplan_knowledge_msgs/ReloadRDDLDomainProblem "46f5005f9ac31164db24c532bfe60e3b")


