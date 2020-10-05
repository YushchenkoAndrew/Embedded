void setup()
{
  pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}
void OY()
{

  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,1);

}
void UP()
{
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,1);
  delay(2);
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);
  delayMicroseconds(50);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
}
void DOWN()
{
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);
  delay(2);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,1);
  delayMicroseconds(50);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
}
void loop()
{
  for (int i=0; i<5; i++)
  {
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);

  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,1);

  delay(1);
 
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);

  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);
  delayMicroseconds(100);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  delayMicroseconds(100);
  }

  for (int i=0; i<5; i++)
  {
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);


  delay(1);
 
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);

  delayMicroseconds(100);

  
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  delayMicroseconds(100);
  }

  
  for (int i=0; i<8; i++)
  {
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);

  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);

  delay(1);
 
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);

  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,1);
  delayMicroseconds(100);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  delayMicroseconds(100);
  }
  
  
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);
  
  delay(30);


}

