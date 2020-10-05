//(4) .-1 f-2 g-4 a-8
  //(6)b-1 c-2 d-4 e-8
  
  //(8)9-1 4-2 5-4 8-8
  //(10)1-1 2-2 6-4 7-8
int a[20]={15,3,3,9,1,1,7,1,14,};
int b[20]={12,2,8,12,9,1,12,0,15,};
int c[20]={7,15,15,11,13,15,15,15,14,};
int d[20]={15,7,11,15,15,15,13,14,15};
bool e[20]=   {1,1,1,1,1,0,1,1,1,};
int n=9;
void setup()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);

  digitalWrite(5,0);
  digitalWrite(7,0);

  digitalWrite(12,1);

  digitalWrite(9,0);
  digitalWrite(11,0);
 
} 
void segment(int a, int b)
{
   for (int i=1; i<=a; i++)
  {
  digitalWrite(4,1);
  digitalWrite(4,0);
  }
  for (int i=1; i<=b; i++)
  {
  digitalWrite(6,1);
  digitalWrite(6,0);
  }
  delay(3);
}

void where(int c,int d, bool q)
{
  for (int i=1; i<=c; i++)
  {
  digitalWrite(8,1);
  digitalWrite(8,0);
  }
  for (int i=1; i<=d; i++)
  {
  digitalWrite(10,1);
  digitalWrite(10,0);
  }
  digitalWrite(12,q);
  

 
}
void zero()
{
  digitalWrite(5,1);
  digitalWrite(7,1);
  digitalWrite(5,0);
  digitalWrite(7,0);

  
  digitalWrite(9,1);
  digitalWrite(11,1);
  digitalWrite(9,0);
  digitalWrite(11,0);
}

void loop()
{ 
  
  for (int i=0; i<=8; i++)
  {
  where(c[i],d[i],e[i]);
  segment(a[i],b[i]);


  zero();
  }


}

