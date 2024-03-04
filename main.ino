#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int count = 1;

void setup() {
  lcd.init(); 

  lcd.backlight();
  lcd.setCursor(3,0);
  // lcd.print("Hello, world!");
  // lcd.setCursor(2,1);
  // lcd.print("Ywrobot Arduino!");
}

void loop() {
  delay(1000);
  lcd.clear();

  lcd.print("Count : " + String(count));

  count = count + 1;
}