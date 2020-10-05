#include<SPI.h>
#include<SD.h>

File number;
String str="";

byte a[8][16];
byte b[16];

byte x,y,w=0,j=0;

boolean q=false;

void translate()
{
  w=0;j=0;
  q=false;
  str="";
  if (number)
  {
    Serial.println("DONE");
    while (number.available())
    str+=char(number.read());
    number.close();
  }
  else Serial.println("failed 2");
  Serial.println();
  Serial.println("mass 1.1");

  for (int i=0; i<=str.length(); i++)
  {
   if (str[i] == 'x') q=true;
   if (q == true)
   w++;
   switch(w)
   {
    case 2:
           if (str[i] >= '0' && str[i] <= '9')
            x=((int)str[i]-'0')*16;
            else
            switch(str[i])
           {
            case 'A':x=10*16; break;
            case 'B':x=11*16; break;
            case 'C':x=12*16; break;
            case 'D':x=13*16; break;
            case 'E':x=14*16; break;
            case 'F':x=15*16; break;
           }
            break;
           
    case 3:
          if (str[i] >= '0' && str[i] <= '9')
           b[j]=(int)str[i]+x-'0';
           else 
           switch(str[i])
           {
            case 'A':b[j]=10+x; break;
            case 'B':b[j]=11+x; break;
            case 'C':b[j]=12+x; break;
            case 'D':b[j]=13+x; break;
            case 'E':b[j]=14+x; break;
            case 'F':b[j]=15+x; break;
           }
           q=false;
           w=0;
           j++;
           break;
   }
   Serial.print(str[i]);
  }

   Serial.println();
   Serial.println();
  Serial.println("mass 1.2");
 
  for(int i=0; i<=j-1; i++)
  {
    Serial.print(b[i]);
    Serial.print(" ");
    int p=b[i];
    int m=0;
     if (p != 0)
  {
   for (w=0; w<=7; w++)
  {
    
  a[w][i]=0;
  }
 
  while (p != 1)
  {
    a[m][i]=p%2;
    p=p/2;
    m++;
  }
  a[m][i]=p;
  }
  else
  for (w=0; w<=7; w++)
  {
    
  a[w][i]=0;
  }
  
  }
  Serial.println();
  Serial.println();
  Serial.println("mass 1.3");
  Serial.println();

  for(int i=0; i<=7; i++){
  for(j=0; j<=16; j++)
  {
  Serial.print(a[i][j]);
  Serial.print(" ");
  }
  Serial.println();
  }

  Serial.println();
  Serial.println();
  Serial.println();
}

void creat()
{

  number=SD.open("one.txt");
  translate();
  
  

  number=SD.open("two.txt");
  translate();

 

  number=SD.open("three.txt");
  translate();

  

  number=SD.open("four.txt");
  translate();
}

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  if (!SD.begin(4))
  {
  Serial.println("failed");
  return;
  }
  Serial.println("Done");

  creat();

  
  

 
}
void loop()
{
  
}

