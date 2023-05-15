#include <iostream>
#include "Accelerometer.h"
#include <mma8451_pi.h>






/**
int main() {
  // Create an instance of the Accelerometer class
  Accelerometer accelerometer(250, 2000, 5000);

  // Initialize the accelerometer
  if (!accelerometer.isInitialize()) {
    cout << "Failed to initialize accelerometer!" << endl;
    return -1;
  }

  // Loop to continuously check for falls
  while (true) {
    // Check if a fall has been detected
    if (accelerometer.isFallDetected()) {
      // Perform actions for when a fall is detected
      cout << "Fall detected!" << endl;
    }

    // Add a delay before checking for falls again
    //delay(10);
  }

  return 0;
}

*/
