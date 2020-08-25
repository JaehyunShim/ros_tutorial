/*
  Filename: talker.cpp
  Author: Ryan Shim
*/

#include <ros/ros.h>
#include <std_msgs/Int8.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;
  ros::Publisher count_pub = nh.advertise<std_msgs::Int8>("count", 10);
  ros::Rate rate(10); // 10Hz
  std_msgs::Int8 count;
  count.data = 0;
  while (ros::ok())
  {
    ROS_INFO("count: %d", count.data);
    count_pub.publish(count);
    ros::spinOnce();
    rate.sleep();
    count.data++;
  }
  return 0;
}
