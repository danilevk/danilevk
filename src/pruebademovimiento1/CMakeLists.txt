cmake_minimum_required(VERSION 2.8.3)
project(pruebademovimiento1)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
  image_transport
  geometry_msgs
  nav_msgs
  gazebo_msgs
)

find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pruebademovimiento
#  CATKIN_DEPENDS cv_bridge image_transport roscpp rospy std_msgs geometry_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

include_directories(/home/daniellevkovits/catkin_ws/src/pruebademovimiento1/include/pruebademovimiento1)

## Declare a C++ executable
add_executable(pruebademovimiento 
					src/pruebademovimiento.cpp 
					src/pruebademovimiento_.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(pruebademovimiento 
				${catkin_LIBRARIES}
				${OpenCV_LIBS})
