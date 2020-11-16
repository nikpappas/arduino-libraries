#include <ValueConverter.h>
#include <OpAmpModule.h>
#include <VoltometerModule.h>
#include <Logger.h>
const int INA = A0;
const int INB = A1;
const int IN_READ = A3;

const int OUT = 9;

const unsigned long DELAY = 19;
const int ANALOG_MAX = 1023;
const int DIGITAL_MAX = 255;
//OpAmpModule opAmp = OpAmpModule(INA, INB, OUT);
VoltometerModule meter = VoltometerModule(IN_READ);

void setup() {
  Serial.begin(9600);
//  opAmp.init();
  meter.init();
  Serial.println("");
}

void loop() {    
//  opAmp.tick();
//  opAmp.log();
  Serial.print(" ");
  meter.tick();
  meter.log();
  
  Serial.println("");
  delay(DELAY);  
}
