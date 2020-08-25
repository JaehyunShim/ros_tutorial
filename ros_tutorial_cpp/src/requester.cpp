/*
  Filename: requester.cpp
  Author: Ryan Shim
*/

#include <ros/ros.h>
#include "ros_tutorial_cpp/Ask.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "requester");
  ros::NodeHandle nh;
  ros::ServiceClient ask_cli = nh.serviceClient<ros_tutorial_cpp::Ask>("ask");
  ros_tutorial_cpp::Ask ask;
  ask.request.question = "ryan smart?";
  if (ask_cli.call(ask))
  {
    ROS_INFO("Request: %s", ask.request.question.c_str());
    ROS_INFO("Response: %s", ask.response.result.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service ask");
    return 1;
  }
  return 0;
}
