;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::StatusUpdate)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'StatusUpdate (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::STATUSUPDATE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::STATUSUPDATE"))

(in-package "ROS")
;;//! \htmlinclude StatusUpdate.msg.html


(defclass rosplan_knowledge_msgs::StatusUpdate
  :super ros::object
  :slots (_last_update_client _last_update_time ))

(defmethod rosplan_knowledge_msgs::StatusUpdate
  (:init
   (&key
    ((:last_update_client __last_update_client) "")
    ((:last_update_time __last_update_time) (instance ros::time :init))
    )
   (send-super :init)
   (setq _last_update_client (string __last_update_client))
   (setq _last_update_time __last_update_time)
   self)
  (:last_update_client
   (&optional __last_update_client)
   (if __last_update_client (setq _last_update_client __last_update_client)) _last_update_client)
  (:last_update_time
   (&optional __last_update_time)
   (if __last_update_time (setq _last_update_time __last_update_time)) _last_update_time)
  (:serialization-length
   ()
   (+
    ;; string _last_update_client
    4 (length _last_update_client)
    ;; time _last_update_time
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _last_update_client
       (write-long (length _last_update_client) s) (princ _last_update_client s)
     ;; time _last_update_time
       (write-long (send _last_update_time :sec) s) (write-long (send _last_update_time :nsec) s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _last_update_client
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _last_update_client (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; time _last_update_time
     (send _last_update_time :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _last_update_time :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get rosplan_knowledge_msgs::StatusUpdate :md5sum-) "184cadf1052e240c262af1a764339990")
(setf (get rosplan_knowledge_msgs::StatusUpdate :datatype-) "rosplan_knowledge_msgs/StatusUpdate")
(setf (get rosplan_knowledge_msgs::StatusUpdate :definition-)
      "# A message used to publish a status notification from the Knowledge Base
# This status notifies that the KB has been updated.

string last_update_client
time last_update_time


")



(provide :rosplan_knowledge_msgs/StatusUpdate "184cadf1052e240c262af1a764339990")


