
//flame detection sensor and buzzer using Arduino 
int buzzerPin = 12;
int ledPin = 9;
const int minFlame = 0;
const int maxFlame = 1024;
//flame sensor is basically analog
//its pins in the schematic are connected to A0, GND and Vcc
int flamePin = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin,OUTPUT);
  pinMode(flamePin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal=analogRead(flamePin);
int range = map(sensorVal,minFlame,maxFlame,0,3);
  switch(range){
    case(0):
    Serial.println("Too Close!! Danger");
    break;
    case(1):
    Serial.println("Still Danger");
    break;
    case(2):
    Serial.println("No Danger!!");
    break;
  }
  delay(1);
}


  

