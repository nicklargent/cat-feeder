#include <Stepper.h>

const int stepsPerRevolution = 2050;  

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int const buttonPin = 6;

void setup() {
    myStepper.setSpeed(8);
}

void vibrate(int times) {
  myStepper.setSpeed(12);
  for (int i=0; i<times; i++) {
    myStepper.step(-45);
    delay(10);
    myStepper.step(45);
    delay(10);
  }
  myStepper.setSpeed(4);
}

void dispense() {
  vibrate(3);
  myStepper.step(-250);
  delay(10);
  for (int i=0; i<5; i++) {
    vibrate(3);
    myStepper.step(250);
    delay(10);
  }
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void loop() {
  dispense();
  //delay(14400000);  // 4 hours
  delay(10800000);   // 3 hours
  //delay(300000);   // 5 min
  //delay(30000);    // 30 sec
  //delay(5000);     // 5 sec
}
