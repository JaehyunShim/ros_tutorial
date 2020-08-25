/*
  Filename: test_node.cpp
  Author: Ryan Shim
*/

#include <gtest/gtest.h>

#include <ros/ros.h>

TEST(TestSuite, initTest)
{
  ASSERT_TRUE(true);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
