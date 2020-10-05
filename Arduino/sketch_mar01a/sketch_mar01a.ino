byte a=2;
byte led=12;
volatile boolean q=true;
volatile boolean w=true;
volatile int i=0;
void setup()
{
  pinMode(12,OUTPUT);
  attachInterrupt(0, down, CHANGE);

 

}
void loop()
{
  c();
q=!q;
}
void down()
{
 

 w=!w;
q=HIGH;


  
}
void c()
{
  if(w){
digitalWrite(12,q);
  
  delayMicroseconds(100);}
  
}


