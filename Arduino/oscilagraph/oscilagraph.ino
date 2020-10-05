#include "lcd1202.h"

#define FASTADC 1
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

LCD1202 lcd(8, 7, 6, 5);

int mass_in[100],mass_out[100],pause=40,position1=0;

void setup()
{
    
  #if FASTADC
    sbi(ADCSRA,ADPS2) ;
    cbi(ADCSRA,ADPS1) ;
    cbi(ADCSRA,ADPS0) ;
  #endif
  
  lcd.Inicialize();
  lcd.Clear_LCD();
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  analogWrite(9,40);
}
void loop()
{
  pause=40;
  if (position1 > 5*96/8) pause=pause+10;
  else if (position1 < 3*96/8) pause=pause-10;
  /*else if (position1 > 96/2) pause=pause+2;
  else if (position1 < 96/2) pause=pause-2;*/

  if (pause < 40) pause=40;

    int i=0; while((analogRead(A0) < 32)&&(i<32768))i++;
      i=0; while((analogRead(A0) > 32)&&(i<32768))i++;

  for (int i=1; i<96; i++)
  {
    mass_in[i]=analogRead(A0);
    if (pause > 40) delayMicroseconds(pause-40);
  }


  for (int i=0; i<96; i++)
  {
  if (mass_in[i]>>5 < 0b111111) mass_out[i] = mass_in[i]>>5 & 0b111111;
      else mass_out[i] = 0b111111;
  mass_out[i]=33-mass_out[i];
  }

  position1=1;
  while ((mass_out[position1] < 16)&&(position1 < 95)) position1++;
  position1++;
  while ((mass_out[position1] > 16)&&(position1 < 95)) position1++;

  for (int i=1; i<96; i++)
    lcd.drawLine(i-1,mass_out[i-1],i,mass_out[i],1);
/*  for (int i=2; i<96; i++)
    lcd.drawPixel(i,mass_out[i],1);*/

    lcd.Update();
    delay(100);
    lcd.Clear_LCD();
}

