#ifndef pruebadecontrol
#define pruebadecontrol

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
#include <tf/transform_datatypes.h>

using namespace cv;
using namespace std;

class prueba_de_control
{

private:


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

	float positionx;
	float positiony;
	float positionz;
	float orientationx;
	float orientationy;
	float orientationz;
	float orientationw;
	float wpx, wpy, wpz;
	float error_px, error_py, error_pz;
	float Kp_px, Kp_py, Kp_pz;
	float u_px, u_py, u_pz;
	
	//double roll, pitch, yaw;
	float wox, woy, woz;
	float error_ox, error_oy, error_oz;
	float Kp_ox, Kp_oy, Kp_oz;
	float u_ox, u_oy, u_oz;


	

public:

	prueba_de_control();
	~prueba_de_control();

	int override;///
	int i;
	int j;
	int takeoff;
	int land;

	float speed;
	float pitch_vel;
	float roll_vel;
	float yaw_vel;
	float altitude_vel;

	void Image(const sensor_msgs::ImageConstPtr &msg);
	void OvR(const std_msgs::Int8 &OvR);////////////////  
	void Position(const gazebo_msgs::ModelStates &Position);///
	
};

#endif
