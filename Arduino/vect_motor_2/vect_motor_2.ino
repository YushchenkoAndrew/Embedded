int a=20000;
int main_step=1;
int pause[4]={180000,0,10000,000};

void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

}
void main_0(int a,int b, int c, int d,int steps)
{
  int max1,max2,main;
  if (a>b) max1=a; else max1=b;
  if (c>d) max2=c; else max2=d;
  if (max1>max2) main=max1; else main=max2;
  
  for (int i=1; i<=steps; i++)
  {
  if (a!=0)
  UP(a/steps);
  if (b!=0)
  DOWN(b/steps);
  if (c!=0)
  RIGTH(c/steps);
  if (d!=0)
  LEFT(d/steps);
  
  }
  

  
}
void LEFT(int q)
{
  PORTD &=~ (1<<2);
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
 /* digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);*/
  if (q>=1000) delay(q/1000);
  else delayMicroseconds(q);
  
/*  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);*/
  PORTD &=~ (1<<2);
  PORTD &=~ (1<<3); 
  PORTD |= (1<<4);
  delayMicroseconds(20);

 /* digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);*/
  PORTD &=~ (1<<2);
  PORTD &=~ (1<<3); 
  PORTD &=~ (1<<4);
  delayMicroseconds(200);
}

void UP(int q)
{
  PORTD &=~ (1<<5);
  PORTD &=~ (1<<6); 
  PORTD |= (1<<7); 
  /*
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,1);*/
  if (q>=1000) delay(q/1000); 
  else delayMicroseconds(q);
  
 /* digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);*/
  PORTD |= (1<<5);
  PORTD &=~ (1<<6); 
  PORTD |= (1<<7); 
  delayMicroseconds(20);
  
 /* digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);*/
  PORTD &=~ (1<<5);
  PORTD &=~ (1<<6); 
  PORTD &=~ (1<<7); 
  delayMicroseconds(200);
}

void RIGTH(int q)
{
  PORTD &=~ (1<<2);
  PORTD &=~ (1<<3); 
  PORTD |= (1<<4);
  /*
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);*/
  if (q>=1000) delay(q/1000); 
  else delayMicroseconds(q);
  
 /* digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,1);*/
  PORTD &=~ (1<<2);
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
  delayMicroseconds(20);

 /* digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);*/
  PORTD &=~ (1<<2);
  PORTD &=~ (1<<3); 
  PORTD &=~ (1<<4); 
  delayMicroseconds(20);
}

void DOWN(int q)
{
  PORTD |= (1<<5);
  PORTD &=~ (1<<6); 
  PORTD |= (1<<7); 
  /*
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,1);*/
  if (q>=1000) delay(q/1000); 
  else delayMicroseconds(q);
  
/*  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,1);*/
  PORTD &=~ (1<<5);
  PORTD &=~ (1<<6); 
  PORTD |= (1<<7); 
  delayMicroseconds(20);
  
 /* digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);*/
  PORTD &=~ (1<<5);
  PORTD &=~ (1<<6); 
  PORTD &=~ (1<<7); 
  delayMicroseconds(20);
}

void loop() 
{

 //  main_0(a-pause[0],0,0,0,main_step); 
   
   
  
   main_0(a-pause[0],0,a-pause[2],0,main_step);
 //  main_0(0,a-pause[1],0,0,main_step);
   
  main_0(0,a-pause[1],0,a-pause[3],main_step);
  
}
