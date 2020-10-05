// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_march12b.ino
    Created:	12-Mar-19 5:31:54 PM
    Author:     KOMP\Komp-PC
*/

void setup()
{
	pinMode(9, INPUT);
	pinMode(13, OUTPUT);

}
bool q = 0, store = 0;

// Add the main program code into the continuous loop() function
void loop()
{
	if (digitalRead(9)) {
		delay(100);
		if (digitalRead(9)) {
			digitalWrite(13, q);
			q = !q;
		}
	}
	

}
