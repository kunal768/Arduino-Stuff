
int Led= 13;
 int x;

void setup() {
  // put your setup code here, to run once:
  pinMode(Led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()){
    x=Serial.read();
    if(x==1){
      digitalWrite(Led,HIGH);
    }
    if(x==0){
      digitalWrite(Led,LOW);
    }
    delay(1000);
  }

}

