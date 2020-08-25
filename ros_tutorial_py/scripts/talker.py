#!/usr/bin/env python
'''
  Filename: talker.py
  Author: Ryan Shim
'''

import rospy
from std_msgs.msg import Int8

def talker():
    rospy.init_node('talker', anonymous=True)
    count_pub = rospy.Publisher('count', Int8, queue_size=10)
    rate = rospy.Rate(10) # 10Hz
    count = Int8()
    count.data = 0
    while not rospy.is_shutdown():
        rospy.loginfo("count: %d", count.data)
        count_pub.publish(count)
        rate.sleep()
        count.data += 1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
