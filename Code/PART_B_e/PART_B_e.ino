#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;    
int ledPin = 13;      
int sensorValue = 0;
float Voltage_Value = 0;
String Voltage_String;
String equal;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  equal = '=';
}

void loop() { 
  sensorValue = analogRead(sensorPin);
  Voltage_Value = sensorValue * (5.0 / 1023.0);
  Voltage_String = String(Voltage_Value) + 'V';
  
  
  lcd.setCursor(0, 0);
  lcd.print(sensorValue);

  lcd.setCursor(5, 0);
  lcd.print(equal);

  lcd.setCursor(7, 0);
  lcd.print(Voltage_String);
  
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  delay(200);
  lcd.clear();
  
}
