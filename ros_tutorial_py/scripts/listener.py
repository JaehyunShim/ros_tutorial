#!/usr/bin/env python
'''
  Filename: listener.py
  Author: Ryan Shim
'''

import rospy
from std_msgs.msg import Int8

def count_callback(msg):
    rospy.loginfo("count: %d", msg.data)
    
def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('count', Int8, count_callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
