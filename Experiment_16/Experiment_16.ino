int datapin = 2;
int clockpin = 3;
int latchpin = 4;

byte data = 0;

void setup() {
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
}

void loop() {
  oneAfterAnother();

}

void shiftWrite(int desiredPin, boolean desiredState) {
  bitWrite(data, desiredPin, desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data);

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

void oneAfterAnother() {
  int index;
  int delayTime = 1000;

  for (index = 0; index <= 7; index++) {
    shiftWrite(index, HIGH);
    delay(delayTime);
  }

  for (index = 7; index >= 0; index--){
    shiftWrite (index, LOW);
    delay(delayTime);
  }

  for (index = 0; index <= 7; index++) {
    if(index % 2 == 0) {
      shiftWrite(0, HIGH);
      shiftWrite(2, HIGH);
      shiftWrite(4, HIGH);
      shiftWrite(6, HIGH);
      shiftWrite(1, LOW);
      shiftWrite(3, LOW);
      shiftWrite(5, LOW);
      shiftWrite(7, LOW);
    }
  }
}

