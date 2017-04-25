#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup(){
    lcd.begin(16, 2);
    
    lcd.print("testing lcd");
}

void loop(){
    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
}