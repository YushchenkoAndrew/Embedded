int start=20000;
int finish=600;
int steps=50;
boolean w=true;
byte k=1;
int i=0;
boolean mistake=false;
byte fill=600;
boolean ok=false;
boolean second=HIGH;
long now;
int trash;
int times=0;
byte m=1;
long last=0;

volatile boolean first=LOW; 

boolean a1[]={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,  };
boolean a2[]={0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,  };
boolean a3[]={0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,  };
boolean a4[]={0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  };


void wait()
{
  //now=micros();

//  j1++;
 // if (j1 % 3 == 0) w=!w;
  last=micros();
  while ((micros()-last) <= (start-trash))
  {
   if(w == true)
   {
    digitalWrite(8,a1[i]);
    digitalWrite(9,a2[i]);
   }
    else
    {
        
    digitalWrite(8,a3[i]);
    digitalWrite(9,a4[i]);
    }
    i++;
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  // delayMicroseconds(6);
   // now=micros();
  }
 // digitalWrite(8,LOW);
 // digitalWrite(9,LOW);

 /* Serial.print(micros()-last);
  Serial.print(" ");
  Serial.println((start-trash));*/
 // digitalWrite(8,LOW);
 // digitalWrite(9,LOW);
 // if (j1%3 == 0){
 // times=((micros()/4-last/4)*4+start)/2;
  //Serial.print("*");Serial.println(j1);
 // j1=0; w=!w; i=0; }

 

}

void wait1()
{
  //now=micros();

  
 // if (j1 % 3 == 0) w=!w;
  last=micros();
  while ((micros()-last) <= (start-trash))
  {
   if(w == true)
   {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
   }
    else
    {
        
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    }

    if ((first == LOW)&&(second == HIGH))
    tulse();
  if (digitalRead(6) == LOW){ ok=true;
    digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
    delay(100);
  }
   
   // delayMicroseconds(0.001);

  //  now=micros();
  }
  m++;
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  if ((first == LOW)&&(second == HIGH))
    tulse();
if ((ok == true)) {ok=false;m=1;first=HIGH;} else if (m > fill) { start=20000;
  /*digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
    delay(100);*/
mistake=true;
  //test2();
  }
if (mistake) w=!w;

  //Serial.println(times);

}



void turn(int q1,int q2)
{
  if (q1 != q2)
  {
  switch(q1)
  {
    case 1:digitalWrite(2,HIGH);

     digitalWrite(3,HIGH);
     digitalWrite(4,LOW);
             
      if((start == finish)){ 
           wait();
           }
           else{wait1();}
      
            

    
    break;
    case 2:digitalWrite(3,HIGH);

           digitalWrite(3,LOW);
           digitalWrite(4,HIGH);
             if((start == finish))
           { 
           wait();
           }
           else{wait1();}
             
    
    break;
    case 3:digitalWrite(4,HIGH);
           digitalWrite(3,LOW);
             digitalWrite(2,HIGH);
             if((start == finish))
           { 
           wait();
           }
           else{wait1();}
             
    
    break;
  }
}
  else 
  switch (q1)
  {
    case 1:digitalWrite(2,HIGH);
           digitalWrite(3,LOW);
           digitalWrite(4,LOW);
          if((start == finish))
           { 
           wait();
           }
           else{wait1();}
           break;
    case 2:digitalWrite(2,LOW);
           digitalWrite(3,HIGH);
           digitalWrite(4,LOW);
           
           if((start == finish))
           { 
           wait();
           }
           else{wait1();}
           break;
    case 3:digitalWrite(2,LOW);
           digitalWrite(3,LOW);
           digitalWrite(4,HIGH);
           if((start == finish))
           { 
           wait();
           }
           else{wait1();}
           break;
  }
}
void turn1(int q1,int q2)
{
 // digitalWrite(8,LOW);
 // digitalWrite(9,LOW);
  if (q1 != q2)
  {
  switch(q1)
  {
    case 1:digitalWrite(2,HIGH);
           digitalWrite(3,HIGH);
           digitalWrite(4,LOW);
             
              if (first == HIGH)  
             delayMicroseconds(start);
             else wait1();

    break;
    case 2:digitalWrite(3,HIGH);

           digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
           if (first == HIGH)  
             delayMicroseconds(start);
             else wait1();
  
    break;
        case 3: digitalWrite(4,HIGH);

             digitalWrite(3,LOW);
             digitalWrite(2,HIGH);
             if (first == HIGH)  
             delayMicroseconds(start);
             else wait1();

    break;
  }
}
  else 
  switch (q1)
  {
    case 1:digitalWrite(2,HIGH);
           digitalWrite(3,LOW);
           digitalWrite(4,LOW);
           if (first == HIGH)  
             delayMicroseconds(start);
             else wait1();
           break;
    case 2:digitalWrite(2,LOW);
           digitalWrite(3,HIGH);
           digitalWrite(4,LOW);
           
           if (first == HIGH)  
             delayMicroseconds(start);
             else wait1();
           break;
    case 3:digitalWrite(2,LOW);
           digitalWrite(3,LOW);
           digitalWrite(4,HIGH);
           if (first == HIGH)  
             delayMicroseconds(start);
             else wait1();
           break;
  }
//  Serial.println(first);
}
void test()
{
  now=micros();

//  i++;
 // if (j1 % 3 == 0) w=!w;
  
  // delayMicroseconds(2);

  //  now=micros();
// w=!w;
//while (i!=0);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
 // digitalWrite(8,LOW);
//  digitalWrite(9,LOW);*/
//  if (j1%3 == 0){
 // times=((micros()/4-last/4)*4+start)/2;
  //Serial.print("*");Serial.println(j1);
 // j1=0; w=!w; i=0; }

  //Serial.println(times);
  trash=micros()-now;
  i=0;
  
  
}

void tulse()
{
  if (digitalRead(6) == LOW){
  first=HIGH;
  digitalWrite(13,HIGH);
 delay(100);
  digitalWrite(13,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(100);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(500);
  }
}

void test2()
{

  
  if (first == LOW)
  turn1(1,1);
  if (first == LOW)
  turn1(1,2);
  if (first == LOW)
  turn1(2,2);
  if (first == LOW)
  turn1(2,3);
  if (first == LOW)
  turn1(3,3);
  if (first == LOW)
  turn1(3,1);
  else  test();
  


}

void firststeps()
{
    while (start != finish)
  {
    first=LOW;
    second=LOW;
    if (start < 1000 )
    {
    first=HIGH;
    second=HIGH;
    }
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);

  if (start > finish)
  start=start-steps;
  else
  {
  start=finish;
  digitalWrite(13,LOW);
  }




 /* if (start <= 20000)
  steps=50;
  */
  if (start <=2000)
  steps=1;

  if ((finish + 500 > start) &&(finish != start))
  digitalWrite(13,HIGH);

  }
}

void setup()
{
// test();
 pinMode(6,INPUT);
 pinMode(14,INPUT);
 pinMode(15,INPUT);
 pinMode(16,INPUT);
 pinMode(17,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(250000);
  digitalWrite(13,LOW);
  delay(500);
 // attachInterrupt(1,tulse,CHANGE);
 // detachInterrupt(0);
 while (first == HIGH)
 test2();


firststeps();

  first=HIGH;
  second=LOW;
  digitalWrite(13,LOW);
  Serial.println(trash);

}
void loop()
{

/*  if (first == LOW)
  {
 // test();
  test2();
  }
  else{*/
  if ((digitalRead(14) == 1)&&(digitalRead(15) == 0)&&(digitalRead(16) == 0)&&(digitalRead(17) == 0))
  {
  k=1;
  if (mistake) k++;
  }
  else
  if ((digitalRead(14) == 0)&&(digitalRead(15) == 1)&&(digitalRead(16) == 0)&&(digitalRead(17) == 0))
  {
  k=2;
  if (mistake) k++;
  }
  else 
  if ((digitalRead(14) == 0)&&(digitalRead(15) == 0)&&(digitalRead(16) == 1)&&(digitalRead(17) == 0))
  {
  k=3;
  if (mistake) k=1;
  }
  else
  if ((digitalRead(14) == 0)&&(digitalRead(15) == 0)&&(digitalRead(16) == 0)&&(digitalRead(17) == 1))
  k=4;
  else
  if ((digitalRead(14) == 0)&&(digitalRead(15) == 0)&&(digitalRead(16) == 0)&&(digitalRead(17) == 0))
  k=0;
  //  Serial.println(trash);
switch(k)
{
case 1:
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn(2,3);
  turn(3,3);
  turn(3,1);

  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);

  
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);
  break;

  case 2:
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);

  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn(2,3);
  turn(3,3);
  turn(3,1);

  
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);
  break;

  case 3:
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);

  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);

  
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn(2,3);
  turn(3,3);
  turn(3,1);
  break;

  case 4:
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn(2,3);
  turn(3,3);
  turn(3,1);

  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn(2,3);
  turn(3,3);
  turn(3,1);

  
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn(2,3);
  turn(3,3);
  turn(3,1);
  break;

  case 0:
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);

  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);

  
  turn1(1,1);
  turn1(1,2);
  turn1(2,2);
  turn1(2,3);
  turn1(3,3);
  turn1(3,1);
  break;
}

  w=!w;
 i=0;


//  } else{
/*
if ((start < 10000)&&(finish != start))
for (int op=1; op<=3; op++)
{
  turn(1,1);
  turn(1,2);
  turn(2,2);
  turn(2,3);
  turn(3,3);
  turn(3,1);

}*/

   // Serial.println(start);
  /*

  if (start > finish)
  start=start-steps;
  else
  {
  start=finish;
  digitalWrite(13,LOW);
  }




 /* if (start <= 20000)
  steps=50;
  
  if (start <=2000)
  steps=1;

  if ((finish + 500 > start) &&(finish != start))
  digitalWrite(13,HIGH);

 */
  
 
}

