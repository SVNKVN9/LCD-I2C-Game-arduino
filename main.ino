#include <stdlib.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int score = 0;
int swicth = 7;

int row = 0;

int mon_row = 0;
int mon_col = 16;

int win = 20;
int isLose = 0;
int isWon = 0;
int step_to_move = 250;
int current_step = 0;

void setup() {
  lcd.init(); 

  lcd.backlight();

  pinMode(swicth, INPUT);
}

void process() {
  if (current_step <= step_to_move) {
    current_step += 1;

    return;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score " + String(score));

  lcd.setCursor(8, row);
  lcd.print(">");

  if (mon_col == 8 && mon_row == row) { // Loss
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("You LOSS");

    isLose = 1;
    return;
  } else if (mon_col == 8 && mon_row != row) { // Reset State
    score += 1;
    mon_col = 16;
    if (step_to_move <= 75) {
      step_to_move = 75;
    } else {
      step_to_move = step_to_move - 15;
    }
    
    mon_row = rand() % 2;

    if (score == win) {
      isWon = 1;
    }
  }

  lcd.setCursor(mon_col, mon_row);
  lcd.print("<");

  mon_col -= 1;
  current_step = 0;
}

void onSwitch() {
  int value = digitalRead(swicth);

  if (value == 1) {
    return;
  }

  if (row == 0) {
    row = 1;
  } else {
    row = 0;
  }

  delay(300);
}

void loop() {
  onSwitch();

  if (isWon == 1) {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("You WIN");
    
    delay(5000);

    return;
  }

  if (isLose == 0) {
    process();
  }

  delay(1);
}