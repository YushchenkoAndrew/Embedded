// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       tets 1.2.ino
    Created:	26-Feb-19 7:02:51 PM
    Author:     KOMP\Komp-PC
*/
#include<stdio.h>
bool q = 0;

void setup()
{
	pinMode(13, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	digitalWrite(13, q);
	printf("%d",q);
	q = !q;
	delay(1000);

}
