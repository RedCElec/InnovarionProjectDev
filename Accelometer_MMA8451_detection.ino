#include <Wire.h>
#include <Adafruit_MMA8451.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451(); // Create an instance of the MMA8451 library

const float THRESHOLD = 2.0; // Set a threshold value for fall detection

void setup() {
  Serial.begin(9600); // Start serial communication
  mma.begin(); // Initialize the MMA8451
  mma.setRange(MMA8451_RANGE_2_G); // Set the range to 2g
}

void loop() {
  static unsigned long lastTime = 0; // Initialize the last time variable
  static bool wasMoving = false; // Initialize the movement flag
  
  sensors_event_t event; // Create a variable to store the sensor event data
  
  if (mma.getEvent(&event)) { // Read the sensor data
    float acceleration = sqrt(pow(event.acceleration.x, 2) + pow(event.acceleration.y, 2) + pow(event.acceleration.z, 2)); // Calculate the total acceleration
    
    if (acceleration > THRESHOLD) { // Check if the acceleration exceeds the threshold
      if (!wasMoving) { // Check if the accelerometer was previously stationary
        unsigned long currentTime = millis(); // Get the current time
        
        if ((currentTime - lastTime) > 1000) { // Check if the time between movements exceeds 1 second
          Serial.println("Fall detected!"); // Print a message indicating that a fall has been detected
          
          // TODO: Trigger an alarm or notification here
          
          lastTime = currentTime; // Update the last time variable
        }
      }
      
      wasMoving = true; // Set the movement flag
    }
    else {
      wasMoving = false; // Reset the movement flag
    }
    
    Serial.print("X: ");
    Serial.print(event.acceleration.x);
    Serial.print(" m/s^2\tY: ");
    Serial.print(event.acceleration.y);
    Serial.print(" m/s^2\tZ: ");
    Serial.print(event.acceleration.z);
    Serial.print(" m/s^2\tTotal Acceleration: ");
    Serial.println(acceleration);
  }
  
  delay(100); // Delay for 100ms
}

