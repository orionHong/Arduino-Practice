  const int switchPin = 3;
  const int redLedPin = 11;
  const int greenLedPin = 12;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(switchPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int switchVal;

  switchVal = digitalRead(switchPin);

  if(switchVal == HIGH)
  {
    digitalWrite(redLedPin, HIGH);
    delay(50);
    digitalWrite(greenLedPin, LOW);
    delay(50);
  }
  else
  {
    digitalWrite(greenLedPin, HIGH);
    delay(50);
    digitalWrite(redLedPin, LOW);
    delay(50);
  }
}
