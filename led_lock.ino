int ledPin = 0;
int lockPin = 2;
int butPin = 1;
int pressCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(lockPin, OUTPUT);
  pinMode(butPin, INPUT);
}

void loop() {
  if (butPin == HIGH && pressCount == 0){
    digitalWrite(ledPin, HIGH);
    pressCount = 1;
  }
  else if (butPin == LOW && pressCount == 1){
    digitalWrite(ledPin, LOW);
  }
  else if (butPin == HIGH && pressCount == 1){
    digitalWrite(ledPin, HIGH);
    digitalWrite(lockPin, HIGH);
    pressCount == 2;
  }
  else {
    //Nothing, repeat.
  }
}
