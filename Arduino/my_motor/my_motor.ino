int steps=5;
int stepmotor=20000;
int stopstep=3500;
int wait=0;
int c=0;
int number=0;

int speedtime=3;

int sleep=1000;



boolean a[]={
  0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
  1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
  1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
  1,1,1,1,1,1,1,1,1,1,1};



void stoptime(int t)
{
  int k=-1;
  if (t != 3500)
  delayMicroseconds(t);
  else
    if (wait <=sleep) {wait++;delayMicroseconds(t-(wait/2));}
  else
  

  for (int i=0; i<=t; i=i+50)
  {
    k++;
    digitalWrite(8,a[k]);
  delayMicroseconds(t/100);
  }
  
}

void stoptime2(int t)
{
  
  if (t != 3500)
  delayMicroseconds(t);
  else
    if (wait <=sleep) {wait++;delayMicroseconds(t-(wait/2));}
  else
  

  for (int i=0; i<=t; i=i+50)
  {
   
    digitalWrite(8,LOW);
  delayMicroseconds(t/100);
  }
}

void chance(int t)
{
  boolean y;
  c++;
  if (c %speedtime == 0){

 
  for (int i=71; i>=1; i--)
  
    a[i]=!a[i];
  
    
  
  c=0;
  }
  
  stoptime(t);
  
}


void turn(int number)
{
  switch(number)
  {
    case 1:
    { 
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      chance(stepmotor);
      break;
    }
    case 2:
    { 
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      stoptime2(stepmotor);
      break;
    }
    case 3:
    { 
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      stoptime2(stepmotor);
      break;
    }
  }
}


void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  digitalWrite(13,LOW);
}


void loop()
{
  turn(1);
  turn(2);
  turn(3);
  if (stepmotor > stopstep)
  stepmotor=stepmotor-steps;
  else stepmotor=stopstep;

  if (stepmotor <40000)
  {
  steps=500;
  digitalWrite(13,LOW);
  }
  if (stepmotor <20000)
  {
    steps=50;
    digitalWrite(13,HIGH);
  }

}

