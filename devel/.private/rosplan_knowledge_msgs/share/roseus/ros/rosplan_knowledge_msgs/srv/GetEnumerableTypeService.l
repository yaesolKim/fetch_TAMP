;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::GetEnumerableTypeService)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'GetEnumerableTypeService (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETENUMERABLETYPESERVICE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETENUMERABLETYPESERVICE"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETENUMERABLETYPESERVICEREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETENUMERABLETYPESERVICEREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETENUMERABLETYPESERVICERESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETENUMERABLETYPESERVICERESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::GetEnumerableTypeServiceRequest
  :super ros::object
  :slots (_type_name ))

(defmethod rosplan_knowledge_msgs::GetEnumerableTypeServiceRequest
  (:init
   (&key
    ((:type_name __type_name) "")
    )
   (send-super :init)
   (setq _type_name (string __type_name))
   self)
  (:type_name
   (&optional __type_name)
   (if __type_name (setq _type_name __type_name)) _type_name)
  (:serialization-length
   ()
   (+
    ;; string _type_name
    4 (length _type_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _type_name
       (write-long (length _type_name) s) (princ _type_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _type_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _type_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetEnumerableTypeServiceResponse
  :super ros::object
  :slots (_values ))

(defmethod rosplan_knowledge_msgs::GetEnumerableTypeServiceResponse
  (:init
   (&key
    ((:values __values) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _values __values)
   self)
  (:values
   (&optional __values)
   (if __values (setq _values __values)) _values)
  (:serialization-length
   ()
   (+
    ;; string[] _values
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _values)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string[] _values
     (write-long (length _values) s)
     (dolist (elem _values)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string[] _values
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _values (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _values i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetEnumerableTypeService
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::GetEnumerableTypeService :md5sum-) "620e0db27dedf37a3e89c5aaa3324d1b")
(setf (get rosplan_knowledge_msgs::GetEnumerableTypeService :datatype-) "rosplan_knowledge_msgs/GetEnumerableTypeService")
(setf (get rosplan_knowledge_msgs::GetEnumerableTypeService :request) rosplan_knowledge_msgs::GetEnumerableTypeServiceRequest)
(setf (get rosplan_knowledge_msgs::GetEnumerableTypeService :response) rosplan_knowledge_msgs::GetEnumerableTypeServiceResponse)

(defmethod rosplan_knowledge_msgs::GetEnumerableTypeServiceRequest
  (:response () (instance rosplan_knowledge_msgs::GetEnumerableTypeServiceResponse :init)))

(setf (get rosplan_knowledge_msgs::GetEnumerableTypeServiceRequest :md5sum-) "620e0db27dedf37a3e89c5aaa3324d1b")
(setf (get rosplan_knowledge_msgs::GetEnumerableTypeServiceRequest :datatype-) "rosplan_knowledge_msgs/GetEnumerableTypeServiceRequest")
(setf (get rosplan_knowledge_msgs::GetEnumerableTypeServiceRequest :definition-)
      "# Get all values of the enumeration type with the name 'typeName'.
string type_name
---
string[] values

")

(setf (get rosplan_knowledge_msgs::GetEnumerableTypeServiceResponse :md5sum-) "620e0db27dedf37a3e89c5aaa3324d1b")
(setf (get rosplan_knowledge_msgs::GetEnumerableTypeServiceResponse :datatype-) "rosplan_knowledge_msgs/GetEnumerableTypeServiceResponse")
(setf (get rosplan_knowledge_msgs::GetEnumerableTypeServiceResponse :definition-)
      "# Get all values of the enumeration type with the name 'typeName'.
string type_name
---
string[] values

")



(provide :rosplan_knowledge_msgs/GetEnumerableTypeService "620e0db27dedf37a3e89c5aaa3324d1b")


