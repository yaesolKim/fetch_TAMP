;; Auto-generated. Do not edit!


(when (boundp 'rosplan_interface_mapping::RemoveWaypoint)
  (if (not (find-package "ROSPLAN_INTERFACE_MAPPING"))
    (make-package "ROSPLAN_INTERFACE_MAPPING"))
  (shadow 'RemoveWaypoint (find-package "ROSPLAN_INTERFACE_MAPPING")))
(unless (find-package "ROSPLAN_INTERFACE_MAPPING::REMOVEWAYPOINT")
  (make-package "ROSPLAN_INTERFACE_MAPPING::REMOVEWAYPOINT"))
(unless (find-package "ROSPLAN_INTERFACE_MAPPING::REMOVEWAYPOINTREQUEST")
  (make-package "ROSPLAN_INTERFACE_MAPPING::REMOVEWAYPOINTREQUEST"))
(unless (find-package "ROSPLAN_INTERFACE_MAPPING::REMOVEWAYPOINTRESPONSE")
  (make-package "ROSPLAN_INTERFACE_MAPPING::REMOVEWAYPOINTRESPONSE"))

(in-package "ROS")





(defclass rosplan_interface_mapping::RemoveWaypointRequest
  :super ros::object
  :slots (_id ))

(defmethod rosplan_interface_mapping::RemoveWaypointRequest
  (:init
   (&key
    ((:id __id) "")
    )
   (send-super :init)
   (setq _id (string __id))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; string _id
    4 (length _id)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _id
       (write-long (length _id) s) (princ _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass rosplan_interface_mapping::RemoveWaypointResponse
  :super ros::object
  :slots ())

(defmethod rosplan_interface_mapping::RemoveWaypointResponse
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

(defclass rosplan_interface_mapping::RemoveWaypoint
  :super ros::object
  :slots ())

(setf (get rosplan_interface_mapping::RemoveWaypoint :md5sum-) "bbfcda76036ebbe3d36caf7af80b260c")
(setf (get rosplan_interface_mapping::RemoveWaypoint :datatype-) "rosplan_interface_mapping/RemoveWaypoint")
(setf (get rosplan_interface_mapping::RemoveWaypoint :request) rosplan_interface_mapping::RemoveWaypointRequest)
(setf (get rosplan_interface_mapping::RemoveWaypoint :response) rosplan_interface_mapping::RemoveWaypointResponse)

(defmethod rosplan_interface_mapping::RemoveWaypointRequest
  (:response () (instance rosplan_interface_mapping::RemoveWaypointResponse :init)))

(setf (get rosplan_interface_mapping::RemoveWaypointRequest :md5sum-) "bbfcda76036ebbe3d36caf7af80b260c")
(setf (get rosplan_interface_mapping::RemoveWaypointRequest :datatype-) "rosplan_interface_mapping/RemoveWaypointRequest")
(setf (get rosplan_interface_mapping::RemoveWaypointRequest :definition-)
      "string id
---


")

(setf (get rosplan_interface_mapping::RemoveWaypointResponse :md5sum-) "bbfcda76036ebbe3d36caf7af80b260c")
(setf (get rosplan_interface_mapping::RemoveWaypointResponse :datatype-) "rosplan_interface_mapping/RemoveWaypointResponse")
(setf (get rosplan_interface_mapping::RemoveWaypointResponse :definition-)
      "string id
---


")



(provide :rosplan_interface_mapping/RemoveWaypoint "bbfcda76036ebbe3d36caf7af80b260c")


