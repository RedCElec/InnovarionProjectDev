#include <iostream>
#include "Accelerometer.cpp"
//#include <Adafruit_Sensor.h>

int main() {
  std::cout << "Starting fall detection..." << std::endl;

  Accelerometer accelerometer(20, 2000, 5000);
  accelerometer.initialize();

  while (true) {
    if (accelerometer.isFallDetected()) {
      std::cout << "Fall detected!" << std::endl;
      // Perform any necessary actions based on the fall detection
    }
  }

  return 0;
}

