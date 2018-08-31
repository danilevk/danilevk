/*********************************************************************** 
 * Derechos reservados                                                 *
 * Autores: Daniel Steven Levkovits Scherer                            * 
 * Versión: 1.0                                                        *
 * Última actualización:  23/08/2018                                   *
 * Pasantía Larga/Tesis 2018                                           *    
 *                                                                     *
 * El siguiente programa se encarga de generar una trayectoria de      *
 * evasion mediante posicionamiento y hacer el control del drone.      *     
 ***********************************************************************/
 
#include <pruebadecontrol.h> //daniel

prueba_de_control::prueba_de_control():   // constructor
	nh_("~"), it_(nh_)
{
	ROS_INFO("Init Webcam Viewer");
	
	Image_ = it_.subscribe("/ardrone/front/image_raw", 1, &prueba_de_control::Image, this); //me subscribo a la imagen del drone.
//////////////////////////Daniel
	OvR_ = nh_.subscribe("/keyboard/override",1, &prueba_de_control::OvR, this); // me subscribo a la funcion de override para iniciar la trayectoria con x e interrumpirla con c.

	Position_ = nh_.subscribe("/gazebo/model_states",1000, &prueba_de_control::Position, this); //me subscribo a la posicion del drone en el espacio.

	pubTakeoff1_ = nh_.advertise<std_msgs::Empty>("/ardrone/takeoff", 3);  //publico la funcion de despegue
	
	pubLand1_ = nh_.advertise<std_msgs::Empty>("/ardrone/land", 3); //publico la funcion de aterrizaje
	
	pubCommandPilot1_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 3); // publico la velocidad a la que viajara el drone

////////////////////////// inicializar variables
i=0;
takeoff=0;
land=0;

}

prueba_de_control::~prueba_de_control() //destructor
{
}

void prueba_de_control::Image(const sensor_msgs::ImageConstPtr &msg)   // recibe la imagen y se ejecuta todo a 30fps o sea cada vez que recibe la imagen
{	
	try
	{
		cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
	}
	catch (cv_bridge::Exception& e)
	{
		ROS_ERROR("cv_bridge exception: %s", e.what());
		return;
	}
	
	Webcam_image = cv_ptr->image;

///////////////////////////MOVIMIENTO AUTONOMO DEL DRONE	
if(override==10)
	{
		ROS_INFO("Overriding");
		pitch_vel = 0;
		roll_vel = 0;
		altitude_vel = 0;
		yaw_vel = 0;
		commandPilot.linear.x = pitch_vel;
		commandPilot.linear.y =  roll_vel;
		commandPilot.linear.z = altitude_vel;
		commandPilot.angular.z = yaw_vel;
		pubCommandPilot1_.publish(commandPilot);
		land =0;
		takeoff = 0;
		ROS_INFO("posicion en x override:(%f)", positionx);	
	}

	
else if(override == 6)   //revisar linea para ver si es mejor quitar el && land==0
{
	i=i+1;

	ROS_INFO_STREAM("info"<< i);
	ROS_INFO("\nPosition (x,y,z):\t (%f,%f,%f)\n", positionx, positiony, positionz);
	ROS_INFO("\nOrientation (x,y,z,w):\t (%f,%f,%f, %f)\n", orientationx, orientationy,orientationz, orientationw);
	
	if(takeoff == 0)
		{
			
			wpx = positionx + 10.0;     //world position en X
			wpy = positiony + 0.0;     //world position en Y
			ROS_INFO("wpx: %f", wpx);
			ROS_INFO("wpy: %f", wpy);
			pubTakeoff1_.publish(msgTakeoff);
			takeoff = 1;
		}
	if(takeoff == 1 && i == 49)
		{
			wpz = positionz + 0.0;    //world position en Z
			ROS_INFO("wpz: %f", wpz);
		}

	if(takeoff == 1 && i >= 50)
		{
		//control de la POSICION controlador P

			error_px = wpx - positionx;    // el error es la diferencia de distancia entre el punto al que quieres llegar y el punto en el que estas.
			error_py = wpy - positiony;
			error_pz = wpz - positionz;
			ROS_INFO("error X: %f", error_px);
			ROS_INFO("error Y: %f", error_py);
			ROS_INFO("error Z: %f", error_pz);
			Kp_px = 0.8;                  //ctte de proporcionalidad desplazamiento en x
			Kp_py = 0.8;                  //ctte de proporcionalidad desplazamiento en y
			Kp_pz = 0.8; 				  //ctte de proporcionalidad desplazamiento en z
			           
            //ROS_INFO("Kp_px: %f", Kp_px);
			u_px = Kp_px * error_px;			 //control de velocidad en x con controlador P
			u_py = Kp_py * error_py;
			u_pz = Kp_pz * error_pz;
			//ROS_INFO("u_px: %f", u_px);
			pitch_vel = u_px;
			roll_vel = u_py;
			altitude_vel = u_pz;
			yaw_vel = 0;
			commandPilot.linear.x = pitch_vel;
			commandPilot.linear.y =  roll_vel;
			commandPilot.linear.z = altitude_vel;
			commandPilot.angular.z = yaw_vel;
			pubCommandPilot1_.publish(commandPilot);
			ROS_INFO("pitch_vel: %f", pitch_vel);              
			ROS_INFO("roll_vel: %f", roll_vel); 
			ROS_INFO("yaw_vel: %f", yaw_vel); 
	
		if( (error_px > -0.1 && error_px < 0.07) && (error_py > -0.07 && error_py < 0.07) && (error_pz > -0.1 && error_pz < 0.1) )
			{
				ROS_INFO("esperando aterrizar");

				pitch_vel = u_px;
				roll_vel = u_py;
				altitude_vel = u_pz;
				yaw_vel = 0;
				commandPilot.linear.x = pitch_vel;
				commandPilot.linear.y =  roll_vel;
				commandPilot.linear.z = altitude_vel;
				commandPilot.angular.z = yaw_vel;
				pubCommandPilot1_.publish(commandPilot);
				land = 1;
				j++;
			}
			 ////////////////////	
		}

	if(land == 1 && j>=20)
		{
			ROS_INFO("aterrizando");
			pitch_vel = 0;
			roll_vel = 0;
			altitude_vel = 0;
			yaw_vel = 0;
			commandPilot.linear.x = pitch_vel;
			commandPilot.linear.y =  roll_vel;
			commandPilot.linear.z = altitude_vel;
			commandPilot.angular.z = yaw_vel;
			pubCommandPilot1_.publish(commandPilot);
			pubLand1_.publish(msgLand);
			i = 0;
			override = 10;
		}
	                            //despegue luego movimiento y luego aterrizaje 
}
		
	imshow("Webcam-CADI2018", Webcam_image);
	waitKey(1);
	
}


void prueba_de_control::OvR(const std_msgs::Int8 &OvR)
	{
		override = OvR.data;
	}

void prueba_de_control::Position(const gazebo_msgs::ModelStates &Position)
	{
														//ROS_INFO_STREAM("Pose"<<Position.pose.size());
		positionx = Position.pose[11].position.x;
		positiony = Position.pose[11].position.y;
		positionz = Position.pose[11].position.z;
		orientationx = Position.pose[11].orientation.x;
		orientationy = Position.pose[11].orientation.y;
		orientationz = Position.pose[11].orientation.z;
		orientationw = Position.pose[11].orientation.w;
		tf::Quaternion q(Position.pose[11].orientation.x, Position.pose[11].orientation.y, Position.pose[11].orientation.z, Position.pose[11].orientation.w);
		tf::Matrix3x3 m(q);
      	m.getRPY(roll, pitch, yaw);
      	roll = roll * 180 / 3.141592;
      	yaw = yaw * 180 / 3.141592;
      	pitch = pitch * 180 / 3.141592;
	}