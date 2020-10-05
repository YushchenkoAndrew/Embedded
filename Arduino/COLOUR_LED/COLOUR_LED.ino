int colour[3][16]={
  {255,255,0,  255,  0,    122,  83,},//B
  {255,0,  255,120,  255,  122,  83,},//G
  {0,  255,255,0,    0,    255,  83,},//R
};
int i=0;
int j=-1;
int number=0;
void setup()
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
}
void loop()
{
  if (millis()% 1000 == 0){
    j++;
    if (j == 7) j=0;
  digitalWrite(3,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
 // delay(1);
  }

  analogWrite(3,colour[0][j]);
  delayMicroseconds(350);
  digitalWrite(3,1);
  
  analogWrite(5,colour[1][j]);
  delayMicroseconds(350);
  digitalWrite(5,1);
  
  analogWrite(6,colour[2][j]);
  delayMicroseconds(350);
  digitalWrite(6,1);
 // delayMicroseconds(1);
}

