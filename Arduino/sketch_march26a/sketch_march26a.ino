// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_march26a.ino
    Created:	26-Mar-19 4:34:38 PM
    Author:     KOMP\Komp-PC
*/



void setup()
{
	pinMode(2, INPUT);
	pinMode(13, OUTPUT);
	Serial.begin(9600);
}
boolean prev_state = 1, current, q = 0;

// Add the main program code into the continuous loop() function
void loop()
{
	digitalWrite(13, digitalRead(2));
	Serial.println(digitalRead(2));
	delay(70);
}
/*
	if (current != prevState)
	{
	delay(20);
	currentState = digitalRead(2);
	}
	prevState = current;

	if (current == 0 && flag == 0){
	digitaWrite(13, q= !q);
	}
*/
