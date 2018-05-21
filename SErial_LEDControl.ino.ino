/* this is yet another sketch. Im currently 
short of ideas(and tools) so i decide lets communicate with an LED via serial monitor communication
I find it respectable enough to begin with. Leave your comments later*/
//connecting the Led between 13 and ground
int ledPin = 13;
String message;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   message=Serial.readString();
   if(message=="ON"){
    digitalWrite(ledPin,HIGH);
    Serial.println("The LED is now on");
   }
   if(message=="OFF"){
    digitalWrite(ledPin,LOW);
    Serial.println("The LED is now off");
   }

}
