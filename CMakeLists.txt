cmake_minimum_required(VERSION 2.8.3)
project(conveyor_controller)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)

## Declare ROS messages and services
add_message_files(FILES controll_mode.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package(
  #INCLUDE_DIRS include
  LIBRARIES conveyor_controller
  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS system_lib
)

## Build node
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(controller_msg_publisher src/controller_msg_publisher.cpp)
target_link_libraries(controller_msg_publisher ${catkin_LIBRARIES})
add_dependencies(controller_msg_publisher controller_msg_publisher.cpp)
