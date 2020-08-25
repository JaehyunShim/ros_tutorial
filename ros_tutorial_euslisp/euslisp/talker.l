#!/usr/bin/env roseus
#|
  Filename: talker.l
  Author: Ryan Shim
|#

(ros::load-ros-manifest "roseus")

(ros::roseus "talker")
(ros::advertise "count" std_msgs::int8 10)
(ros::rate 10) ;; 10Hz
(setq count (instance std_msgs::int8 :init))
(while (ros::ok)
  (ros::ros-info "count: ~d" (send count :data))
  (ros::publish "count" count)
  (ros::sleep)
  (send count :data (+ (send count :data) 1))
  )
  
(ros::roseus "shutdown")
(exit)
