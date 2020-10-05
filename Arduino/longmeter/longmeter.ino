byte a[11];
byte b[3];
float q=0;
float om;
boolean now=false;
int last;
boolean u;
byte pluse=0;
boolean k=HIGH;
byte p=1;
int j;
float volt;
float amper;
byte g=12;
byte h=13;
String str;
int mass()
{
  a[0]=0b1000000;
  a[1]=0b1111001;
  a[2]=0b0100100;
  a[3]=0b0110000;
  a[4]=0b0011001;
  a[5]=0b0010010;
  a[6]=0b0000010;
  a[7]=0b1011000;
  a[8]=0b0000000;
  a[9]=0b0010000;
}
int led(byte e)
{
  for (byte i=0; i<=7; i++)
  {
    boolean s=bitRead(a[e],i);
    digitalWrite(i+5,s);
  }
}
int chislo(int c)
{
  byte w;
  byte z=c%10;
  c=c/10;
  int x=c%10;
  c=c/10;
  
  if ((x == 0)&&(c == 0))
    w=1;
  else if (c == 0)
    w=2;
  else
w=3;
if (w == 1)
{
  digitalWrite(b[2],HIGH);
    led(z);
    delay(6);
    digitalWrite(b[2],LOW);
}
else if (w == 2)
{
  digitalWrite(b[2],HIGH);
    led(z);
    delay(6);
    digitalWrite(b[2],LOW);
    digitalWrite(b[1],HIGH);
    led(x);
    delay(6);
    digitalWrite(b[1],LOW);
}
else if (w == 3)
{
  digitalWrite(b[2],HIGH);
    led(z);
    delay(6);
    digitalWrite(b[2],LOW);
    digitalWrite(b[1],HIGH);
    led(x);
    delay(6);
    digitalWrite(b[1],LOW);
    digitalWrite(b[0],HIGH);
    led(c);
    delay(6);
    digitalWrite(b[0],LOW);
}
}


void setup()
{
  mass();

  for (byte i=2; i<=11; i++)
  pinMode(i,OUTPUT);
  for (byte i=5; i<=11; i++)
  digitalWrite(i,HIGH);
  b[0]=2;
  b[1]=3;
  b[2]=4;

 
  pinMode(18,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(12,OUTPUT);

 // Serial.begin(9600);

}

int meters()
{
  digitalWrite(A3,LOW);
  delayMicroseconds(10);
  digitalWrite(A3,HIGH);
  delayMicroseconds(10);
  digitalWrite(A3,LOW);
  int  l=pulseIn(A2,HIGH)/58;
  return l;
}

void loop()
{
j=0;
  q=meters();
if (q>251) q=last;

  for (int i=1;i<=50;i++)
  {
  chislo(q);
  int times=map(q,0,250,7,50);
  if (i % times == 0) j++;
  switch(j)
  {
    case 1:  digitalWrite(13,HIGH);
             digitalWrite(14,LOW);
             digitalWrite(15,LOW);
             digitalWrite(12,LOW);
             digitalWrite(18,LOW);
             
             break;
    case 2:  digitalWrite(13,LOW);
             digitalWrite(14,HIGH);
             digitalWrite(15,LOW);
             digitalWrite(12,LOW);
             digitalWrite(18,LOW);
             
             break;
    case 3:  digitalWrite(13,LOW);
             digitalWrite(14,LOW);
             digitalWrite(15,HIGH);
             digitalWrite(12,LOW);
             digitalWrite(18,LOW);
             
             break;  
    case 4:  digitalWrite(13,LOW);
             digitalWrite(14,LOW);
             digitalWrite(15,LOW);
             digitalWrite(12,HIGH);
             digitalWrite(18,LOW);
             
             break;  
    case 5:  digitalWrite(13,LOW);
             digitalWrite(14,LOW);
             digitalWrite(15,LOW);
             digitalWrite(12,LOW);
             digitalWrite(18,HIGH);
             
             break; 
    case 6: digitalWrite(18,LOW); 
  }
  }
   
  last=q;

}

