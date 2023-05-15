#include <iostream>
#include "Accelerometer.h"
#include <chrono> //to be check
#include <thread> //to be check
//#include <Adafruit_Sensor.h>


void event(int value){

  std::cout << "Send request" << std::endl;

  system("curl --location --request GET 'http://localhost:3000/webhook' \
--header 'Content-Type: application/json' \
--data '{
    "value": "+std::to_string(value)+"
}' ")
}

void i2c_display();

int main() {
  std::cout << "Starting fall detection..." << std::endl;

  Accelerometer accelerometer(20, 2000, 5000);
  accelerometer.initialize();

  while (true) {
    if (accelerometer.isFallDetected()) {
      std::cout << "Fall detected!" << std::endl;
      event();
      i2c_display();    
      // Perform any necessary actions based on the fall detection 
    }
    
    this_thread::sleep_for(chrono::milliseconds(100)); // to be check
  }

  return 0;
}

