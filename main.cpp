#include <iostream>
#include <chrono>
#include <thread>
#include "Accelerometer.h"
#include <luma.oled/RaspberryPi/gpio.h>
#include <luma.oled/graphics.h>
#include <luma.core/interface.h>
/////////////////////////////////////////////////////////////////////////
//sudo apt-get update
//sudo apt-get install -y build-essential cmake libjpeg-dev zlib1g-dev libtiff5-dev libopenjp2-7-dev libssl-dev libcurl4-openssl-dev libx11-dev libxcb1-dev libxau-dev libxdmcp-dev libx11-xcb-dev liblzma-dev libxcb-shm0-dev libxcb-render0-dev libxcb-randr0-dev libxcb-image0-dev libxrandr-dev libxrender-dev libfontconfig1-dev libfreetype6-dev libsystemd-dev libudev-dev libinput-dev libmtdev-dev libts-dev libjpeg62-turbo-dev
//make sure to download the dependencies above
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
