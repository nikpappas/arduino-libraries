#ifndef LedMonitor_h
#define LedMonitor_h

#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <LedControl.h>

const int LEVEL_COUNT = 8;
const int ANALOG_MAX = 1023;
const int DIGITAL_MAX = 255;


byte currentToByte(int current);
double scale(double value, int initial, int result);
void clone(byte *screenBuffer, byte *screenResult, int size);
void shiftLeft(byte *screenBuffer, byte *screenResult, int size);

class LedMonitor{
private:
  int _in;
  LedControl _lc;
  unsigned long _delayTime;
  byte value;
  unsigned long lastRendered;

public:
  LedMonitor(int toneIn, int delayTime, LedControl ledControl);
  void tick();
  void init();
  void draw();
  byte getValue();
  int curIn;
};


#endif	//LedMonitor.h
