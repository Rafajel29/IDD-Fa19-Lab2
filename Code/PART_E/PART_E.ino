#include <LiquidCrystal.h>
#include "pitches.h"

#define BTN1_PIN 6
#define BTN2_PIN 7
#define BTN3_PIN 9

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

float Time1 = 10;
float Time2 = 10;
int flag = 0;
long int Timer = 0;

void setup()   {
  lcd.begin(16, 2);     
  pinMode(BTN1_PIN, INPUT);
  pinMode(BTN2_PIN, INPUT); 
  pinMode(BTN3_PIN, INPUT);  
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print(Time1);

  lcd.setCursor(8, 0);
  lcd.print(Time2);
  
}

void loop() {
  if(buttonPressed(BTN1_PIN)) {
    flag = 1;
    Timer = millis();
  }
  if(buttonPressed(BTN2_PIN)) {
    flag = 2;
    Timer = millis();
  }
  if (flag == 2){
    Time2 = Time2 - abs((0.001 * (millis() - Timer)));
    Timer = millis();
    lcd.setCursor(8, 0);
    lcd.print(Time2);
    if (Time2 <= 0){
      flag = 3;
    }
  }
  if (flag == 1){
    Time1 = Time1 - abs((0.001 * (millis() - Timer)));
    Timer = millis();
    lcd.setCursor(0, 0);
    lcd.print(Time1);
    if (Time1 <= 0){
      flag = 3;
    }
  }
  if (flag == 3){
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
    Time1 = 10;
    Time2 = 10;
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print(Time1);

    lcd.setCursor(8, 0);
    lcd.print(Time2);
    flag = 0;
  }
  if(buttonPressed(BTN3_PIN)) {
    Time1 = 10;
    Time2 = 10;
    lcd.clear();
    flag = 0;
    
    lcd.setCursor(0, 0);
    lcd.print(Time1);

    lcd.setCursor(8, 0);
    lcd.print(Time2);
  }
}

// Generic function to check if a button is pressed
int buttonPressed(uint8_t button) {
  static uint16_t lastStates = 0;
  uint8_t state = digitalRead(button);
  if (state != ((lastStates >> button) & 1)) {
    lastStates ^= 1 << button;
    return state == HIGH;
  }
  return false;
}
