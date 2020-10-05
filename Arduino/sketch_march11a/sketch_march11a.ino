// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_march11a.ino
    Created:	11-Mar-19 10:18:13 PM
    Author:     KOMP\Komp-PC
*/

double i = 0;
double step = 0.0001;

void setup()
{
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
}

int brigth(double x, double u) {
	double store, out;
	store = modf(abs(255 * sin(x + u)), &out);
	return out;
}

// Add the main program code into the continuous loop() function
void loop()
{
	analogWrite(9, brigth(i / 3, 0));
	analogWrite(10, brigth(i * 2 / 3, 0));
	analogWrite(11, brigth(i, PI / 2));
	i += step;
}
