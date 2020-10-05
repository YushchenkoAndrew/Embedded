bool q=0;
void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
digitalWrite(6,1);

digitalWrite(2,1);

digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);

delay(100);
digitalWrite(6,0);
digitalWrite(7,0);
}
void change()
{
  q=!q;
  digitalWrite(7,q);
}
void mario()
{
    tone(2,1318,150);
delay(150);change();
tone(2,1318,300);
delay(300);change();
tone(2,1318,150);
delay(300);change();
tone(2,1046,150);
delay(150);change();
tone(2,1318,300);
delay(300);change();
tone(2,1568,600);
delay(600);change();
tone(2,784,600);
delay(600); change();

tone(2,1046,450) ; // 2й такт
delay(450);change();
tone(2,784,150);
delay(450);change();
tone(2,659,300);
delay(450);change();
tone(2,880,300);
delay(300);change();
tone(2,987,150);
delay(300);change();
tone(2,932,150);
delay(150);change();
tone(2,880,300);
delay(300);change();


tone(2,784,210); // 3й такт
delay(210);change();
tone(2,1318,210);
delay(210);change();
tone(2,1568,150);
delay(150);change();
tone(2,1750,300);
delay(300);change();
tone(2,1396,150);
delay(150);change();
tone(2,1568,150);
delay(300);change();
tone(2,1318,300);
delay(300);change();
tone(2,1046,150);
delay(150);change();
tone(2,1174,150);
delay(150);change();
tone(2,987,450);
delay(450);change();


tone(2,1046,450); // 4й такт
delay(450);change();
tone(2,784,150);
delay(450);change();
tone(2,659,300);
delay(450);change();
tone(2,880,300);
delay(300);change();
tone(2,987,150);
delay(300);change();
tone(2,932,150);
delay(150);change();
tone(2,880,300);
delay(300);change();


tone(2,784,210); // 5й такт
delay(210);change();
tone(2,1318,210);
delay(210);change();
tone(2,1568,150);
delay(150);change();
tone(2,1750,300);
delay(300);change();
tone(2,1396,150);
delay(150);change();
tone(2,1568,150);
delay(300);change();
tone(2,1318,300);
delay(300);change();
tone(2,1046,150);
delay(150);change();
tone(2,1174,150);
delay(150);change();
tone(2,987,450);
delay(600);change();
}

void loop() {
for (int j=0; j<=5; j++)
{
 change();
for (int i=0; i<=400; i++)
{ 
  digitalWrite(2,0);
  delay(1);
  digitalWrite(2,1);
  delay(1);
  digitalWrite(2,0);
  delay(1);
}
delay(1000);
}
//delay(3000);
//mario();

}
