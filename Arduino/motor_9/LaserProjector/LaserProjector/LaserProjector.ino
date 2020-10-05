/*
	PROJECT NAME: LaserProjector.ino
	DESCRIPTION:  Improve some the latest version of this project
	DATE:	      30-Dec-19 8:40:14 PM
	AUTHOR:	      Andrew Yushchenko
*/

#include"LaserProjector.h"

#define pinLaser 5
#define startPoint 2
#define mirrowLevel 3

volatile char indexMirrow = 0;

volatile char data[50] = { 0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xFF,
  0x00, 0xC6, 0xC7, 0xC7, 0xFF, 0xFF, 0xFF, 0xC0 };
volatile char dataSize = 16;

// This parameter need for show bits of data and for correct mechanical error for mirrow system
volatile int index = 0;	


const char mirrowPosition[8] = { 0, 6, 5, /**/4, /**/3, /**/2, /**/1, 7 };

const char mirrowBit[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

const char mirrowCorrection[8] = { 101, 114, 122, 100, 110, 94, 97, 87 };


void setup() {
	pinMode(13, OUTPUT);

	pinMode(pinLaser, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(startPoint), setInStartPosition, LOW);
}

volatile bool a = false;	//For testing 


// Paint pixels
ISR(TIMER0_COMPA_vect) {
	cli();

	digitalWrite(pinLaser, ((index + 1 < 0) || (index > dataSize)) ? 0 : data[index] & mirrowBit[mirrowPosition[indexMirrow]]);
	index++;

	sei();
}

void setInStartPosition() {
	cli();
  	TCCR0A = 0;		// set entire TCCR0A register to 0
  	TCCR0B = 0;		// same for TCCR0B
  	TCCR0A |= (1 << WGM01);		// turn on CTC mode
  	TCCR0B |= (1 << CS01);
  
  	OCR0A = 40;	// ~it would be called every (n -- ms)
  	TIMSK0 |= (1 << OCIE0A);	// enable timer compare interrupt
  	TCNT0 = 0;		//initialize counter value to 0
	sei();

	detachInterrupt(digitalPinToInterrupt(startPoint));

	attachInterrupt(digitalPinToInterrupt(startPoint), dataTransmite, FALLING);
	attachInterrupt(digitalPinToInterrupt(mirrowLevel), nextMirrow, FALLING);
}

void nextMirrow() {
	indexMirrow = indexMirrow == 8 ? 0 : indexMirrow + 1;
	index = -mirrowCorrection[mirrowPosition[indexMirrow]];
}

void dataTransmite() {
	indexMirrow = 0;
//  laserP.indexMirrow = 0;
}

// the loop function runs over and over again until power down or reset
void loop() {

}
