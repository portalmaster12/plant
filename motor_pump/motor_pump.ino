#include <Average.h>

// Reserve space for 10 entries in the average bucket.
// Change the type between < and > to change the entire way the library works.

Average<int> moistoure(12);

const int switchPin =2;
const int motorPin =10;
int switchstate = 0;
const int Input = A5;
//float moistoure[]{0,0,0,0,0,0,0,0,0,0,0,0};
//int ByteRecieved;
int death =0;
int average =  0;




void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode (Input, INPUT);
  Serial.begin(9600);
  Serial.println(analogRead(Input));
  
} 

void loop(){
  moistoure.push(analogRead(Input));
switchstate = digitalRead(switchPin);
average = moistoure.mean();
 delay(83);
 //Serial.println(switchstate);
 death++;
 if (death >11){
   death = 0;
 }
  if (switchstate == HIGH | average < 642 {
    digitalWrite(motorPin, HIGH);

  }
  else{
    digitalWrite(motorPin,LOW);
  
  }

  if(death==11){
    //ByteRecieved = Serial.read();
    //Serial.write('Average:::');
    Serial.println(average);
    
  }
 
}


