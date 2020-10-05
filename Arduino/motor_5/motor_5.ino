#include<SPI.h>
#include<SD.h>

File sim;

volatile byte i=2;
byte nn=0,el=3,p=0;
boolean endm=false,side=true,q=true;
int new_mass=0;
byte c[8];
int pause[6]={0,//3
              530,//4
               540,//2
               530,//1
               400,//6
               580,//5
               
               };
byte string_m[6]={
                  2,
                  3,
                  1,
                  0,
                  5,
                  4,
                  };

byte a[6][128]={
  {1,1,1,1,1,1,1,1,},
  {0,0,0,0,0,0,1,1,},
  {0,0,0,0,0,1,1,0,},
  {0,0,0,1,1,0,0,0,},
  {0,1,1,0,0,0,0,0,},
  {1,1,1,1,1,1,1,1,},
};
//byte b[6][128];

byte d[16]; 

void setup()
{
  Serial.begin(9600);
  while(!Serial);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(7,OUTPUT);

  if (!SD.begin(4))
  return;
  /*Serial.print("done");
  Serial.end();**/
  attachInterrupt(0, zero, FALLING);
  while (i != 0);
  creat();
  for (nn=0;nn<=15; nn++)
  {
    Serial.print(d[nn]);
    Serial.print(" ");
    rewrite();
  }
  Serial.println();
  for (byte h=0; h<=5; h++){
  for (byte j=0; j<=127;j++)
  Serial.print(a[h][j]);
  Serial.println();
  }
}

void zero()
{
  i=0;
}

void creat()
{
  nn=0;
  endm=false;
 // side=!side;
  switch(el)
  {
    case 1:sim=SD.open("one.txt");
           translate();
           sim.close();break;
    case 2:sim=SD.open("two.txt");
           translate();
           sim.close();break;
    case 3:sim=SD.open("three.txt");
           translate();
           sim.close();break;
  }
  p=0;
  el++;
  if (el == 4) el=1;
}

void translate()
{
  boolean qq=false;
  byte m=0,x;
  byte str;
  
  if (sim)
  while (sim.available())
  {
    str = (sim.read());
    if (str == 'x')
    qq=true;
    if (qq)
    {
    m++;
    switch(m)
    {
      case 2:if (str >= '0' && str <= '9')
      x=16*(str-'0');
      else if (str >= 'A' && str <= 'F') 
      x=16*(str-'A'+10);
      break;
      
      case 3:if (str >= '0' && str <= '9')
      d[p]=x+(str-'0');
      else if (str >= 'A' && str <= 'F') 
      d[p]=x+(str-'A'+10);
      m=0;
      p++;
      qq=false;
      break;
    }
    }
  } 
}

void rewrite()
{
  byte mn;
  if (!endm)
  {
    mn=0;
    for (byte pp=0; pp<=7; pp++)
    c[pp]=0;
    if (nn < 16)
    if (d[nn] != 0)
    {
      while (d[nn] != 1)
      {
        c[mn]=d[nn]%2;
        d[nn]/=2;
        mn++;
      }
      c[mn]=d[nn];
    }
    for (byte pp=0; pp<=5; pp++)
    a[pp][nn]=c[pp];
  }
}

void reading()
{
  if (digitalRead(3) == LOW && q == true)
  {
    i++;
    q=false;
  }
  else if(digitalRead(3) == HIGH)
  q=true;
}

void loop()
{
/*  byte n;
  while (i != 35)
  {
    reading();
  //  rewrite();
  
    n=i/6;
    if (i % 6 == 0)
    {
      delayMicroseconds(pause[n]);
      for (byte j=127; j>0; j--)
      {
    //    if (side)
        digitalWrite(7,a[string_m[n]][j]);
     //   else digitalWrite(7,b[string_m[n]][j]);
        reading();
        if (i == 35) break;
      }
      digitalWrite(7,0);
    }
  }
  if (new_mass % 10 ==0)
  {
//  creat();
  new_mass=0;
  }
  new_mass++;*/
}


