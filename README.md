# PIDArduino
A simple PID controller library for Arduino

*Warning, this library hasn't been properly tested yet. Bugs may occur*

# Usage
```java
#include <PIDController.h>
PIDController pid;
```

First include the library.

Then create an instance of the class.

---

```java
#include <PIDController.h>
PIDController pid;

void setup () {
  Serial.begin(9600);   // Some methods require the Serial.begin() method to be called first
  pid.begin();          // initialize the PID instance
  pid.setpoint(600);    // The "goal" the PID controller tries to "reach"
  pid.tune(1, 1, 1);    // Tune the PID, arguments: kP, kI, kD
  pid.limit(0, 255);    // Limit the PID output between 0 and 255, this is important to get rid of integral windup!
}

void loop () {
  int sensorValue = analogRead(A0);         // Read the value from the sensor
  int output = pid.compute(sensorValue);    // Let the PID compute the value, returns the optimal output
  delay(30);                                // Delay for 30 ms
}
```

In the setup function, call:

* `pid.begin()` to initialize the object.

* `pid.setpoint(newSetpoint)` to set the wanted value.

* `pid.tune(kP, kI, kD)` to tune the controller.

* `pid.limit(min, max)` to get rid of [integral windup](https://en.wikipedia.org/wiki/Integral_windup) (nasty stuff), and to limit the output values from the controller.


***THIS ARTICLE IS NOT FINISHED YET***
