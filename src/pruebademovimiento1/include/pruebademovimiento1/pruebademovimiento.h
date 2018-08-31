#ifndef pruebademovimiento
#define pruebademovimiento

#include <ros/ros.h>
#include <ros/package.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <geometry_msgs/Twist.h> ///
#include <std_msgs/Int8.h>     ////
#include <std_msgs/Empty.h>///
#include <nav_msgs/Odometry.h>//
#include <gazebo_msgs/ModelStates.h>

using namespace cv;
using namespace std;

class prueba_de_movimiento
{

//private:
public:

	ros::NodeHandle nh_;
	
  	image_transport::ImageTransport it_;
  	image_transport::Subscriber Image_;
	
	ros::Subscriber Position_;
	ros::Subscriber OvR_; ///
	ros::Publisher pubLand1_;/////
	ros::Publisher pubTakeoff1_;////
	ros::Publisher pubCommandPilot1_;///
	geometry_msgs::Twist commandPilot;//
	std_msgs::Empty msgTakeoff;//
	std_msgs::Empty msgLand;//
 
	Mat Webcam_image;
	
	cv_bridge::CvImagePtr cv_ptr;
	

public:

	prueba_de_movimiento();
	~prueba_de_movimiento();
	float speed;
	float pitch;
	float roll;
	float yaw;
	float altitude;
	int override;///
	int i;
	int takeoff;
	int land;
	
	float positionx;
	float positiony;
	float positionz;
	float orientationx;
	float orientationy;
	float orientationz;
	float orientationw;


	void Image(const sensor_msgs::ImageConstPtr &msg);
	void OvR(const std_msgs::Int8 &OvR);////////////////  
	void Position(const gazebo_msgs::ModelStates &Position);///
};

#endif
