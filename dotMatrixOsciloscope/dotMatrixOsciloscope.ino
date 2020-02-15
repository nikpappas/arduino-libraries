
#include "led.h"

LedControl lc=LedControl(13,10,11,1);  // Pins: DIN,CLK,CS, # of Display connected
const int in = A0;
const int VCC = 8;


const int ANALOG_MAX = 1023;
const int LEVEL_COUNT = 8;

double frequency = 1;

unsigned long delayTime=50;  // Delay between Frames

unsigned long lastRendered;
unsigned long now;
// Put values in arrays
byte screenBuffer[] =
{
   B00010000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};
// Put values in arrays
byte screenResult[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};
byte levels[] ={
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000
};

//void printBuffer(){
//  for(int i=0; i < LEVEL_COUNT; i++){
//    Serial.println(screenBuffer[i], BIN);
//  }
//}
 
void setup() {
  Serial.begin(9600);
  pinMode(in, INPUT_PULLUP);
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC, HIGH);
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
  int current  = analogRead(in);
  byte value = currentToByte(current);
  screenBuffer[0] = value;

}
void tick() {
  lastRendered = millis();
  int freqIn  = analogRead(in);
  frequency = (freqIn -200 )/200;
  double period = 2*3.14*frequency;

//  int current =  ANALOG_MAX*(sin(period*(lastRendered*.001))+1)/2;
  int current =  current + ANALOG_MAX*(cos(period*(lastRendered*.001))+1)/2;
  byte value = currentToByte(current);
//  Serial.println(current);
//  Serial.println(value);
  screenBuffer[0] = value;
  draw();
  clone(screenBuffer, screenResult, LEVEL_COUNT);
  shiftLeft(screenBuffer, screenResult, LEVEL_COUNT);
}
void draw() {
  for (int i = 0; i < LEVEL_COUNT; i++) {
    lc.setRow(0,i,screenBuffer[i]);
  }
}

byte currentToByte(int current){
  int quantizedValue = floor((1.0*current*LEVEL_COUNT)/ANALOG_MAX);
  Serial.println(quantizedValue);
  return levels[quantizedValue];
}

void loop() {
  tick();
  unsigned long diff = millis() - lastRendered;
//  lastRendered = millis();
//  Serial.println(diff);
//  if (diff>0){
//    delay(delayTime-diff);  
//  } else {
    delay(delayTime-diff);
//  }
  
}



//Alternative linked copy()
//byte i = 5; // good to 255 elements
//while ( i-- ) *( dest + i ) = *( src + i ); // dest and src are your 2 array names

//
//void copyA(int* src, int* dst, int len) {
//    memcpy(dst, src, sizeof(src[0])*len);
//}
//
//void copyB(int* src, int* dst, int len) {
//    for (int i = 0; i < len; i++) {
//        *dst++ = *src++;
//    }
//}
