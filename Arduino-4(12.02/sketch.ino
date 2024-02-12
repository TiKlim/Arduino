void setup() {
pinMode(4, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(4, HIGH); //Включить LED
delay(1000);
digitalWrite(4, LOW);
delay(1000); 
}
