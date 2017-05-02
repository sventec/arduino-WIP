//Reed Simon
//2017
//Beauty and the Beast, Proctor Academy, Spring Term 2016-17
//Mini-servos, arduino nano, drone controller
//1.00

#include <Servo.h> //Servo library

/*  ONLY USE THIS IF THE INPUTS OF THE JOYSTICKS ARE VARIABLE
#define rec1 A0
#define rec2 A1
#define rec3 A2
*/

//Pin INPUTs from RC Reciever
const byte rec1 = 3;
const byte rec2 = 4;
const byte rec3 = 5;

//Pin OUTPUTS to Servo control pins
const byte sPin1 = 7;
const byte sPin2 = 8;
const byte sPin3 = 9;

//Initialize servos 1-3
Servo servo1;
Servo servo2;
Servo servo3;


byte dread(byte pin){
    return digitalRead(pin);
}

void setup(){
    //Init reciever pins as digital inputs
    pinMode(rec1, INPUT);
    pinMode(rec2, INPUT);
    pinMode(rec3, INPUT);

    //Init servo pins as digital outputs
    pinMode(servo1, OUTPUT);
    pinMode(servo2, OUTPUT);
    pinMode(servo3, OUTPUT);

    //Attach servo pins to their respective servos
    servo1.attach(sPin1);
    servo2.attach(sPin2);
    servo3.attach(sPin3);
}

void loop(){
    if(dread(rec1) == HIGH || dread(rec2) == HIGH || dread(rec3) == HIGH){
        if(dread(re1) == HIGH){
            servo1.write(/*VALUE*/);
            delay(50);
        } else if(dread(rec2) == HIGH){
            servo2.write(/*value*/);
            delay(50);
        } else if(dread(rec3) == HIGH){
            servo3.write(/*value*/);
            delay(50);
        }
        delay(30); //debouncing / power saving measure, no need to constantly check.
    }
}
