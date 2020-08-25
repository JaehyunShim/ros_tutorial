/*
  Filename: listener.cpp
  Author: Ryan Shim
*/

#include <ros/ros.h>
#include <std_msgs/Int8.h>

void countCallback(const std_msgs::Int8::ConstPtr& msg)
{
  ROS_INFO("count: %d", msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;
  ros::Subscriber count_sub = nh.subscribe("count", 10, countCallback);
  ros::spin();
  return 0;
}
