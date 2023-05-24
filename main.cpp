#include <iostream>
#include <chrono>
#include <thread>
#include "Accelerometer.h"
#include <luma.oled/RaspberryPi/gpio.h>
#include <luma.oled/graphics.h>
#include <luma.core/interface.h>
/////////////////////////////////////////////////////////////////////////
//pip install luma.oled (use this command to install the oled library)//
///////////////////////////////////////////////////////////////////////
using namespace std;
using namespace luma::core;
using namespace luma::gpio;
using namespace luma::oled;

// Define the OLED display
gpio sda{bcm2835_gpio_P1_03};  // GPIO 2
gpio scl{bcm2835_gpio_P1_05};  // GPIO 3
ssd1306_i2c_interface i2c{sda, scl};
ssd1306 display{i2c};

void displayMessage(const char* message) {
  display.clear();
  display.set_position(Point(0, 0));
  display.text(message, "FreeSans.ttf", 16, WHITE);
  display.show();
}

int main() {
  std::cout << "Starting fall detection..." << std::endl;

  Accelerometer accelerometer(20, 2000, 5000);
  accelerometer.initialize();

  display.init();
  displayMessage("Fall detection...");

  while (true) {
    if (accelerometer.isFallDetected()) {
      std::cout << "Fall detected!" << std::endl;
      displayMessage("Fall detected!");
      // Perform any necessary actions based on the fall detection
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
