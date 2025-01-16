#define LAMP_PIN 4
#define PUMP_PIN 2
void setup() {
Serial.begin(9600);
pinMode(LAMP_PIN, OUTPUT);
pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LAMP_PIN, HIGH);
  delay(2000);
  digitalWrite(LAMP_PIN, LOW);
  digitalWrite(PUMP_PIN, HIGH);
  delay(2000);
  digitalWrite(PUMP_PIN, LOW);
}
