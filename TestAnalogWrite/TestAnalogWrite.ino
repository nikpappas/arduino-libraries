void setup() {
  Serial.begin(9600);
  Serial.println("Vout");
  // put your setup code here, to run once:

}

void loop() {
  analogWrite(9, 100);
  
  delay(50);
  // put your main code here, to run repeatedly:

}
