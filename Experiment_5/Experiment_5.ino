  // pushbutton pin
  const int buttonPin = 3;

  //RGB LEG pins
  const int redPin = 11;
  const int greenPin = 12;
  const int bluePin = 9;

  //create a variable to stroe a counter and set it to 0
  int counter = 0;

void setup() {
  // Set up the pushbutton pins to be an input
  pinMode(buttonPin, INPUT);

  // Set up the RGB pins to be an outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // local variable to hold the pushbutton states
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) //light the LED
  {
    counter++;
    delay(50);
  }

  if(counter == 0) //pins are off
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  else if (counter == 1) //redPin is HIGH
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  else if(counter == 2) //greenPin is HIGH
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }

  else if(counter == 3) //bluePin is HIGH
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
  else //else reset the counter to 0 (turning off all the pins)
  {
    counter = 0;
  }
}
