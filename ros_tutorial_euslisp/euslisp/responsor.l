#!/usr/bin/env roseus
#|
  Filename: responsor.l
  Author: Ryan Shim
|#

(ros::load-ros-manifest "roseus")
(ros::load-ros-manifest "ros_tutorial_euslisp")

(defun ask-callback (req)
  (let ((res (send req :response)))
    (if (equal (send req :question) "ryan smart?")
        (send res :result "yes")
      (send res :result "another question?"))
    (ros::ros-info "Request: ~A" (send req :question))
    (ros::ros-info "Response: ~A" (send res :result))
    res))

(ros::roseus "responsor")
(ros::advertise-service "ask" ros_tutorial_euslisp::Ask #'ask-callback)
(ros::spin)
