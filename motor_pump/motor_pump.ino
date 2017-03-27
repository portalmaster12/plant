const int switchPin =2
const int motorPin =9
int switchstate =0

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchpin, INPUT);
}

void loop() {
  switchstate = digitalRead(switchPin);
  
  if (switchstate == HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin,LOW)
  }
}
