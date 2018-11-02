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
    double compute(double input, string graph = NOGRAPH);

    // Methods - void
    void begin();
    void tune(double _Kp, double _Ki, double _Kd);
    void limit(double min, double max);
    void setpoint(double newSetpoint);
    void minimize(double newMinimize);

    // Methods - double, getters
    double getOutput();
	
	// Constants
	const static string GRAPH;
	const static string NOGRAPH;
  private:
    // Methods
    void graph(double _sensor);
    
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
