volatile int i=0;
volatile bool q=0;
void setup()
{
  pinMode(7,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  attachInterrupt(0,zero,FALLING);
   attachInterrupt(1,test,FALLING);
   
}
void zero()
{
  q=1;
}
void test()
{
 i++;
 if (q){ i=0; q=0;}
  
}
void loop()
{

  if (i  == 3)
  digitalWrite(7,0); else digitalWrite(7,1);
}

