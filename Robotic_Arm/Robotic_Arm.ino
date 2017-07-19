//#include <Servo.h>
#include<SoftwareSerial.h>

//const int analogPin = 0;
//const int servoPin = 6;
const int rxPin = 10; // from arduino pin 10 to roomba pin 4
const int txPin = 11; // from arduino pin 11 to roomba pin 3
const int ddPin = 5; // from arduino pin 5 to roomba pin 5

//int temp;

SoftwareSerial oreo(rxPin, txPin);
//Servo servoo;

void setup() {
  //pinMode(analogPin, OUTPUT);
  //servoo.attach(servoPin);

  //temp = analogRead(analogPin) * (180.0 / 1024.0);

  roomba();
  
}

void loop() {
 // int pos = analogRead(analogPin) * (180.0 / 1024.0);

  //temp = pos;
  //servoo.write(pos);
}

void roomba() {
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

  delay(1000);
  roombaChallenge();
}

void roombaChallenge() {

  forwards(2, 5000);
  spinCCl(96.5);
  forwards(1, 2700);
  spinCCl(95);
  forwards(2, 5000);
  spinCCl(90);
  forwards(1, 2500);
  
}

void spinTillYouDrop() {
  oreo.write(145);
  oreo.write(0xff);
  oreo.write(0x38);
  oreo.write(byte(00));
  oreo.write(0xc8);
}

void spinCl() {
  oreo.write(145);
  oreo.write(0xff);
  oreo.write(0x38);
  oreo.write(byte(00));
  oreo.write(0xc8);
}

void spinCCl() {
  oreo.write(145);
  oreo.write(byte(00));
  oreo.write(0xc8);
  oreo.write(0xff);
  oreo.write(0x38);
}

void spinCl(int degrees) {
  spinCl();
  delay(3700 / 360.0 * degrees);
  wheelStop();
}


void spinCCl(int degrees) {
  spinCCl();
  delay(3700 / 360.0 * degrees);
  wheelStop();
}


void forwards(){
  Serial.print("Forwards");

  oreo.write(145);
  oreo.write(highByte(500));
  oreo.write(lowByte(500));
  oreo.write(highByte(500));
  oreo.write(lowByte(500));
  /*
  oreo.write(145); 
  oreo.write(byte(1));   
  oreo.write(byte(244));
  oreo.write(byte(1));
  oreo.write(byte(244));
  */
}

void forwards(int distance, int time) {
  Serial.write("Forwards with distance");
  forwards();
  //int stopTime = (distance / 0.5) * (1000); // distance / 0.5 (m/s) * 1000(ms/s)
  delay(time); // Time: distance(mm) / velocity (500mm)
  wheelStop();
}

void wheelStop(){
  Serial.print("spinL");
  
  oreo.write(145); 
  oreo.write(byte(00));
  oreo.write(byte(00));
  oreo.write(byte(00));   
  oreo.write(byte(00));
}

  

