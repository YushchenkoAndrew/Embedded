#include "lcd1202.h"

LCD1202 lcd(8, 7, 6, 5);

byte mass_out[288],raz=4,voltdel=1;
int moveX=0;
volatile byte pos=255; 
 bool q=0;

void setup()
{
  ADMUX= 0b01100000;

  change();
  
  attachInterrupt(0,moving,FALLING);
  attachInterrupt(1,button,FALLING);
  pinMode(11,OUTPUT);

  analogWrite(11,20);
  lcd.Inicialize();
  lcd.Clear_LCD();
}

void zamer()
{
  int mass_in[193];
  switch(raz)
  {
  case 1:ADCSRA=0b11100010;break;
  case 2:ADCSRA=0b11100011;break;
  case 3:ADCSRA=0b11100100;break;
  case 4:ADCSRA=0b11100101;break;
  case 5:ADCSRA=0b11100110;break;
  case 6:ADCSRA=0b11100111;break;
  }
  for (byte i=1; i<=192; i++)
  {
  while ((ADCSRA & 0x10) == 0);
  ADCSRA |= (1<<ADIF);
  mass_in[i]=(ADCL>> 6) | (ADCH << 2);
  }
  
  for (byte i=1; i<=192; i++)
    if (mass_in[i] >> 5 < 0b11111111) { mass_out[i]=mass_in[i] >> 5 ; } else mass_out[i]=0b00100000;
}

void handing()
{
  for (int i=1; i<=192; i++)
  mass_out[i]=map(mass_out[i],0,32,32,0);
}

void menu1()
{
  bool i=true;

    switch(pos)
   {
    case 1:  lcd.fillRect(1,52,22,14,1);
             lcd.print(3,55,0,voltdel);
             lcd.print(35,55,1,"Разв");
             lcd.print(70,55,1,"Paus");
             break;
    case 2:  lcd.fillRect(32,52,30,14,1);
             lcd.print(3,55,1,"В/Д");
             lcd.print(35,55,0,raz);
             lcd.print(70,55,1,"Paus");
             break;
    case 3:  lcd.fillRect(67,52,30,14,1);
             lcd.print(3,55,1,"В/Д");
             lcd.print(35,55,1,"Разв");
             lcd.print(70,55,0,"On");
             break;
    case 4:  lcd.print(3,55,1,"В/Д");
             lcd.print(35,55,1,"Разв");
             lcd.print(70,55,1,"Paus");
             break;
    case 255: 
             lcd.print(3,55,1,"В/Д");
             lcd.print(35,55,1,"Разв");
             lcd.print(70,55,1,"Paus");
             break;
   }
}

void moving()
{
  
  switch (pos)
  {
  case 1: if ((!(PIND & 0b00000100))&&(!(PIND & 0b00010000))) {voltdel--; if (voltdel == 0) voltdel=1;} else{voltdel++; if (voltdel == 4) voltdel=3; } change();break; 
  case 2: if ((!(PIND & 0b00000100))&&(!(PIND & 0b00010000))){raz++; if (raz == 7) raz=6; }  else{raz--; if (raz == 0) raz=1;} break;
  case 3: if ((!(PIND & 0b00000100))&&(!(PIND & 0b00010000))){ moveX-=10;   if (moveX <= -47) moveX=-47;}  else{ moveX+=10;   if (144+moveX >191) moveX=47;} break;
  }
  
}

void change()
{
 /* switch(voltdel)
  {
  case 1: PORTC |= (1<<1);PORTC &=~ (1<<2);PORTC &=~ (1<<3);break;
  case 2: PORTC |= (1<<2);PORTC &=~ (1<<1);PORTC &=~ (1<<3);break;
  case 3: PORTC |= (1<<3);PORTC &=~ (1<<2);PORTC &=~ (1<<1);break;
  }*/
}

void value()
{
  moveX=0;
}

void button()
{



}

void graph()
{
  menu1();
  for (int i=48+moveX; i<=144+moveX; i++)
  lcd.drawLine(i-47-moveX,mass_out[i],i-47-moveX,mass_out[i+1],1);
    if (pos ==3)
    { 
    lcd.drawLine(map(moveX,-48,47,0,86),45,map(moveX,-48,47,0,86)+10,45,1);
    lcd.drawLine(map(moveX,-48,47,0,86),46,map(moveX,-48,47,0,86)+10,46,1);
    lcd.drawLine(map(moveX,-48,47,0,86),47,map(moveX,-48,47,0,86)+10,47,1);
    } 
  lcd.Update();
  delay(100);
  lcd.Clear_LCD();
}

void checkButton()
{
  if ((PINB & 0b00000010)&&(pos != 2)&&(pos != 3)) if (pos == 255) pos=1; else pos=255; 
  if ((PINB & 0b00000100)&&(pos != 1)&&(pos != 3)) if (pos == 255) pos=2; else pos=255;
  if ((PINB & 0b00010000)&&(pos != 2)&&(pos != 1)) if (pos == 255) pos=3; else pos=255;
}



void loop()
{
  if (pos != 3)
  {
  zamer();
  handing();//obrabotka
  value();
  }
  checkButton();
  graph();

}

