int ledPin = 13; //Номер пина со светидиодом
int dotDelay = 500; //Время длительности точки
void setup() {
pinMode(ledPin, OUTPUT);
}
void loop() { 
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(dotDelay);
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(dotDelay);
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(1000);

digitalWrite(ledPin, HIGH);
delay(3 * dotDelay);
digitalWrite(ledPin, LOW);
delay(3 * dotDelay);
digitalWrite(ledPin, HIGH);
delay(3 * dotDelay);
digitalWrite(ledPin, LOW);
delay(3 * dotDelay);
digitalWrite(ledPin, HIGH);
delay(3 * dotDelay);
digitalWrite(ledPin, LOW);
delay(1000);

digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(dotDelay);
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(dotDelay);
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(1000);
}