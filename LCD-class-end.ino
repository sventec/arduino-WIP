#include <LiquidCrystal.h>
#include <avr/sleep.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

const int wakePin = 2;
const int nextPin = 7;
const int sleepPin = 8;

int day = 1;

void wakeUpNow(){
    //this executes before going back to loop after waking up
    if(day <= 3){
        day++;
    }else{
        day = 1;
    }
}

void setup(){
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    
    pinMode(sleepPin, INPUT_PULLUP);
    pinMode(nextPin, INPUT);
    pinMode(wakePin, INPUT_PULLUP);
    attachInterrupt(0, wakeUpNow, LOW);
}

void sleepNow(){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    attachinterrupt(0, wakeUpNow, LOW);
    sleep_mode();
    //This is where the board wakes up
    sleep_disable();
    detachInterrupt(0);
}

void nextLoop(){
    while(nextPin == HIGH && sleepPin == HIGH){
        switch(day){
            case 1:
                lcd.setCursor(0, 0);
                lcd.print("10:00 AM");
                lcd.setCursor(0, 1);
                lcd.print("monday");
                break;
            case 2:
                lcd.setCursor(0,0);
                lcd.print("11:25 AM");
                lcd.setCursor(0, 1);
                lcd.print("tuesday");
                break;
            case 3:
                lcd.setCursor(0, 0);
                lcd.print("12:30 PM");
                lcd.setCursor(0, 1);
                lcd.print("friday");
                break;
            default:
                day = 1;
        }
    }
    return;
}
  
void loop(){
    if(sleepPin == HIGH && nextPin == HIGH){
        nextLoop();
    } else if(sleepPin == HIGH && nextPin == LOW){
                if(day <= 3 && nextPin == LOW){
            day++;
        }else{
            day = 1;
        }
        nextLoop();
    } else if(sleepPin == LOW && nextPin == HIGH){
        sleepNow();
    }
}





