#include <OpAmp.h>
#include <ValueConverter.h>

const int IN = A0;

const int OUT = 7;

const int RESULT_IN = A1;

const unsigned long DELAY = 60;
const int ANALOG_MAX = 1023;
const int DIGITAL_MAX = 255;

OpAmp opAmp = OpAmp(ANALOG_MAX, 0);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("");
  Serial.println("inA inB out res");
  pinMode(IN, INPUT);
  pinMode(RESULT_IN, INPUT);
  pinMode(OUT, OUTPUT);
  
}

void loop() {
  int inA = analogRead(IN);
  int inB = ANALOG_MAX/2;

  int value = opAmp.operate(inA, inB);
  
  digitalWrite(OUT, value);
  int result = analogRead(RESULT_IN);
  Serial.print(analog2V(inA)); // inA
  Serial.print(" ");
  Serial.print(analog2V(inB)); // inB
  Serial.print(" ");
  Serial.print(analog2V(value)); // out
  Serial.print(" ");
  Serial.println(analog2V(result)); // res

  delay(DELAY);  
  
  // put your main code here, to run repeatedly:

}

void testValues(){
  const int values[] = {
  1,200, 400, 600, 700
};

    int valuesLen = 5;
  int loops = 3*(valuesLen-1);

    for(int i=0; i<loops ;i++){
    int index = i%(valuesLen-1);
    int value = opAmp.operate(values[index+1], values[(index)]);
    Serial.print(values[index]*.1);
    Serial.print(" ");
    Serial.print(values[index+1]*.1);
    Serial.print(" ");
    Serial.println(value*.1);
    }
}
