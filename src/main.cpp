#include <iostream>
#include <mma8451_pi/mma8451_pi.h>
#include <chrono> 
#include <thread>
#include <fstream>
#include <string>


const int treshold = 2;

// Path to the GPIO value file
const int GPIO_PIN = 17;
const std::string GPIO_PATH = "/sys/class/gpio/gpio" + std::to_string(GPIO_PIN) + "/value";



void event_sensor(int value)
{
  std::cout << "\n Send request for acceleration" << std::endl;

  system(" curl --location --request GET 'http://localhost:3000/alarmAcceleration' \
--header 'Content-Type: application/json' \
  ");
  std::cout << std::endl;
}
void event_button()
{
  std::cout << "\n Send request for emergency button" << std::endl;

  system(" curl --location --request GET 'http://localhost:3000/alarmButton' \
--header 'Content-Type: application/json' \
  ");
  std::cout << std::endl;
}

void i2c_display()
{


}

int main()
{
      // Export the GPIO pin
    std::ofstream exportFile("/sys/class/gpio/export");
    exportFile << GPIO_PIN;
    exportFile.close();

    // Set the GPIO pin as an INPUT
    std::ofstream directionFile("/sys/class/gpio/gpio" + std::to_string(GPIO_PIN) + "/direction");
    directionFile << "in";
    directionFile.close();
  //Emergency Button Initialization
  
  //Important Value 
    bool GPIO_value;

  //Sensor Initialization
  std::cout << "Starting fall detection..." << std::endl;
  mma8451 sensor = mma8451_initialise(1, MMA8451_DEFAULT_ADDR);
  mma8451_set_range(&sensor, 4);
  mma8451_vector3 acceleration;


  while (true)
  {
    //Emergency Button Part 
    std::ifstream valueFile(GPIO_PATH);
    if (!valueFile) {
        std::cerr << "Failed to open GPIO value file" << std::endl;
        //return 1; //should not be comment when build
    }
    valueFile >> GPIO_value;
    
    if(GPIO_value == 1){
      event_button();
    }
    valueFile.close();
    


    //Sensor Part
    mma8451_get_acceleration(&sensor, &acceleration);
    std::cout << acceleration << std::endl;
    if(acceleration.x >= treshold || acceleration.y >=  treshold || acceleration.z >= treshold){
      event_sensor(acceleration.x);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  }

  return 0;
}

