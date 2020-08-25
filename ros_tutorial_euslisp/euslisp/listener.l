#!/usr/bin/env roseus
#|
  Filename: listener.l
  Author: Ryan Shim
|#

(ros::load-ros-manifest "roseus")

(defun count-callback (msg) 
  (ros::ros-info "count: ~d" (send msg :data)))

(ros::roseus "listener" :anonymous t)
(ros::subscribe "count" std_msgs::int8 #'count-callback)
(ros::spin)
