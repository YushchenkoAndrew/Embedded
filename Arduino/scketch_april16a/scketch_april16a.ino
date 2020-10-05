// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       scketch_april16a.ino
    Created:	16-Apr-19 4:34:34 PM
    Author:     KOMP\Komp-PC
*/
void setup()
{
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	Serial.begin(9600);
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS01) & (1 << CS00);
	OCR0A = 0xF9;
	TIMSK0 |= (1 << OCIE0B) | (1 << OCIE0A);
	cli();
}

volatile int countTimer = 0;

volatile int counter = 0;

ISR(TIMER0_COMPA_vect) {
	countTimer++;

	Serial.println(counter);
}

boolean last = 0, current = 0, flag = 0, q = 0;
// Add the main program code into the continuous loop() function
void loop()
{
	if (countTimer >= 30 && flag == 1) {
		cli();
		countTimer = 0;
		flag = 0;
		if (current == 0 && last == 1) {
		}
		last = current;
	}

	if (last != digitalRead(2) && flag == 0) {
		current = digitalRead(2);
		if (!digitalRead(2)){
			if (digitalRead(3))
				counter++;
			else
				counter--;
			}
		flag = 1;
		sei();
	}
	
}
