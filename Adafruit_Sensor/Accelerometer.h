#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>
#include <cmath>

class Accelerometer {
  private:
    Adafruit_MMA8451 mma;
    float _threshold;
    unsigned long _timeInterval;
    unsigned long _fallInterval;
    unsigned long _lastTime = 0;
    bool _wasMoving = false;
    unsigned long _lastFallTime = 0;

  public:
    Accelerometer(float threshold, unsigned long timeInterval, unsigned long fallInterval);
    void initialize();
    bool isFallDetected();
};

#endif

