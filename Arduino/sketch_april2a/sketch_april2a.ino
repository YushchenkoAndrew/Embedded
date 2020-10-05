// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_april2a.ino
    Created:	02-Apr-19 4:37:18 PM
    Author:     KOMP\Komp-PC
*/


void setup()
{
	pinMode(A0, INPUT);
	pinMode(11, OUTPUT);
	Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop()
{
		digitalWrite(11, analogRead(A0) > 500 ? 1:0);
	delay(20);
}
