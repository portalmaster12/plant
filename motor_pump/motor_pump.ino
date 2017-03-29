const int switchPin =2;
const int motorPin =9;
int switchstate = 0;
const int Input = 12;
int moistoure = 0;
//int ByteRecieved;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode (Input, INPUT);
//  Serial.begin(9600);
//  Serial.println(digitalRead(Input));
} 

void loop(){
moistoure = digitalRead(Input);
switchstate = digitalRead(switchPin);
 
  if (moistoure >85) {
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin,LOW);
  }

  
//  if(Serial.available()>0){
    //ByteRecieved = Serial.read();
//    Serial.println(moistoure);
//  }
 
}

