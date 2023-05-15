#include <iostream>
<<<<<<< HEAD:mma8451_pi-master/main.cpp
#include <chrono>
#include <thread>
#include "Accelerometer.h"
#include <mma8451_pi.h>

using namespace std;
=======
#include "Accelerometer.cpp"
//#include <Adafruit_Sensor.h>
>>>>>>> 631d15bcdfb02b84e187a3fa8d635b2bdb06baa7:Adafruit_Sensor/main.cpp

int main() {
  std::cout << "Starting fall detection..." << std::endl;

  Accelerometer accelerometer(20, 2000, 5000);
  accelerometer.initialize();

  while (true) {
    if (accelerometer.isFallDetected()) {
      std::cout << "Fall detected!" << std::endl;
      // Perform any necessary actions based on the fall detection
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
