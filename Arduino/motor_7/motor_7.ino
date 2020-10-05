
volatile byte i=0;

boolean q=true,w=true,right=false,mistake=false,reopen=false,ends=false;
char a1[72],a2[72];
byte ghj=0,last=0;
/*
int pause[]=
{
  0,//2
  510,//3
  520,//1
  520,//0
  380,//5
  570,//4
};*/

void setup()
{
//  Serial.begin(250000);
//  if (!SD.begin(4)) return;
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(7,OUTPUT);
  attachInterrupt(1, sum, FALLING);
  
}
void sum()
{
  i++;
  if (i % 9 == 0) i=1;
}

 

bool binary(char c, byte n)
{
  if((c >= '0')&&(c <= '9'))
  switch(n)
  {
    case 0:return bool(c & 8);break;
    case 1:return bool(c & 4);break;
    case 2:return bool(c & 2);break;
    case 3:return bool(c & 1);break;
    case 4:return bool(c & 1);break;
    case 5:return bool(c & 2);break;
    case 6:return bool(c & 4);break;
    case 7:return bool(c & 8);break;
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
    case 6:return bool(c & 4);break;
    case 7:return bool(c & 9);break;
  }
  }
}



void loop()
{
   digitalWrite(7,0);

    if (i != last){
    for (int j=71; j>=0; j--)
    {
      bool b;
      if ((i == 1)||(i == 2)||(i == 3)||(i == 4))
      b=binary(a2[j],i-1); 
      else 
      b=binary(a1[j],i-1);
    digitalWrite(7,b); 
    delayMicroseconds(10);
    }
    last=i;
    }
    
  
}

