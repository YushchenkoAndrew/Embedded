byte a[11];
byte b[3];
float q=0;
float om;
boolean music=false;
boolean zero=false;
byte buzzer=1;
boolean now=false;
boolean last=false;
boolean u;
byte pluse=0;
boolean k=HIGH;
byte p=1;
float volt;
float amper;
byte g=12;
byte h=13;
String str;
int mass()
{
  a[0]=0b1000000;
  a[1]=0b1111001;
  a[2]=0b0100100;
  a[3]=0b0110000;
  a[4]=0b0011001;
  a[5]=0b0010010;
  a[6]=0b0000010;
  a[7]=0b1011000;
  a[8]=0b0000000;
  a[9]=0b0010000;
}
int led(byte e)
{
  for (byte i=0; i<=7; i++)
  {
    boolean s=bitRead(a[e],i);
    digitalWrite(i+5,s);
  }
}
int chislo(int c)
{
  byte w;
  byte z=c%10;
  c=c/10;
  int x=c%10;
  c=c/10;

  if (zero == true) { digitalWrite(b[1],HIGH); led(0); delay(6); digitalWrite(b[1],LOW);}
  
  if ((x == 0)&&(c == 0))
    w=1;
  else if (c == 0)
    w=2;
  else
w=3;
if (w == 1)
{
  digitalWrite(b[2],HIGH);
    led(z);
    delay(6);
    digitalWrite(b[2],LOW);
}
else if (w == 2)
{
  digitalWrite(b[2],HIGH);
    led(z);
    delay(6);
    digitalWrite(b[2],LOW);
    digitalWrite(b[1],HIGH);
    led(x);
    delay(6);
    digitalWrite(b[1],LOW);
}
else if (w == 3)
{
  digitalWrite(b[2],HIGH);
    led(z);
    delay(6);
    digitalWrite(b[2],LOW);
    digitalWrite(b[1],HIGH);
    led(x);
    delay(6);
    digitalWrite(b[1],LOW);
    digitalWrite(b[0],HIGH);
    led(c);
    delay(6);
    digitalWrite(b[0],LOW);
}
}
float tap()
{
  float result;
  last=now;
  now=digitalRead(19);
  
  if (now == LOW && last == HIGH)
  {
    tone(1,1500);
    delay(15);
  pluse++;
  noTone(1);
  if (pluse >9)
  pluse=0;
  if (music) song();
  }
  if (!music)
  {
  switch(pluse)
  {
    case 0:digitalWrite(13,HIGH);  result=voltmetr(); 
    digitalWrite(15,LOW);break;
    case 1:digitalWrite(14,HIGH);  result=ampermetr();
    digitalWrite(13,LOW);break;
    case 2:digitalWrite(15,HIGH);  result=ommetr();
    digitalWrite(14,LOW);break;
    case 3:digitalWrite(15,HIGH);  result=ommetr();
    digitalWrite(14,LOW);break;
    case 4:digitalWrite(15,HIGH);  result=ommetr();
    digitalWrite(14,LOW);break;
    case 5:digitalWrite(15,HIGH);  result=ommetr();
    digitalWrite(14,LOW);break;
    case 6:digitalWrite(15,HIGH);  result=ommetr();
    digitalWrite(14,LOW);break;
    case 7:digitalWrite(15,HIGH);  result=ommetr();
    digitalWrite(14,LOW);break;
    case 8:digitalWrite(15,HIGH);  result=ommetr();
    digitalWrite(14,LOW);break;
    case 9:digitalWrite(15,LOW);  digitalWrite(12,LOW); result=zvon();
    digitalWrite(12,LOW);break;
  }} 
 return(result);
}
int zvon()
{
  int sensor=analogRead(A2)*10;
  if (sensor)
  {
  tone(1,2500);}
  else noTone(1);
 
  return(sensor);
}
float voltmetr()
{
  int sensor=analogRead(A2);
  volt=(sensor*(5.2/1023.0))*11;
  return (volt);
}
float ampermetr()
{
  int sensor=analogRead(A3);
  amper=sensor*1.45;
  return(amper);
}
float ommetr()
{
  int sensor=analogRead(A2);
  double U2=sensor*(5.0/1023.0);
  
  om=(5.0*10000)/U2-110000;

    switch(pluse)
  {
    case 2:sensor=analogRead(A3);
    U2=sensor*(5.0/1023.0);
  
    om=(5.0*4)/U2; if (om>100) om=680*om/60.18;break;
    case 3:om=1.2*om*1000/3666660; digitalWrite(13,HIGH);delay(4);digitalWrite(13,LOW);break;
    case 4:om=4.7*om*1000/7586200; digitalWrite(14,HIGH);delay(4);digitalWrite(14,LOW);break;
    case 5:om=12*om*1000/14756090; digitalWrite(18,HIGH);delay(4);digitalWrite(18,LOW);break;
    case 6:om=56*om*1000/63389830; digitalWrite(13,HIGH);digitalWrite(14,HIGH);delay(4);digitalWrite(14,LOW);digitalWrite(13,LOW);break;
    case 7:om=103*om*1000/112391320; digitalWrite(13,HIGH);digitalWrite(14,HIGH);digitalWrite(18,HIGH);delay(4);digitalWrite(14,LOW);digitalWrite(18,LOW);digitalWrite(13,LOW);break;
    case 8:om=1.1*om*1000000/2427585200; digitalWrite(14,HIGH);digitalWrite(18,HIGH);delay(4);digitalWrite(14,LOW);digitalWrite(18,LOW);break;
  }
  

  return (om);
}
void setup()
{
  mass();

  for (byte i=2; i<=11; i++)
  pinMode(i,OUTPUT);
  for (byte i=5; i<=11; i++)
  digitalWrite(i,HIGH);
  b[0]=2;
  b[1]=3;
  b[2]=4;
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(19,INPUT);
  pinMode(1,OUTPUT);
  pinMode(18,OUTPUT);
  if (!digitalRead(19)){
 song(); music=true;
 }
}
void song()
{
  tone(1,1318,150);
delay(150);
tone(1,1318,300);
delay(300);
tone(1,1318,150);
delay(300);
tone(1,1046,150);
delay(150);
tone(1,1318,300);
delay(300);
tone(1,1568,600);
delay(600);
tone(1,784,600);
delay(600); 


tone(1,1046,450) ; // 2й такт
delay(450);
tone(1,784,150);
delay(450);
tone(1,659,300);
delay(450);
tone(1,880,300);
delay(300);
tone(1,987,150);
delay(300);
tone(1,932,150);
delay(150);
tone(1,880,300);
delay(300);


tone(1,784,210); // 3й такт
delay(210);
tone(1,1318,210);
delay(210);
tone(1,1568,150);
delay(150);
tone(1,1750,300);
delay(300);
tone(1,1396,150);
delay(150);
tone(1,1568,150);
delay(300);
tone(1,1318,300);
delay(300);
tone(1,1046,150);
delay(150);
tone(1,1174,150);
delay(150);
tone(1,987,450);
delay(450);


tone(1,1046,450); // 4й такт
delay(450);
tone(1,784,150);
delay(450);
tone(1,659,300);
delay(450);
tone(1,880,300);
delay(300);
tone(1,987,150);
delay(300);
tone(1,932,150);
delay(150);
tone(1,880,300);
delay(300);


tone(1,784,210); // 5й такт
delay(210);
tone(1,1318,210);
delay(210);
tone(1,1568,150);
delay(150);
tone(1,1750,300);
delay(300);
tone(1,1396,150);
delay(150);
tone(1,1568,150);
delay(300);
tone(1,1318,300);
delay(300);
tone(1,1046,150);
delay(150);
tone(1,1174,150);
delay(150);
tone(1,987,450);
delay(600);
noTone(1);
delay(3000);
  tone(buzzer, 660 ,100);  
delay ( 150);  
tone(buzzer, 660 ,100);  
delay ( 300);  
tone(buzzer, 660 ,100);  
delay ( 300);  
tone(buzzer, 510 ,100);  
delay ( 100);  
tone(buzzer, 660 ,100);  
delay ( 300);  
tone(buzzer, 770 ,100);  
delay ( 550);  
tone(buzzer, 380 ,100);  
delay ( 575);  
  
tone(buzzer, 510 ,100);  
delay ( 450);  
tone(buzzer, 380 ,100);  
delay ( 400);  
tone(buzzer, 320 ,100);  
delay ( 500);  
tone(buzzer, 440 ,100);  
delay ( 300);  
tone(buzzer, 480 ,80);  
delay ( 330);  
tone(buzzer, 450 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 200);  
tone(buzzer, 660 ,80);  
delay ( 200);  
tone(buzzer, 760 ,50);  
delay ( 150);  
tone(buzzer, 860 ,100);  
delay ( 300);  
tone(buzzer, 700 ,80);  
delay ( 150);  
tone(buzzer, 760 ,50);  
delay ( 350);  
tone(buzzer, 660 ,80);  
delay ( 300);  
tone(buzzer, 520 ,80);  
delay ( 150);  
tone(buzzer, 580 ,80);  
delay ( 150);  
tone(buzzer, 480 ,80);  
delay ( 500);  
  
tone(buzzer, 510 ,100);  
delay ( 450);  
tone(buzzer, 380 ,100);  
delay ( 400);  
tone(buzzer, 320 ,100);  
delay ( 500);  
tone(buzzer, 440 ,100);  
delay ( 300);  
tone(buzzer, 480 ,80);  
delay ( 330);  
tone(buzzer, 450 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 200);  
tone(buzzer, 660 ,80);  
delay ( 200);  
tone(buzzer, 760 ,50);  
delay ( 150);  
tone(buzzer, 860 ,100);  
delay ( 300);  
tone(buzzer, 700 ,80);  
delay ( 150);  
tone(buzzer, 760 ,50);  
delay ( 350);  
tone(buzzer, 660 ,80);  
delay ( 300);  
tone(buzzer, 520 ,80);  
delay ( 150);  
tone(buzzer, 580 ,80);  
delay ( 150);  
tone(buzzer, 480 ,80);  
delay ( 500);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,150);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 150);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 430 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 100);  
tone(buzzer, 570 ,100);  
delay ( 220);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,200);  
delay ( 300);  
  
tone(buzzer, 1020 ,80);  
delay ( 300);  
tone(buzzer, 1020 ,80);  
delay ( 150);  
tone(buzzer, 1020 ,80);  
delay ( 300);  
  
tone(buzzer, 380 ,100);  
delay ( 300);  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,150);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 150);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 430 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 100);  
tone(buzzer, 570 ,100);  
delay ( 420);  
  
tone(buzzer, 585 ,100);  
delay ( 450);  
  
tone(buzzer, 550 ,100);  
delay ( 420);  
  
tone(buzzer, 500 ,100);  
delay ( 360);  
  
tone(buzzer, 380 ,100);  
delay ( 300);  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 500 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,150);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 150);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 430 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 100);  
tone(buzzer, 570 ,100);  
delay ( 220);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,200);  
delay ( 300);  
  
tone(buzzer, 1020 ,80);  
delay ( 300);  
tone(buzzer, 1020 ,80);  
delay ( 150);  
tone(buzzer, 1020 ,80);  
delay ( 300);  
  
tone(buzzer, 380 ,100);  
delay ( 300);  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,150);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 150);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 430 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 100);  
tone(buzzer, 570 ,100);  
delay ( 420);  
  
tone(buzzer, 585 ,100);  
delay ( 450);  
  
tone(buzzer, 550 ,100);  
delay ( 420);  
  
tone(buzzer, 500 ,100);  
delay ( 360);  
  
tone(buzzer, 380 ,100);  
delay ( 300);  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 500 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 500 ,60);  
delay ( 150);  
tone(buzzer, 500 ,80);  
delay ( 300);  
tone(buzzer, 500 ,60);  
delay ( 350);  
tone(buzzer, 500 ,80);  
delay ( 150);  
tone(buzzer, 580 ,80);  
delay ( 350);  
tone(buzzer, 660 ,80);  
delay ( 150);  
tone(buzzer, 500 ,80);  
delay ( 300);  
tone(buzzer, 430 ,80);  
delay ( 150);  
tone(buzzer, 380 ,80);  
delay ( 600);  
  
tone(buzzer, 500 ,60);  
delay ( 150);  
tone(buzzer, 500 ,80);  
delay ( 300);  
tone(buzzer, 500 ,60);  
delay ( 350);  
tone(buzzer, 500 ,80);  
delay ( 150);  
tone(buzzer, 580 ,80);  
delay ( 150);  
tone(buzzer, 660 ,80);  
delay ( 550);  
  
tone(buzzer, 870 ,80);  
delay ( 325);  
tone(buzzer, 760 ,80);  
delay ( 600);  
  
tone(buzzer, 500 ,60);  
delay ( 150);  
tone(buzzer, 500 ,80);  
delay ( 300);  
tone(buzzer, 500 ,60);  
delay ( 350);  
tone(buzzer, 500 ,80);  
delay ( 150);  
tone(buzzer, 580 ,80);  
delay ( 350);  
tone(buzzer, 660 ,80);  
delay ( 150);  
tone(buzzer, 500 ,80);  
delay ( 300);  
tone(buzzer, 430 ,80);  
delay ( 150);  
tone(buzzer, 380 ,80);  
delay ( 600);  
  
tone(buzzer, 660 ,100);  
delay ( 150);  
tone(buzzer, 660 ,100);  
delay ( 300);  
tone(buzzer, 660 ,100);  
delay ( 300);  
tone(buzzer, 510 ,100);  
delay ( 100);  
tone(buzzer, 660 ,100);  
delay ( 300);  
tone(buzzer, 770 ,100);  
delay ( 550);  
tone(buzzer, 380 ,100);  
delay ( 575); 
noTone(1);
}
void loop()
{
  zero=false;
  q=tap();
  if (pluse != 9){
  str=String((float)(q));
  if ((str[2] == '.')||(str[1] == '.'))
  {
    digitalWrite(12,HIGH);
    delay(3);
    digitalWrite(12,LOW);
    if (q<1 && q!=0) zero=true;
    q=q*10;
  }}
  
  chislo(q);
}

