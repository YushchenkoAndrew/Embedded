const byte led=12;
void setup() {
  
pinMode(led,OUTPUT);
}

void loop() {
 digitalWrite(led,HIGH);
 delayMicroseconds(2);
 digitalWrite(led,LOW);
 delayMicroseconds(15);
}
