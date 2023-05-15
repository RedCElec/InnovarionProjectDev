#include "Accelerometer.h"
#include <cmath>
//#include <Adafruit_Sensor.h>

Accelerometer::Accelerometer(int threshold, int timeInterval, int fallInterval) {
  _threshold = threshold;
  _timeInterval = timeInterval;
  _fallInterval = fallInterval;
}



void Accelerometer::initialize() {
  // Initialize the accelerometer
}


bool Accelerometer::isFallDetected() {
  sensors_event_t event;
  if (!mma.getEvent(&event)) {
    return false;
  }

  float acceleration = sqrt(pow(event.acceleration.x, 2) + pow(event.acceleration.y, 2) + pow(event.acceleration.z, 2));

  if (acceleration > _threshold) {
    if (!_wasMoving) {
      unsigned long currentTime = getTimeInMillis();

      if ((currentTime - _lastTime) > _timeInterval) {
        if ((currentTime - _lastFallTime) > _fallInterval) {
          _lastFallTime = currentTime;
          _wasMoving = true;

          return true;
        }
      }
    }

    _wasMoving = true;
  } else {
    _wasMoving = false;
  }

  return false;
}


unsigned long Accelerometer::getTimeInMillis() {
  // Return the current time in milliseconds
}
