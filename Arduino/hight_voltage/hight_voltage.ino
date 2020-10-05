bool q=1;
void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
  digitalWrite(2,0);
  digitalWrite(3,0);
}

void loop() {
  digitalWrite(2,q);
  digitalWrite(3,!q);
  delayMicroseconds(1);
  q=!q;

}
