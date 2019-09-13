#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;    
int ledPin = 13;      
int sensorValue = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  sensorValue = analogRead(sensorPin);
  lcd.print(sensorValue);
  
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  delay(10);
  lcd.clear();
  
}
