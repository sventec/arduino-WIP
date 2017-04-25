//Reed Simon
//Debounce Script
//v1.0.0
//17.24.04

const byte butPin = 1;

void setup(){
    pinMode(butPin, INPUT);
}

byte buttonListen(byte pin){
    byte lastState = LOW;
    byte currentState;
    currentState = digitalRead(pin);
    if (currentState == HIGH){
        delay(30);
        if(digitalRead(pin) == HIGH && lastState == LOW){
            lastState = LOW;
            return(HIGH);
        } else{}
    } else{}
}