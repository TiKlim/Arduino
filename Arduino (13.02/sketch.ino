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
/*void loop1() { //Точка
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(3 * dotDelay);
}
void loop2() { //Точка
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(3 * dotDelay);
}
void loop3() { //Точка
digitalWrite(ledPin, HIGH);
delay(dotDelay);
digitalWrite(ledPin, LOW);
delay(3 * dotDelay);
}
void loop4() { //Тире
digitalWrite(ledPin, HIGH);
delay(3 * dotDelay);
digitalWrite(ledPin, LOW);
delay(dotDelay);
}
void loop5() { //Тире
digitalWrite(ledPin, HIGH);
delay(3 * dotDelay);
digitalWrite(ledPin, LOW);
delay(dotDelay);
}
void loop6() { //Тире
digitalWrite(ledPin, HIGH);
delay(3 * dotDelay);
digitalWrite(ledPin, LOW);
delay(dotDelay);
}*/