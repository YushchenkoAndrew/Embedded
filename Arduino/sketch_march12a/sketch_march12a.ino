// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_march12a.ino
    Created:	12-Mar-19 5:04:51 PM
    Author:     KOMP\Komp-PC
*/
const byte r = 9;
const byte g = 10;
const byte b = 11;

void setup()
{


}
void set_rgb(byte x, byte y, byte z) {
	for (int i = 0; i < 256; i++) {
		analogWrite(x, i);
		analogWrite(y, 255 - i);
		analogWrite(z, 255);
		delay(25);
	}
}

// Add the main program code into the continuous loop() function
void loop()
{
	set_rgb(r, g, b);
	set_rgb(g, b, r);
	set_rgb(b, r, g);

}
