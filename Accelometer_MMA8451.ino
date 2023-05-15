#include <Wire.h>
#include <Adafruit_MMA8451.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451(); // Create an instance of the MMA8451 library

void setup() {
  Serial.begin(9600); // Start serial communication
  mma.begin(); // Initialize the MMA8451
  mma.setRange(MMA8451_RANGE_2_G); // Set the range to 2g
}

void loop() {
  sensors_event_t event; // Create a variable to store the sensor event data
  
  if (mma.getEvent(&event)) { // Read the sensor data
    Serial.print("X: ");
    Serial.print(event.acceleration.x);
    Serial.print(" m/s^2\tY: ");
    Serial.print(event.acceleration.y);
    Serial.print(" m/s^2\tZ: ");
    Serial.print(event.acceleration.z);
    Serial.print(" m/s^2\tOrientation: ");
    
    switch (mma.getOrientation()) {
      case MMA8451_PL_PUF:
        Serial.println("Portrait up front");
        break;
      case MMA8451_PL_PUB:
        Serial.println("Portrait up back");
        break;
      case MMA8451_PL_PDF:
        Serial.println("Portrait down front");
        break;
      case MMA8451_PL_PDB:
        Serial.println("Portrait down back");
        break;
      case MMA8451_PL_LRF:
        Serial.println("Landscape right front");
        break;
      case MMA8451_PL_LRB:
        Serial.println("Landscape right back");
        break;
      case MMA8451_PL_LLF:
        Serial.println("Landscape left front");
        break;
      case MMA8451_PL_LLB:
        Serial.println("Landscape left back");
        break;
      default:
        Serial.println("Unknown orientation");
    }
  }
  
  delay(100); // Delay for 100ms
}