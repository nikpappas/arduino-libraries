#include <ValueConverter.h>
#include <OpAmpModule.h>
#include <Logger.h>
const int INA = A0;
const int INB = A1;

const int OUT = 7;

const int RESULT_IN = A1;

const unsigned long DELAY = 60;
const int ANALOG_MAX = 1023;
const int DIGITAL_MAX = 255;
OpAmpModule opAmp = OpAmpModule(INA, INB, OUT);

void setup() {
  Serial.begin(9600);
  opAmp.init();
}

void loop() {
    
  opAmp.tick();
  opAmp.log();
  delay(DELAY);  
  
}
