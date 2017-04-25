//Reed Simon
//1.0.1
//17.04.25

#include <LiquidCrystal.h>
#include <avr/sleep.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

const int nextPin = 7;

int day = 1;

void setup(){
    lcd.begin(16,2);
    
    pinMode(nextPin, INPUT);
    
    if(day == 1){
        lcd.print("10:00 AM");
        lcd.setCursor(0, 1);
        lcd.print("Monday");
    } else if(day == 2){
        lcd.print("11:25 AM");
        lcd.setCursor(0, 1);
        lcd.print("Tuesday");
    } else if(day == 3){
        lcd.print("12:30 PM");
        lcd.setCursor(0, 1);
        lcd.print("Friday");
    }
}

void loop(){
    if(digitalRead(nextPin) == LOW){
        delay(100);
        if(digitalRead(nextPin) == LOW){
            lcd.clear();
            if(day < 4){
                day++;
            } else if(day >= 4){
                day = 1;
            }
            if(day == 1){
                lcd.print("10:00 AM");
                lcd.setCursor(0, 1);
                lcd.print("Monday");
            } else if(day == 2){
                lcd.print("11:25 AM");
                lcd.setCursor(0, 1);
                lcd.print("Tuesday");
            } else if(day == 3){
                lcd.print("12:30 PM");
                lcd.setCursor(0, 1);
                lcd.print("Friday");
            }
        }
    }
}