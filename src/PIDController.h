#ifndef PIDControllerLib
#define PIDControllerLib

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class PIDController {
  public:
    // Constructor
    PIDController();

    // Methods - double
    double compute(double input, boolean graph = false, boolean verbose = false);

    // Methods - void
    void tune(double _Kp, double _Ki, double _Kd);
    void limit(double min, double max);
    void setpoint(double newSetpoint);

    // Methods - double, getters
    double getOutput();
  private:
    // Methods
    void printGraph(double sensorInput, boolean verbose = false);
    
    // Variables - long
    unsigned long lastTime;
    unsigned long now;

    // Variables - double
    double output;
    double lastErr;
    double timeChange;

    // Variables - double, error variables
    double error;
    double errSum;
    double dErr;

    // Variables - bool

    // Variables - double - tuining
    double Kp;
    double Ki;
    double Kd;
    double minOut;
    double maxOut;
    double setPoint;
};
#endif
