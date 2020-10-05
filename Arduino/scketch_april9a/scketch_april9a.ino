// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       scketch_april9a.ino
    Created:	09-Apr-19 4:30:46 PM
    Author:     KOMP\Komp-PC
*/

void setup()
{
	Serial.begin(9600);
	pinMode(7, INPUT_PULLUP);
}

// Add the main program code into the continuous loop() function
void loop()
{
	Serial.print("X ");
	Serial.println(analogRead(A0));
	Serial.print("Y ");
	Serial.println(analogRead(A1));
	Serial.print("Z ");
	Serial.println(!digitalRead(7));
	delay(500);
}
