#ifndef PIDControllerLib
#define PIDControllerLib

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define GRAPH     "graph"
#define NOGRAPH   "nograph"
#define VERBOSE   "verbose"
#define NOVERBOSE "noverbose"

class PIDController {
  public:
    // Constructor
    PIDController();

    // Methods - double
    double compute(double input, String graph = NOGRAPH, String verbose = NOVERBOSE);

    // Methods - void
    void begin();
    void tune(double _Kp, double _Ki, double _Kd);
    void limit(double min, double max);
    void setpoint(double newSetpoint);
    void minimize(double newMinimize);

    // Methods - double, getters
    double getOutput();
  private:
    // Methods
    void printGraph(double sensorInput, String verbose);
    
    // Variables - long
    unsigned long lastTime;

    // Variables - double
    double output;
    double lastErr;
    double timeChanged;

    // Variables - double, error variables
    double error;
    double errSum;
    double dErr;

    // Variables - bool
    bool doLimit;
    bool init;

    // Variables - double - tuining
    double Kp;
    double Ki;
    double Kd;
    double divisor;
    double minOut;
    double maxOut;
    double setPoint;
};
#endif
