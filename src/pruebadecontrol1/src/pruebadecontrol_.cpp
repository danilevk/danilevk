#include <pruebadecontrol.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "pruebadecontrol");
  
  prueba_de_control OBJECT;

  ros::spin();

  return 0;
}
