  const int tempPin = 0; //Analog input pin

  int tempVal;

  float volts;

  float tempC;
  float tempF;
  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempVal = analogRead(tempPin);

  Serial.print("TempVal = ");
  Serial.print(tempVal);

  Serial.print(" **** ");

  volts = tempVal * 3.3;
  volts /= 1023.0;

  Serial.print("Volts: ");
  Serial.print(volts, 3);

  Serial.print(" *** ");

  tempC = (volts - 0.5) * 100;

  Serial.print(" degrees C: ");
  Serial.print(tempC);

  Serial.print(" *** ");

  tempF = (tempC * 9.0 / 5.0) + 32.0;

  Serial.print(" degrees F: ");
  Serial.println(tempF);

  delay(1000);
}
