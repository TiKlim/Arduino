#define BUZZER_PIN 3
#define LDR_PIN  A0

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  int val, frequency;
  val = analogRead(LDR_PIN);
  frequency = map(val, 0, 1023, 2500, 5000);

  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  tone(BUZZER_PIN, frequency, 20);
  delay(80);
  
}

void loop(){ 
}