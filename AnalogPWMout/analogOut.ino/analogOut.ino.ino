const int pwm = 2 ;     //initializing pin 2 as ‘pwm’ variable
const int simple = 3 ;     //initializing pin 2 as ‘pwm’ variable
void setup()
{
     pinMode(pwm,OUTPUT) ;  //Set pin 2 as output
     pinMode(simple,OUTPUT) ;  //Set pin 2 as output
}
void loop()
{
  int i;
  int increments = 25;
  int delayTime = 500;
  for(i = 0;i<11;i++){
     analogWrite(pwm,i*25) ;     //setting pwm to 25 
     analogWrite(simple,i*25) ;     //setting pwm to 25 
     delay(delayTime);
  }
}
