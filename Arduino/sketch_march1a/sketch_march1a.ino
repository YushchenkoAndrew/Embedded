// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       sketch_march1a.ino
    Created:	01-Mar-19 5:11:56 PM
    Author:     KOMP\Komp-PC
*/

void setup() {
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS00) | (1 << CS01);
	OCR0A = 0xF9;	//250
	OCR0B = 0x7D;	//125
	TIMSK0 |= (1 << OCIE0B) | (1 << OCIE0A);
	sei();
}

volatile int count_a = 0, count_b = 0;

ISR(TIMER0_COMPA_vect) {
	count_a++;
}
ISR(TIMER0_COMPB_vect) {
	count_b++;
}
void reset(bool q) {
	if (q) {
		cli();
		count_a = 0;
		sei();
	}
	else {
		cli();
		count_b = 0;
		sei();
	}

}

int count_1, count_2, last_1, last_2, fric = 200;

void loop() {
	cli();
	count_1 = count_a;
	count_2 = count_b;
	sei();
	switch (count_1 / fric) {
	case 1: {
		digitalWrite(4, 1);
		digitalWrite(5, 0);
		digitalWrite(6, 0);
		break;
	}
	case 2: {
		digitalWrite(4, 0);
		digitalWrite(5, 1);
		digitalWrite(6, 0);
		break;
	}
	case 3: {
		digitalWrite(4, 0);
		digitalWrite(5, 0);
		digitalWrite(6, 1);
		break;
	}
	case 4: {
		digitalWrite(4, 0);
		digitalWrite(5, 1);
		digitalWrite(6, 0);
		reset(1);
		break;
	}
	}


	switch (count_2 / fric) {
	case 1: {
		digitalWrite(7, 0);
		digitalWrite(8, 0);
		digitalWrite(9, 1);
		break; 
	}
	case 2: {
		digitalWrite(7, 0);
		digitalWrite(8, 1);
		digitalWrite(9, 0);
		break;
	}
	case 3: {
		digitalWrite(7, 1);
		digitalWrite(8, 0);
		digitalWrite(9, 0);
		break;
	}
	case 4: {
		digitalWrite(7, 0);
		digitalWrite(8, 1);
		digitalWrite(9, 0);
		reset(0);
		break;
	}
	}

}