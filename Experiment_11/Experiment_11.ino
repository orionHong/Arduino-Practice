const int motorPin = 9;

void setup() {
  pinMode(motorPin, OUTPUT);

}

void loop() {
  motorOnThenOffWithSpeed();

}

void motorOnThenOff()
{
  int onTime = 3000;

  int offTime = 3000;

  digitalWrite(motorPin, HIGH);

  delay(onTime);

  digitalWrite(motorPin, LOW);

  delay(offTime);
}

void motorOnThenOffWithSpeed()
{
  int Speed1 = 250;

  int Time1 = 3000;

  int Speed2 = 80;

  int Time2 = 3000;

  analogWrite(motorPin, Speed1);

  delay(Time1);

  analogWrite(motorPin, Speed2);

  delay(Time2);
}

