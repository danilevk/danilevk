cmake_minimum_required(VERSION 2.8.3)
project(pruebadecontrol1)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  gazebo_msgs
  geometry_msgs
  image_transport
  nav_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
)

find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pruebadecontrol
#  CATKIN_DEPENDS cv_bridge gazebo_msgs image_transport roscpp rospy std_msgs geometry_msgs sensor_msgs  nav_msgs tf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

include_directories(/home/daniellevkovits/catkin_ws/src/pruebadecontrol1/include/pruebadecontrol1)

## Declare a C++ executable
add_executable(pruebadecontrol 
          src/pruebadecontrol.cpp 
          src/pruebadecontrol_.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(pruebadecontrol
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})
