//const int pwm = 2 ;    //naming pin 2 as ‘pwm’ variable 
const int adc = A0 ;   //naming pin 0 of analog input side as ‘adc’
int increment = 0;
const int MAX_VALUE = 1023;
void setup()
{
      Serial.begin(9600);
      pinMode(adc, INPUT);
//     pinMode(pwm,OUTPUT) ;  //setting pin 2 as output
}
void loop()
{
//  increment++;
     int adcVal  = analogRead(adc) ;    //reading analog voltage and storing it in an integer 
//     adcVal = map(adc, 0, 1023, 0, 255);  
/*
----------map funtion------------the above funtion scales the output of adc, which is 10 bit and gives values btw 0 to 1023, in values btw 0 to 255 form analogWrite funtion which only receives  values btw this range
*/
//     analogWrite(pwm,adc) ; 
//     if(increment%999==0){
     Serial.println(adcVal);      
//     Serial.plotter(adcVal);      
//     }
//int i=0;
//for(i=5;i>0;i--){
//    if(adcVal > MAX_VALUE/i){
//      digitalWrite(i-4,HIGH);
//    }else{
//      digitalWrite(i-4,LOW);
//    }
//}
    
}
