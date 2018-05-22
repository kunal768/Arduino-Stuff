//by KunalKeshavSinghSahni
//I have used L298N, IR module and servo motor for the project
//the IR module is surmounted over the servo motor 
//refer the attached documents for more idea 
//Connections: Ir OUT : D2 --MotorA IN1:D7 IN2:D6  PWM1:D5 ---MotorB IN3:D8 IN4:D9 PWM2:D10 --- Servo pin:D3


#include<Servo.h> //including the servo library
 Servo servo1; //only servo motor in the project

int servoPin = 3;//is later declared with servo1.attach(servoPin)
int servoPos = 0;//initial direction of servo motor and hence of IR module

//Motor A
int motorApin1 = 7;
int motorApin2 = 6;
int pwmPin1 = 5;


//Motor B
int motorBpin1 = 8; 
int motorBpin2 = 9;
int pwmPin2 = 10;


// IR Module
int irPin = 2;
int isObstacle = HIGH;//HIGH means no obstacle
int obstacleCount = 0; //if the path is between O1 to O2 then all odd encounters with Obstacles (1st ,3rd ,5th...) are with O2 and all even encounters with Obstacles(2nd ,4th ,6th...) are with O1


void setup() {
  // put your setup code here, to run once:
   servo1.attach(servoPin);

   pinMode(irPin,INPUT);
   
  //Motor A
  pinMode(motorApin1,OUTPUT);
  pinMode(motorApin2,OUTPUT);
  pinMode(pwmPin1,INPUT);
  analogWrite(pwmPin1,200);//setting speed of rotation initially
  
  //Motor B
  pinMode(motorBpin1,OUTPUT);
  pinMode(motorBpin2,OUTPUT);
  pinMode(pwmPin2,INPUT);
  analogWrite(pwmPin2,200);//setting speed of rotation initially;

  moveForward(); //sets inital direction of movement

}

void loop() {
  // put your main code here, to run repeatedly:
  isObstacle = digitalRead(irPin); //check for obstacle in the path

  if(isObstacle==LOW){
    obstacleCount++;
    rotateIR();    //turns the IR module using servo
    turnDirection(); //reverses the rotation of wheels
  }
    
    
}
//----------------------------------------------------------
void turnDirection(){
  if((obstacleCount%2)!=0){        //all odd obstacles are encountered on obstacle2 so we must move backwards
    moveBackward();
  }
  if((obstacleCount)%2==0){        //all even obstacles are encountered on obstacle1 so we must move forward
    moveForward();
  }
}
 // --------------------------------------------------------
void moveForward(){
  digitalWrite(motorApin1,HIGH);
  digitalWrite(motorBpin1,HIGH);
  digitalWrite(motorApin2,LOW);
  digitalWrite(motorBpin2,LOW);
}
//----------------------------------------------------------
void rotateIR(){
  for(servoPos = 0; servoPos <= 180; servoPos++ ){
    servo1.write(servoPos);
  }
  servoPos = 0; //re-initalisation after rotation of servo
}
//-----------------------------------------------------------
void moveBackward(){
  digitalWrite(motorApin1,LOW);
  digitalWrite(motorBpin1,LOW);
  digitalWrite(motorApin2,HIGH);
  digitalWrite(motorBpin2,HIGH);
  
}
//--------------------------------------------------------------


