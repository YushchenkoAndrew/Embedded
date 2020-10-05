#include "lcd1202.h"
LCD1202 lcd(8, 7, 6, 5);
int j=1;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  analogWrite(9,250);
  lcd.Inicialize();
  lcd.Clear_LCD();
  //Serial.begin(250000);
}
void loop()
{

    int a[100];
  for (int i=1; i<=96; i++)
  
      a[i]=map(analogRead(A0),0,1024,0,20);
    for (int i=1; i<=95; i++)
  {
   lcd.drawPixel(i,a[i],1);
   lcd.drawLine(i,a[i],i,a[i+1],1);
  }
  lcd.Update();
  delay(1000);
  lcd.Clear_LCD();
}

