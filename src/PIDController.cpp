#include "PIDController.h"

PIDController::PIDController () {
  // Variables - double
  output = 0;
  lastErr = 0;
  errSum = 0;

  // Variables - long
  lastTime = 0;

  // Variables - bool

  // Variables - double - tuining
  Kp = 1;
  Ki = 1;
  Kd = 1;
  minOut = 0;
  maxOut = 255;
  setPoint = 0;
}

void PIDController::setpoint (double newSetpoint) {
  setPoint = newSetpoint;
}

void PIDController::tune (double _Kp, double _Ki, double _Kd) {
  if (_Kp < 0 || _Ki < 0 || _Kd < 0) return;
  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;
}

void PIDController::limit(double min, double max) {
  minOut = min;
  maxOut = max;
}

void PIDController::printGraph (double sensorInput, boolean verbose) {
  if (verbose) {
    Serial.print(sensorInput);
    Serial.print(",");
    Serial.print(setPoint);
    // VERBOSE
    Serial.print(",");
    Serial.println(output);
  } else {
    Serial.print(sensorInput);
    Serial.print(",");
    Serial.println(setPoint);
  }
}

// Getters
double PIDController::getOutput () {
  return output;
}


double PIDController::compute (int sensor, boolean graph, boolean verbose) {
  // Return false if it could not execute;
  // This is the actual PID algorithm executed every loop();

  // Calculate time difference since last time executed
  now = millis();
  timeChange = (int) (now - lastTime);

  // Calculate the error (proportional)
  error = setPoint - sensor;

  // Calculate the error sum (integral)
  errSum += error * timeChange;

  // Calculate the derivative
  dErr = (error - lastErr) / timeChange;

  // Limit the error sum (integral)
  errSum = constrain(errSum, minOut - (minOut * 0.1), maxOut + (maxOut * 0.1));

  // Calculate the new output by adding all three elements together
  output = constrain(((Kp * error + Ki * errSum + Kd * dErr) / 10), minOut, maxOut);

  // Update lastErr and lastTime to current values for use in next execution
  lastErr = error;
  lastTime = now;

  // Draw the garph if GRAPH mode
  if (graph) {
    printGraph(sensor, verbose);
  }

  // Return the current output
  return output;
}
