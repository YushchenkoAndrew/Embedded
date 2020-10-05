// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_march5.ino
    Created:	05-Mar-19 5:11:53 PM
    Author:     KOMP\Komp-PC
*/
int count = 0;
void setup()
{
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
}

void change_led(int q, int w, int e) {
	analogWrite(9, q);
	analogWrite(10, w);
	analogWrite(11, e);
}

// Add the main program code into the continuous loop() function
void loop()
{
	switch (count)
	{
	case 0: change_led(200, 255, 255); break;
	case 1: change_led(100, 255, 255);  break;
	case 2: change_led(15, 255, 255); 
		count = -1; break;
	}

	count++;
	delay(500);
}
