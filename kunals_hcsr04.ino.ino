//this is my initialisation for HCSR04 Code(ULTRASONIC INTERFACE)
//by KUNALKESHAVSINGHSAHNI (fuck Camelcasing)
int trigPin=12;
int echoPin=11;
int ledPin=13;
void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(ledPin,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //to clear trigPin first
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  //cleared--------------------
  digitalWrite(trigPin,HIGH);//starting trigPin
  delayMicroseconds(10);//10us delay
  float duration=pulseIn(echoPin,HIGH);//remember Echo Pin always Connected to PWM input for this very reason!!!! "#pulseIn" returns time
  //now formula for caclulating distance
  int distance = (duration/2)*0.034;
  if(distance>4){
    digitalWrite(ledPin,HIGH);
    Serial.print("BHai AARAM SE!!");
  }
  Serial.println(distance); 

}
