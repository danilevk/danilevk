#include <pruebademovimiento.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "pruebademovimiento");
  
  prueba_de_movimiento OBJECT;

  ros::spin();

  return 0;
}
