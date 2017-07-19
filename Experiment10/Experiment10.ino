#include<Servo.h>

Servo servoo

void setup() {
  //attach servooo to pin 9 on the Arduino 101
  servooo.attach(9);

}

void loop() {
  int position;

  servoo.write(90);

  delay(1000);

  servoo.write(180);

  delay(1000);

  servoo.write(0);

  delay(1000);

  for(position = 180; position >= 0; position -= 1)
  {
    servoo.write(position);

    delay(20);
  }

}
