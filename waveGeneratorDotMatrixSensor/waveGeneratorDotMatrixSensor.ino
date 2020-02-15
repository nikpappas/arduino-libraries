#include <LedMonitor.h>
#include <LedControl.h>

const int TONE_IN = A1;
const unsigned long delayTime=70;  // Delay between Frames
const LedControl lc = LedControl(13, 10, 11, 1);  // Pins: DIN,CLK,CS, # of Display connected
LedMonitor lm = LedMonitor(TONE_IN, delayTime, lc);
const int in = A0;
const int VCC = 8;
const int TONE_OUT = 5;

//int current=0;


double frequency = 1;
//bool isHigh = true;
//unsigned long lastSwapped = millis();


unsigned long now;
// Put values in arrays

 
void setup() {
  Serial.begin(9600);
  pinMode(in, INPUT_PULLUP);
  pinMode(TONE_IN, INPUT_PULLUP);
  pinMode(VCC, OUTPUT);
  pinMode(TONE_OUT, OUTPUT);
  digitalWrite(TONE_OUT, HIGH);
  digitalWrite(VCC, HIGH);
  lm.init();
  lm.tick(0);
  delay(200);
  Serial.println("frequency current");
  
}
int i=0;
void loop() {
    digitalWrite(VCC, HIGH);

  int freqIn  = analogRead(in);
  frequency = (freqIn -360 )*.1;
  double period = 2*3.14*frequency;
  double current = 0.0;// ANALOG_MAX*(sin(period*(millis()*.001))+1)/2;
//   current =  current + ANALOG_MAX * (cos(period*(millis()*.001))+1)/2;
//  tone(TONE_OUT, frequency);
//  analogWrite(TONE_OUT, scale(current, ANALOG_MAX, DIGITAL_MAX));
//  if(isHigh){
//    digitalWrite(TONE_OUT, HIGH);   
//  }else{
//    digitalWrite(TONE_OUT, LOW);   
//  }
//  unsigned long tempMillis = millis();
//  if(tempMillis-lastSwapped>period){
//    isHigh = !isHigh;
//    lastSwapped = tempMillis;
//  }
  
//  Serial.print(frequency);
//  Serial.print("current");
  Serial.print(frequency);
  Serial.print(" ");
//  Serial.print("current");
  Serial.println(current);
//  Serial.println(lm.value);
  
  lm.tick(current+(i++));
//  lm.tick(analogRead(TONE_IN));
//  Serial.println(value);
  delay(10);
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
