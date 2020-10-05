
volatile int i=5;
volatile bool q=false,qq=true;

boolean w=true,right=false,mistake=false,reopen=false,ends=false;
//char str[200]='0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00";
char a1[72],a2[72];
char b1[72],b2[72];
int ghj=0,number=0,number2=0,kk,last=0;
bool hh=1;

int pause[]=
{
  0,//2
  510,//3
  520,//1
  520,//0
  380,//5
  570,//4
};

void setup()
{
  Serial.begin(250000);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(7,OUTPUT); 
 attachInterrupt(0, zero, RISING);
  attachInterrupt(1, sum, RISING);
  kk=0;
  //readfile2();
 // while (i != 0);
  
}

void sum()
{
  i++;
  qq=true;
  if (q) {i=0; q=false;}
}
void zero()
{
  q=true;
}


bool binary(char c, byte n)
{
  if((c >= '0')&&(c <= '9'))
  switch(n)
  {
    case 0:return bool(c & 4);break;
    case 1:return bool(c & 8);break;
    case 2:return bool(c & 2);break;
    case 3:return bool(c & 1);break;
    case 4:return bool(c & 2);break;
    case 5:return bool(c & 1);break;
  }
  else 
  if((c >= 'A')&&(c <= 'F'))
  {
    byte r=c+1;
    c=r;
    switch(n)
  {
    case 3:return bool(c & 1);break;
    case 2:return bool(c & 2);break;
    case 0:
    if ((c >= 'D')&&(c <= 'G'))
    return 1;
    else return 0;break;
    case 1:return 1;break;
    case 5:return bool(c & 1);break;
    case 4:return bool(c & 2);break;
  }
  }
}



void loop()
{
   digitalWrite(7,0);
    if (i != last)
    {
    for (int j=100; j>=0; j--)
    {
    digitalWrite(7,1); 
   hh=!hh;
    delayMicroseconds(10);
    }
    last=i;
}   
}

