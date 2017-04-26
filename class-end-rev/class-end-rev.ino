//Reed Simon
//v2.1.0
//17.04.26

#include <LiquidCrystal.h>
#include <avr/sleep.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

const byte nextPin = 7; //BUTTON to advance to NEXT DAY manually
const byte wakePin = 2; //BUTTON to WAKE arduino from sleep, on an INTERRUPT pin
const byte sleepPin = 8; //BUTTON to call the sleepNow() function, PUTS DEVICE TO SLEEP

int day = 1;
volatile int daySave = day;

void setup(){
    lcd.begin(16,2);

    pinMode(nextPin, INPUT); //Attached to external PULLUP resistor
    pinMode(wakePin, INPUT_PULLUP); //Uses internal pullup resistor
    pinMode(sleepPin, INPUT);

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

void wakeNow(){ //This runs after sleep before anything else, no delay() here
    day = daySave;
    //lcd.display(); //REPLACE WITH TURN ON DISPLAY COMMAND
}

void sleepNow(){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    attachInterrupt(0, wakeNow, LOW); //Listening for the wakePin button to go LOW, then runs wakeNow()
    daySave = day;
    sleep_mode();
    //This is where the board wakes up
    sleep_disable();
    detachInterrupt(0);
}

void loop(){
    if(digitalRead(sleepPin == LOW)){
        //lcd.noDisplay(); //REPLACE WITH DISPLAY OFF COMMAND
        sleepNow();
    } else{
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
                } else if(day == 4){
                    lcd.print("Press once more");
                    lcd.setCursor(0, 1);
                    lcd.print("to reset week");
                }
            }
        }
    }
}
