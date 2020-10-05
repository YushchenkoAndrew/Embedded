 byte a[500]={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};

void setup() {
  input();

digitalWrite(14,1);
digitalWrite(15,0);
digitalWrite(16,1);

digitalWrite(17,0);
digitalWrite(18,0);
digitalWrite(19,1);
digitalWrite(19,0);

digitalWrite(10,1);
digitalWrite(11,0);

Serial.begin(250000);

  writes();

pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);


digitalWrite(16,0);
digitalWrite(15,0);
digitalWrite(14,1);
delay(1);

digitalWrite(19,1);
digitalWrite(19,0);


for (int i=0; i<=255;i++)
{
delay(1);

Serial.print(digitalRead(2));
Serial.print(digitalRead(3));
Serial.print(digitalRead(4));
Serial.print(digitalRead(5));
Serial.print(digitalRead(6));
Serial.print(digitalRead(7));
Serial.print(digitalRead(8));
Serial.print(digitalRead(9), "  --  ");
Serial.print(digitalRead(2)*1+digitalRead(3)*2+digitalRead(4)*4+digitalRead(5)*8+digitalRead(6)*16+digitalRead(7)*32+digitalRead(8)*64+digitalRead(9)*128, HEX);
Serial.print("   ==   ");
Serial.println(i);

  digitalWrite(17,1);
   delay(1);
  digitalWrite(17,0);
   delay(1);
  digitalWrite(17,1);
}

digitalWrite(10,0);
digitalWrite(11,1);
}
void input()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
}

void writes()
{ 
  digitalWrite(15,1);
  digitalWrite(14,1); 
  delay(1);
  
for (int i=0; i<=255; i++)
{
  digitalWrite(16,0);
  digitalWrite(14,0);
  delay(1);
  

  digitalWrite(2,bool(a[i] & 1));
  digitalWrite(3,bool(a[i] & 2));
  digitalWrite(4,bool(a[i] & 4));
  digitalWrite(5,bool(a[i] & 8));
  digitalWrite(6,bool(a[i] & 16));
  digitalWrite(7,bool(a[i] & 32));
  digitalWrite(8,bool(a[i] & 64));
  digitalWrite(9,bool(a[i] & 128));
  delay(1);


  digitalWrite(14,1); 
  delay(1);
  digitalWrite(16,1);
  delay(1);


  digitalWrite(17,0);
   delay(1);
  digitalWrite(17,1);
   delay(1);
  digitalWrite(17,0);
  delay(1);

}
digitalWrite(15,0);
delay(1);

}

void loop() {


}
