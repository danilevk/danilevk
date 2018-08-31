
#include <QApplication>
#include "keyboard_control.h"

int main(int argc, char *argv[]) {

  ros::init(argc, argv, "keyboard_control");
  QApplication app(argc, argv);  
    
  KeyPress window;
  
  window.resize(300, 100);
  window.setWindowTitle("Keyboard");
  window.show();
  
  return app.exec();
}
