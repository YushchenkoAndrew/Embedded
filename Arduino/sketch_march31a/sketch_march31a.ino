// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_march31a.ino
    Created:	31-Mar-19 11:21:05 PM
    Author:     KOMP\Komp-PC
*/

void setup()
{
	pinMode(13, OUTPUT);
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS01) & (1 << CS00);
	OCR0A = 0xF9;
	TIMSK0 |= (1 << OCIE0B) | (1 << OCIE0A);
	cli();
}

volatile int countTimer = 0;

ISR(TIMER0_COMPA_vect) {
	countTimer++;
}

boolean last = 0, current = 0, flag = 0, q = 0;
// Add the main program code into the continuous loop() function
void loop()
{
	if (countTimer >= 50 && flag == 1) {
		cli();
		countTimer = 0;
		flag = 0; 
		if (current == 1 && last == 0)
			digitalWrite(13, q = !q);
		last = current;
	}

	if (last != digitalRead(2) && flag == 0) {
		current = digitalRead(2);
		flag = 1;
		sei();
	}

}
