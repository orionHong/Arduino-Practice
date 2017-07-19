  const int sensorPin = 0;
  const int ledPin = 10;

  int lightCal;
  int lightVal;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  lightCal = analogRead(sensorPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(sensorPin);

  if(lightVal < lightCal - 50)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
