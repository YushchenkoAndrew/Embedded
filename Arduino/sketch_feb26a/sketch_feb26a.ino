void setup() {
  //expample launch timer for interruot 1 ms
  TCCR0A |= (1 << WGM01);
  OCR0A = 0xF9;   //set number for compare in counter
  TCCR0B |= (1 << CS01) | (1 << CS00);  //set clk/64
  TIMSK0 |= (1 << OCIEOA);  //using chanel
  sei();  //start all inerrupt (launch new setting)
}

//function inerrupt 
ISR (TIMER0_COMPA_vect)
{
  
}

//intersting fact: volatile -- use for change over program...?

void loop() {

}
