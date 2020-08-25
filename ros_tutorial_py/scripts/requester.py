#!/usr/bin/env python
'''
  Filename: requester.py
  Author: Ryan Shim
'''

import rospy
from ros_tutorial_py.srv import Ask, AskRequest

def client():
    rospy.wait_for_service('ask')
    try:
        ask_cli = rospy.ServiceProxy('ask', Ask)
        req = AskRequest()
        req.question = "ryan smart?"
        res = ask_cli(req)
        print "Requesting: %s"%req.question
        print "Response: %s"%res.result
    except rospy.ServiceException, e:
        print "Failed to call service ask: %s"%e

if __name__ == "__main__":
    client()
