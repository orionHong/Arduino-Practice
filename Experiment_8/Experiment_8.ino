  const int redPot = 0;
  const int greenPot = 1;
  const int bluePot = 2;

  const int redPin = 12;
  const int greenPin = 11;
  const int bluePin = 10;

  int redVal;
  int greenVal;
  int blueVal;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  redVal = analogRead(redPot);
  greenVal = analogRead(greenPot);
  blueVal = analogRead(bluePot);

  redVal = map(redVal, 0, 1023, 0, 255);
  greenVal = map(greenVal, 0, 1023, 0, 255);
  blueVal = map(blueVal, 0, 1023, 0, 255);

  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
