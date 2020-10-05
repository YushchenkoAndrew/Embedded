boolean now=LOW;
boolean last=LOW;
byte i=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(14,INPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  
  now=digitalRead(14);
  if ((now == LOW)&&(last == HIGH))
  i++;
  switch(i)
  {
    case 1:
           digitalWrite(4,HIGH);
           digitalWrite(5,LOW);
           digitalWrite(6,LOW);
           digitalWrite(7,LOW);
           break;
    case 2:
           digitalWrite(4,HIGH);
           digitalWrite(5,HIGH);
           digitalWrite(6,LOW);
           digitalWrite(7,LOW);
           break;
    case 3:
           digitalWrite(4,LOW);
           digitalWrite(5,HIGH);
           digitalWrite(6,HIGH);
           digitalWrite(7,LOW);
           break;
    case 4:
           digitalWrite(4,LOW);
           digitalWrite(5,LOW);
           digitalWrite(6,HIGH);
           digitalWrite(7,HIGH);
           i=0;
           break;
  }
 last=now;

}
