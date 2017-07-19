  #include<SoftwareSerial.h>

  // Pin assignment

  const int rxPin = 6; // from arduino pin 6 to roomba pin 4
  const int txPin = 4; // from arduino pin 4 to roomba pin 3
  const int ddPin = 5; // from arduino pin 5 to roomba pin 5
  const int trackingPin = 3; // arduino pin 4 for tracking sensor
  const int ledPin = 13; // pin13 built-in led
  int timeCounter = 0;
  
  SoftwareSerial oreo(rxPin, txPin);
  
void setup() {
  pinMode(trackingPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); // Set baud rate to 9600
  delay(50);
  Serial.println("666");

  pinMode (ddPin, OUTPUT);

  oreo.begin(19200); // Set baud rate to 19200

  delay(100);

  if (oreo.available()){
    Serial.println(oreo.read());
  } else{
    Serial.println("We failed");
  }
  
  oreo.write(128);
  Serial.println("Start");

  delay(50);
  
  oreo.write(131);
  Serial.println("Safe");
  timeCounter = 0;
  delay(1000);
}

void loop() {
  Serial.println("Time Counter is " + timeCounter);
  boolean val = digitalRead(trackingPin);
 if (val == LOW) {//It is white
    Serial.println("It is here");
    forwards();
    delay(1);
    timeCounter += 1;
    Serial.println(timeCounter);
  }
  else { //when it is black
    Serial.println(timeCounter);
    spinCl(180);
    forwards();
    delay(timeCounter);
    exit(0);
  }
}

void spinTillYouDrop() {
  oreo.write(145);
  oreo.write(0xff);
  oreo.write(0x38);
  oreo.write(byte(00));
  oreo.write(0xc8);
}

void forwards(){
  Serial.println("Forwards");
/*
  oreo.write(145);
  oreo.write(highByte(0));
  oreo.write(lowByte(100));
  oreo.write(highByte(0));
  oreo.write(lowByte(100));
  */
  
  oreo.write(145); 
  oreo.write(byte(0));   
  oreo.write(byte(100));
  oreo.write(byte(0));
  oreo.write(byte(100));
  
}

void forwards(int t) {
  Serial.write("Forwards with time");
  forwards();
  //int stopTime = (distance / 0.5) * (1000); // distance / 0.5 (m/s) * 1000(ms/s)
  delay(t); // Time: distance(mm) / velocity (500mm)
  wheelStop();
}

void wheelStop(){
  Serial.println("spinL");
  
  oreo.write(145); 
  oreo.write(byte(00));
  oreo.write(byte(00));
  oreo.write(byte(00));   
  oreo.write(byte(00));
}

void spinCl() {
  oreo.write(145);
  oreo.write(0xff);
  oreo.write(0x38);
  oreo.write(byte(00));
  oreo.write(0xc8);
}

void spinCl(double degrees) {
  spinCl();
  delay(3696 / 360.0 * degrees);
  wheelStop();
}

