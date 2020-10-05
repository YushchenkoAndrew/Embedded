#include "lcd1202.h"
LCD1202 lcd(8, 7, 6, 5);
bool q=0;
void setup()
{
  lcd.Inicialize();
  lcd.Clear_LCD();
  pinMode(A0,INPUT);
}
void loop()
{
  lcd.fillScreen(1);
  lcd.print(28,30,0,"Функции");
  lcd.Update();
  delay(5000);
  lcd.Clear_LCD();
  for (int i=5; i>0; i--)
  {
  lcd.simb16x32(38,15,1,i);
  lcd.Update();
  delay(1000);
  lcd.Clear_LCD();
  }
  for (double i=0; i<=4*3.14; i+=(3.14/500))
  {
  lcd.drawPixel(i*3,19+trunc(sin(i)*10)*(-1),1);
  lcd.drawPixel(i*3,48+trunc(cos(i)*10)*(-1),1);
  }
  lcd.print(50,15,1,"sin x");
  lcd.print(50,44,1,"cos x");
  lcd.drawLine(0,19,45,19,1);
  lcd.drawLine(0,48,45,48,1);
  lcd.Update();
  delay(5000);
  lcd.Clear_LCD();
  q=1;
  for (double i=3.14/2; i<=5*3.14/2; i+=(3.14/1000))
  {
  lcd.drawPixel(i*10-15,30+trunc(tan(i)*10)*(-1),1);
  if ((tan(i)-0 <= 0.0001)&&(q))  {lcd.drawLine(i*10,0,i*10,68,1);q=0;}
  }
  lcd.print(72,30,1,"tg x");
  lcd.drawLine(0,30,65,30,1);
  lcd.Update();
  delay(5000);
  lcd.Clear_LCD();
  q=1;
  for (double i=0; i<=2*3.14; i+=(3.14/1000))
  {
  lcd.drawPixel(i*10,30+trunc(1/tan(i)*10)*(-1),1);
  if ((tan(i)-0 <= 0.0001)&&(q))  {lcd.drawLine(i*10,0,i*10,68,1);q=0;}
  }
    lcd.drawLine(0,30,65,30,1);
  lcd.print(72,30,1,"ctgx");
  lcd.Update();
  delay(5000);
  lcd.Clear_LCD();
  for (int j=0;j<=1000;j++)
  {
     for (int i=1; i<=96; i++)
  {
     analogWrite(9,1);
  lcd.drawPixel(i,analogRead(A0)-1150,1);
  delayMicroseconds(142);
   //   lcd.Update();
  }
  lcd.Update();
  
  lcd.Clear_LCD();
  }
}

