################################################################################
# Set minimum required version of cmake, project name and compile options
################################################################################
cmake_minimum_required(VERSION 2.8.3)
project(ros_tutorial_cpp)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

################################################################################
# Find catkin packages and libraries for catkin and system dependencies
################################################################################
find_package(
  catkin REQUIRED
  COMPONENTS
    message_generation
    roscpp
    std_msgs
)

################################################################################
# Setup for python modules and scripts
################################################################################

################################################################################
# Declare ROS messages, services and actions
################################################################################
add_service_files(
  FILES
    Ask.srv
)

generate_messages(
  DEPENDENCIES
    std_msgs
)

################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Declare catkin specific configuration to be passed to dependent projects
################################################################################
include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  CATKIN_DEPENDS
    message_runtime
    roscpp
    std_msgs
)

################################################################################
# Build
################################################################################
add_executable(talker src/talker.cpp)
add_dependencies(talker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
add_dependencies(listener ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(listener ${catkin_LIBRARIES})

add_executable(requester src/requester.cpp)
add_dependencies(requester ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(requester ${catkin_LIBRARIES})

add_executable(responsor src/responsor.cpp)
add_dependencies(responsor ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(responsor ${catkin_LIBRARIES})

################################################################################
# Install
################################################################################
install(TARGETS talker listener requester responsor
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

################################################################################
# Test
################################################################################
if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest_gtest(test_node test/test_node.test test/test_node.cpp)
  target_link_libraries(test_node ${catkin_LIBRARIES})

  find_package(roslint REQUIRED)
  roslint_cpp()
  roslint_python()
endif()
