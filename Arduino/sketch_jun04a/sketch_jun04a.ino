void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char a = Serial.read();
    if (a == 'q')
      digitalWrite(7, 0);
    if (a == 'Q')
    digitalWrite(7, 1);
  }
}
