#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
HX711 scale;

void setup()
{
  lcd.init();
  scale.begin(PA3, PA2);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
 
}

void loop()
{
  if (scale.wait_ready_timeout(1000)) {
    long reading = scale.read();
    lcd.setCursor(0,0);
    lcd.print("ADC HX711");
    lcd.setCursor(0,1);
    lcd.print(reading);
  } else {
    Serial.println("HX711 not found.");
  }

  
  lcd.clear();
}