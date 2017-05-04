//Reed Simon
//2017
//Beauty and the Beast, Proctor Academy, Spring Term 2016-17
//Mini-servos, arduino nano, drone controller
//1.11

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

//Debounce type thing
bool trig1 = FALSE;
bool trig2 = FALSE;
bool trig3 = FALSE;

//Initialize servos 1-3
Servo servo1;
Servo servo2;
Servo servo3;



void setup()
{
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

    //Reset all servos
    servo1.write(0);
    servo2.write(0);
    servo3.write(0);
}

void loop()
{

    if(digitalRead(rec1) == HIGH || digitalRead(rec2) == HIGH || digitalRead(rec3) == HIGH){
        if(digitalRead(rec1) == HIGH){
            if(trig1 == FALSE){
                servo1.write(90);
                trig1 = TRUE;
                delay(50);
            }
        }

        else if(digitalRead(rec2) == HIGH){
            if(trig2 == FALSE){
                servo2.write(90);
                trig2 = TRUE;
                delay(50);
            }
        }

        else if(digitalRead(rec3) == HIGH){
            if(trig3 == FALSE){
                servo3.write(90);
                trig3 = TRUE;
                delay(50);
            }
        }

        else
        {

        }
        delay(30); //no need to be constantly checking/looping
    }
}
