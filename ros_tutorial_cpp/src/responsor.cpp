/*
  Filename: responsor.cpp
  Author: Ryan Shim
*/

#include <ros/ros.h>
#include "ros_tutorial_cpp/Ask.h"

bool askCallback(ros_tutorial_cpp::Ask::Request  &req,
                 ros_tutorial_cpp::Ask::Response &res)
{
  if (!req.question.compare("ryan smart?"))
    res.result = "yes";
  else
    res.result = "another question?";
    
  ROS_INFO("Request: %s", req.question.c_str());
  ROS_INFO("Response: %s", res.result.c_str());
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "responsor");
  ros::NodeHandle nh;
  ros::ServiceServer ask_ser = nh.advertiseService("ask", askCallback);
  ROS_INFO("Ready to receive request");
  ros::spin();
  return 0;
}
