#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <mma8451_pi.h>
#include <cmath>



class Accelerometer {
  private:
    mma8451 mma;
    float _threshold;
    unsigned long _timeInterval;
    unsigned long _fallInterval;
    unsigned long _lastTime = 0;
    bool _wasMoving = false;
    unsigned long _lastFallTime = 0;

  public:
    Accelerometer(float threshold, unsigned long timeInterval, unsigned long fallInterval);
    bool isInitialize();
    bool isFallDetected();
};

#endif