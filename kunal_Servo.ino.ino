//this is my first motor work....best thing im starting with a Servo Motor
//by KunalKeshavSinghSahni
//Servo pins are connected to D2, 5V and GND
//we need to include the Servo Library
#include<Servo.h>
int motorPin = 2;//declaring the motor pin(optional) because it is declared during attach
int ledPin = 13;
int pos=0;
Servo kunalServo;//need to create an object
void setup() {
  pinMode(ledPin,OUTPUT);
  // put your setup code here, to run once:
  kunalServo.attach(motorPin);//automatically works for pinMode thing
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
    kunalServo.write(0);//0 degrees
    delay(1000);
    kunalServo.write(90);//moves to 90 degrees
    delay(1000);
    kunalServo.write(180);//moves to 180 degreea
    delay(1000); */
  for ( pos = 0; pos <= 180; pos++) {
    kunalServo.write(pos);
    delay(15);
    digitalWrite(ledPin,HIGH);
  }
  
  for ( pos = 180; pos >= 0; pos--) {
    kunalServo.write(pos);
    delay(15);
    digitalWrite(ledPin,LOW);
  }
}
