#include <VoltometerModule.h>
#include <SignalEmitterModule.h>
#include <SignalEmitterModule.h>
const int OUT = 9;
VoltometerModule vm = VoltometerModule(A0, INPUT);
SignalEmitterModule sem = SignalEmitterModule(OUT, 200);


void setup() {
  vm.init();
  sem.init();
}

void loop() {
  sem.tick();
//  tone(OUT, 440);
  vm.tick();
  vm.log();
  delay(20);
//  if(millis())
}
