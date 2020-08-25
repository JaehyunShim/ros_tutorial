#!/usr/bin/env python
'''
  Filename: responsor.py
  Author: Ryan Shim
'''

import rospy
from ros_tutorial_cpp.srv import Ask, AskResponse

def ask_callback(req):
    res = AskResponse()
    if req.question == "ryan smart?":
        res.result = "yes"
    else:
        res.result = "another question?"

    print "Requesting: %s"%req.question
    print "Response: %s"%res.result
    return res

def responsor():
    rospy.init_node('responsor')
    ask_ser = rospy.Service('ask', Ask, ask_callback)
    print "Ready to receive request"
    rospy.spin()

if __name__ == "__main__":
    responsor()
