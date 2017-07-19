void setup() {
  //set pin 10 to OUTPUT
  
  pinMode(10, OUTPUT);
  
}

void loop() {
  // Turn pin 10 HIgh (ON).
  digitalWrite(10, HIGH);

  // Wait 1000 millisenconds (1 second).
  delay(1000);

  digitalWrite(10, LOW);

  delay(1000);

}
