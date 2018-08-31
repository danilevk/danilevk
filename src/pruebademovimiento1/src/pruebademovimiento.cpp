/*********************************************************************** 
 * Derechos reservados                                                 *
 * Autores: Daniel Steven Levkovits Scherer                            * 
 * Versión: 1.0                                                        *
 * Última actualización:  23/08/2018                                   *
 * Pasantía Larga/Tesis 2018                                           *    
 *                                                                     *
 * El siguiente programa se encarga de generar una trayectoria de      *
 * evasion mediante contadores y finalmente de leer la posición.       *     
 ***********************************************************************/
 
#include <pruebademovimiento.h> //daniel

prueba_de_movimiento::prueba_de_movimiento():   // constructor
	nh_("~"), it_(nh_)
{
	ROS_INFO("Init Webcam Viewer");
	
	Image_ = it_.subscribe("/ardrone/front/image_raw", 1, &prueba_de_movimiento::Image, this); //me subscribo a la imagen del drone.
//////////////////////////Daniel
	OvR_ = nh_.subscribe("/keyboard/override",1, &prueba_de_movimiento::OvR, this); // me subscribo a la funcion de override para iniciar la trayectoria con x e interrumpirla con c.

	Position_ = nh_.subscribe("/gazebo/model_states",1000, &prueba_de_movimiento::Position, this); //me subscribo a la posicion del drone en el espacio.

	pubTakeoff1_ = nh_.advertise<std_msgs::Empty>("/ardrone/takeoff", 3);  //publico la funcion de despegue
	
	pubLand1_ = nh_.advertise<std_msgs::Empty>("/ardrone/land", 3); //publico la funcion de aterrizaje
	
	pubCommandPilot1_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 3); // publico la velocidad a la que viajara el drone

	

////////////////////////// inicializar variables
i=0;
takeoff=0;
land=0;
/*positionx=0.0;
positiony=0.0;
positionz=0.0;
orientationx=0.0;
orientationy=0.0;
orientationz=0.0;
orientationw=0.0;*/
}

prueba_de_movimiento::~prueba_de_movimiento() //destructor
{
}

void prueba_de_movimiento::Image(const sensor_msgs::ImageConstPtr &msg)   // recibe la imagen y se ejecuta todo a 30fps o sea cada vez que recibe la imagen
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
		pitch = 0;
		roll = 0;
		altitude = 0;
		yaw = 0;
		commandPilot.linear.x = pitch;
		commandPilot.linear.y =  roll;
		commandPilot.linear.z = altitude;
		commandPilot.angular.z = yaw;
		pubCommandPilot1_.publish(commandPilot);
		takeoff = 0;
		land =0;
	}
else if(override==6 && land == 0)   //revisar linea para ver si es mejor quitar el land==0
	{
		i=i+1;
		ROS_INFO_STREAM("info"<< i);
		ROS_INFO("\nPosition (x,y,z):\t (%f,%f,%f)\nOrientation (x,y,z,w):\t (%f,%f,%f, %f)", positionx, positiony, positionz, orientationx, orientationy,orientationz, orientationw);
		ROS_INFO("posicion en x:(%f)", positionx);
		
		if(takeoff==0)
		{
			pubTakeoff1_.publish(msgTakeoff);
			takeoff=1;
		}
		if(i>80 && i<=310)
		{
			pitch = 1;
			roll = 0;
			altitude = 0.01;
			yaw = 0;
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i>310 && i<=370)
		{	
			pitch = 0;
			roll = 0;
			altitude = 0;
			yaw = 0;                      
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i>370 && i<=550)
		{	
			pitch = 0;
			roll = -1;
			altitude = 0;
			yaw = 0;
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i>550 && i<=750)
		{	
			pitch = 1;
			roll = 0;
			altitude = 0;
			yaw = 0;
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i>750 && i<=900)
		{	
			pitch = 0;
			roll = 1;
			altitude = 0;
			yaw = 0;
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i>900 && i<=960)
		{	
			pitch = 0;
			roll = 0;
			altitude = 0;
			yaw = 0;
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i>960 && i<=1270)
		{	
			pitch = 1;
			roll = 0;
			altitude = 0;
			yaw = 0;
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i>1270 && i<=1330)
		{	
			pitch = 0;
			roll = 0;
			altitude = 0;
			yaw = 0;
			commandPilot.linear.x = pitch;
			commandPilot.linear.y =  roll;
			commandPilot.linear.z = altitude;
			commandPilot.angular.z = yaw;
			pubCommandPilot1_.publish(commandPilot);
		}
		else if(i > 1330) // no tocar solo rango de i de aqui hacia abajo
		{
			land=1;
		}
		if(land==1)
		{
			pubLand1_.publish(msgLand);
			i = 0;
			override = 10;
		
		}

    }                                   //despegue luego movimiento y luego aterrizaje 

	imshow("Webcam-CADI2018", Webcam_image);
	waitKey(1);

}	
void prueba_de_movimiento::OvR(const std_msgs::Int8 &OvR)
	{
		override = OvR.data;
	}

void prueba_de_movimiento::Position(const gazebo_msgs::ModelStates &Position)
	{
		//ROS_INFO_STREAM("Pose"<<Position.pose.size());
		positionx = Position.pose[11].position.x;
		positiony = Position.pose[11].position.y;
		positionz = Position.pose[11].position.z;
		orientationx = Position.pose[11].orientation.x;
		orientationy = Position.pose[11].orientation.y;
		orientationz = Position.pose[11].orientation.z;
		orientationw = Position.pose[11].orientation.w;
	}