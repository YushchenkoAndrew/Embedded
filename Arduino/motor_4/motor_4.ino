byte i=0;
boolean q=true;
byte n;
int j=0;
byte w;
byte m;
boolean side=0;
byte p;
int ghj=0;
byte l;
byte all2=0;
byte d=0;
byte newmass=1;
int k=3;
int g=0;
int all=0;
boolean mass;

byte times=4;

byte length_mass[5]={
                     16,//b1
                     16,//b2
                     16,//b3
                     16,//b4
                     16,//b5
                     };

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

byte a[6][128];

byte b[6][128];

byte b1[16]={
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x3F,
  0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

byte b2[16]={
  0x00, 0x00, 0x00, 0x00, 0x31, 0x31, 0x29, 0x29,
  0x25, 0x25, 0x23, 0x23, 0x00, 0x00, 0x00, 0x00
  };

byte b3[16]={
  0x00, 0x00, 0x00, 0x00, 0x25, 0x25, 0x25, 0x25,
  0x25, 0x25, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00
  };

byte b4[16]={
  0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x0A, 0x0A,
  0x09, 0x09, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00
  };


  
byte c[8];

void reading()
{
 if ((digitalRead(3) == LOW)&&(q == true))
  { 
    i++;
  if (digitalRead(3) == LOW)
  {
  q=false;
  }
  
  }
  else 
  
    if ((digitalRead(3) == HIGH))
    {
  q=true;
    }
}


void change()
{
 
 
{
  m=0;

switch(l)
{
  case 0:p=b1[d];break;
  case 1:p=b2[d];break;
  case 2:p=b3[d];break;
  case 3:p=b4[d];break;

}

  if (p != 0)
  {
    for (w=0; w<=7; w++)
  {
    
  c[w]=0;
  }
 
  while (p != 1)
  {
    c[m]=p%2;
    digitalWrite(7,0);
    p=p/2;
    m++;
  }
  c[m]=p;
  }
  else
  for (w=0; w<=7; w++)
  {
    
  c[w]=0;
  }
  
  for (w=0; w<=5; w++)
  {
    if (side == 0)
    a[w][g]=c[w];
    else b[w][g]=c[w];
    
  }
  

}
  
}
/*
void add()
{
  if (l <= k && k!=4)
{
  if (d == length_mass[l])
  {
    l++;
    d=0;
    all=all+length_mass[l];
  }
  if (g < all)
  change();
  g++;
  d++;
  }
    else mass=false;
}
*/


void runString()
{
  if (l <= 3 )
{
  
  if (d == length_mass[l])
  {
    l++;
    d=0;
  }
  if (g < all && g >= 0)
  {
  change();
  digitalWrite(7,0);}
  g++;
  d++;
  }
    else{ mass=false;}
  
}



void zero()
{
  
   for (i=0; i<=128; i++)
  for (j=0; j<=5;j++)
  {
    
  if (side == 1)
    a[j][i]=0;
  else
    b[j][i]=0;
  }
}


void setup()
{
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(7,OUTPUT);
  all=length_mass[0]+length_mass[1]+length_mass[2]+length_mass[3];
  while (digitalRead(2) != 0);

  
}
void loop()
{
newmass++;

  if (newmass % times == 0)
  {
    ghj++;
    g=ghj;
    all++;
    if(all >= 128)
    all--;
 if (ghj >= 128)
 {
 ghj=-(length_mass[0]+length_mass[1]+length_mass[2]+length_mass[3]);

 }
 l=0;
  mass=true;
  zero();
  d=0;
  side=!side;
     
     
  }


 while (digitalRead(2) != 0)
 digitalWrite(7,0);



  i=0;
  while (i != 35)
  {    
    reading();
   n=i/6;

   

if (mass == true)
//add();
runString();
  



   
   digitalWrite(7,0);
   


    if (i % 6 == 0)
    {

    
 delayMicroseconds(pause[n]); 

      for (j=127; j>=0; j--)
      {
          
       if (side == 0)
        digitalWrite(7,b[string_m[n]][j]);
        else digitalWrite(7,a[string_m[n]][j]);
        reading();
        
       
          if (i == 35) break;
    
    }
    }

    
   
  
  }
   

  
}

