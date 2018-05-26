//by KunalKeshavSinghSahni
//this is my first code using Joystick Module
//basically controls two Servo motors using Joystick Module

  //Servo values
#include<Servo.h>
 Servo servo1;
 Servo servo2;
 int servo1Pos = 0; 
 int servo2Pos = 0; //inital position for both servos 

 //Joystick values
int pinX = A0;
int pinY = A1;
int valueX = 128;  // center position for joystick X direction (mean value for range from 0-256)
int valueY = 128;  // center position for joystick Y direction (mean value for range from 0-256)



void setup() {
  // put your setup code here, to run once:
  servo1.attach(8);
  servo2.attach(9);
  pinMode(pinX ,INPUT);
  pinMode(pinY ,INPUT);
  servo1.write(servo1Pos);
  servo2.write(servo2Pos);
  
}

void loop() {
            
   valueX = analogRead(pinX);  //reads value for X direction and controls servo 1
  
  // for movement along positive X 
  if(valueX > 128){
    valueX = map(valueX , 0 , 256 , 128 , 256);
    servo1.write(valueX);
    delay(15);
  }
  
  // for movement along negative X
  if(valueX < 128){
    valueX = map(valueX , 0 , 256 , 0 , 128);
    servo1.write(valueX);
    delay(15);
  }

   valueY = analogRead(pinY); //reads value for Y direction and hence controls servo 2
  
  // for movement along positive Y
  if(valueY >128){
   valueY = map(valueY , 0 , 256 , 128 , 256);
   servo2.write(valueY);
   delay(15);
  }
   
  // for movement along negative Y
  if(valueY < 128){
    valueY = map(valueY , 0 , 256 , 0 , 128);
    servo2.write(valueY);
    delay(15);
  }
  
}
