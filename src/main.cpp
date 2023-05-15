#include <iostream>
#include <mma8451_pi.h>
#include <chrono> //to be check
#include <thread> //to be check
// #include <Adafruit_Sensor.h>


int treshold = 0.8;

void event(int value)
{
  std::cout << "Send request" << std::endl;

  system(" curl --location --request GET 'http://localhost:3000/webhook' \
--header 'Content-Type: application/json' \
  ");
}

void i2c_display()
{


}

int main()
{
  std::cout << "Starting fall detection..." << std::endl;

  mma8451 sensor = mma8451_initialise(1, MMA8451_DEFAULT_ADDR);
  mma8451_vector3 acceleration;

  while (true)
  {

    mma8451_get_acceleration(&sensor, &acceleration);
    std::cout << acceleration << std::endl;
    if(acceleration.x >= treshold || acceleration.y >=  treshold || acceleration.z >= treshold){
      event(acceleration.x);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
