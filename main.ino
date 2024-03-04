#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int count = 0;
int swicth = 7;

void setup() {
  lcd.init(); 

  lcd.backlight();

  lcd.clear();
  lcd.print("Count : " + String(count));

  pinMode(swicth, INPUT);
}

void loop() {
  int value = digitalRead(swicth);

  if (value == 0) {
    count = count + 1;

    lcd.clear();

    lcd.print("Count : " + String(count));

    delay(1000);
  }
}