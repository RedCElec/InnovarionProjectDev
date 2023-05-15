#include <iostream>
#include <mma8451_pi.h>
#include <chrono> //to be check
#include <thread> //to be check
//#include <Adafruit_Sensor.h>

void event(int value){

  std::cout << "Send request" << std::endl;
/*
  system("curl --location --request GET 'http://localhost:3000/webhook' \
--header 'Content-Type: application/json' \
--data '{
    "value": 0.8
}'");  */
}

void i2c_display();

int main() {
  std::cout << "Starting fall detection..." << std::endl;

  mma8451 sensor = mma8451_initialise(1, MMA8451_DEFAULT_ADDR);
  mma8451_vector3 acceleration;

  

    mma8451_get_acceleration(&sensor, &acceleration);
    std::cout << acceleration << std::endl;
     

  return 0;
}



