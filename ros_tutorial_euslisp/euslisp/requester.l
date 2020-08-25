#!/usr/bin/env roseus
#|
  Filename: requester.l
  Author: Ryan Shim
|#

(ros::load-ros-manifest "roseus")
(ros::load-ros-manifest "ros_tutorial_euslisp")

(ros::roseus "requester")
(ros::wait-for-service "ask")
(setq req (instance ros_tutorial_euslisp::AskRequest :init))
(send req :question "ryan smart?")
(setq res (ros::service-call "ask" req))
(ros::ros-info "Request: ~A" (send req :question))
(ros::ros-info "Response: ~A" (send res :result))
