#include <Servo.h>

Servo Servo_X;
Servo Servo_Y;
Servo Servo_Grip;

#define Joy_X A0
#define Joy_Y A1
#define BUTTON 2

int Joy_Val = 0;
boolean state = false;

void setup()
{
  Servo_X.attach(3);
  Servo_Y.attach(5);
  Servo_Grip.attach(6);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{

  Joy_Val = analogRead(Joy_X);
  Joy_Val = map(Joy_Val, 0, 1023, 180, 0);
  Servo_X.write(Joy_Val);

  Joy_Val = analogRead(Joy_Y);
  Joy_Val = map(Joy_Val, 0, 1023, 0, 180);
  Servo_Y.write(Joy_Val);
  delay(15);

  if (digitalRead(BUTTON) == LOW) {

    if (state == false) {
      state = true;
      Servo_Grip.write(0);
      delay(500);
    } else {
      state = false;
      Servo_Grip.write(90);
      delay(500);
    }
  }
}