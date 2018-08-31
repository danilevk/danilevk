#ifndef KEYBOARD_CONTROL_H 
#define KEYBOARD_CONTROL_H

#include <ros/ros.h>
#include <ros/package.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>

#include <visualization_msgs/Marker.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <std_msgs/Int8.h>
#include "std_msgs/Empty.h"

#include "std_msgs/String.h"
#include <std_msgs/UInt16.h>
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Float32MultiArray.h"

#include <QWidget>
#include <QtGui>

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QFont>
#include <QKeyEvent>

using namespace std;

class KeyPress: public QWidget 
{

  public:
    KeyPress(QWidget *parent = 0);
    ~KeyPress();
	
  protected:
    void keyPressEvent(QKeyEvent * e);
  
  private:
  
  	ros::NodeHandle nh_;
  	
  	ros::Publisher OvR;
	ros::Publisher pubLand1_;
	
	ros::Publisher pubTakeoff1_;

	ros::Publisher pubCommandPilot1_;
	
	ros::Publisher pubCommandCamera1_;
	
	geometry_msgs::Twist commandPilot;
	geometry_msgs::Twist commandCam;
  
	std_msgs::Empty msgLand;
	std_msgs::Empty msgTakeoff;
	std_msgs::Int8 override;
	

	QGridLayout *grid;
  	QLabel *Drone_Selec;
	QLabel *Speed;
	QLabel *Alt_speed;

	QLabel *num_drone;
	QLabel *Speed_value;
	QLabel *Alt_speed_value;
	QLabel *Command;

	QFont font;
	
	float speed;
	float altitude_speed;

	float pitch;
	float roll;
	float yaw;
	float altitude;
	
	int drone_selected;

};

#endif
