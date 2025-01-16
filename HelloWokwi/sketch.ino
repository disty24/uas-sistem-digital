//Library
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 7
#define ECHO_PIN 8

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();

 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);

}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int durasiPantulan = pulseIn(ECHO_PIN, HIGH);
  float jarak = durasiPantulan *0.034/2;
  float jarakM = jarak/100;

  lcd.setCursor(0, 0);
  lcd.print("Jarak : ");
  lcd.print(jarak);
  lcd.print("cm");

  lcd.setCursor(0,1);
  lcd.print("jarakM : ");
  lcd.print(jarakM);
  lcd.print("M");
}