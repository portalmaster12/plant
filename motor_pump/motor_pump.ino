/*
TSA microcontroller
Watering system code
Ethan Bartlett 
git hub link:
https://www.github.com/portalmaster12/plant/
 */
 
//Includes Average library to make caculating averages 10x easier
#include <Average.h>

//names the set of measures for calculating the mean and states it
//has 12 entries
Average<int> moistoure(12);
//code for which pin the button input comes from
const int switchPin =2;
//code for which pin outputs control to the motor/pump
const int motorPin =10;
//variable to tell whether button is pushed
int switchstate = 0;
//moisture sensor analog input
const int Input = A5;
//says when to check moisture sensor to make 12 readings
//~1 second
int counter =0;
//integer to hold the mean calculation
int average =  0;

//set up arduino board
//declares which pins are inputs, outputs, and
//sets up reading on serial monitor for moisture data
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode (Input, INPUT);
  Serial.begin(9600);
  Serial.println(analogRead(Input));
} 

//has the code that runs the process
void loop(){
  //adds moisture reading to mean list
  moistoure.push(analogRead(Input));
  //tell whether button is pressed
  switchstate = digitalRead(switchPin);
  //calculate average of moisture readings
  average = moistoure.mean();
  //take reading every ~1/12 of a second and adds 1 to counter
  delay(83);
  counter++;
  //reset counter after ~1 second and continue code
  if (counter >11){
     counter = 0;
  }
  //turn on pump if water is low or button is pushed
  if (switchstate == HIGH | average < 642) {
      digitalWrite(motorPin, HIGH);
  }
  else{
      digitalWrite(motorPin,LOW);
  }
  //write average readings every second to serial monitor for 
  //troubleshooting
  if(counter==11){
    Serial.println(average);
    
  }
 
}


