#ifndef PIDControllerConstants
#define PIDControllerConstants

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define DIVISORDEF 10;
#define MINLIMDEF 0;
#define MAXLIMDEF 255;

#endif