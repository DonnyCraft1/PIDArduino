// Libraries
#include <PIDController.h>

// Objects
PIDController pid; // Create an instance of the PID controller class, called "pid"

// Pins
int outputPin   = 3;    // The pin the digital output PMW is connected to
int sensorPin   = A0;   // The pin the analog sensor is connected to

void setup () {
  Serial.begin(9600);   // Some methods require the Serial.begin() method to be called first
  pinMode(outputPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  
  pid.begin();          // initialize the PID instance
  pid.setpoint(600);    // The "goal" the PID controller tries to "reach"
  pid.tune(1, 1, 1);    // Tune the PID, arguments: kP, kI, kD
  pid.limit(0, 255);    // Limit the PID output between 0 and 255, this is important to get rid of integral windup!
}

void loop () {
  int sensorValue = analogRead(sensorPin);  // Read the value from the sensor
  int output = pid.compute(sensorValue);    // Let the PID compute the value, returns the optimal output
  analogWrite(outputPin, output);           // Write the output to the output pin
  delay(30);                                // Delay for 30 ms
}
