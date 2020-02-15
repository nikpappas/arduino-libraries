#include <OpAmp.h>
OpAmp opAmp = OpAmp(1023, 0);
const int values[] = {
  1,200, 400, 600, 700
};
int i=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9300);
  Serial.println("inA inB out");
}

void loop() {
 
  int value = opAmp.operate(values[i], values[i+1]);
  Serial.print(values[i]);
  Serial.print(" ");
  Serial.print(values[i+1]);
  Serial.print(" ");
  Serial.println(value);
  delay(400);
  
  // put your main code here, to run repeatedly:

}
