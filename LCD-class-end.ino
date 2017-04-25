#include <LiquidCrystal.h>
#include <avr/sleep.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

const int wakePin = 2;

void wakeUpNow(){
    //this executes before going back to loop after waking up
}

void setup(){
    lcd.begin(16,2);
    
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
  
void loop(){
    
    
    
}  