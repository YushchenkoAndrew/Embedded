#define WS2812B_pin 0x00030000
#define WS2812B_HIGH 0b0001000000000000;

// Functions
void RGB_update(int option, byte RED, byte GREEN, byte BLUE);

void setup()
{
  // pinMode realization using STM32 GPIO registers
  // PORTC->regs->CRH = (PORTA->regs->CRH & 0xFF0FFFF) | WS2812B_pin;
  pinMode(PB12, OUTPUT);
}

void loop()
{
  RGB_update(0, 0, 0, 0);
}

void RGB_update(int option, byte RED, byte GREEN, byte BLUE)
{
  GPIOB->regs->ODR |= WS2812B_HIGH;
  __asm__("nop\n\t"
          "nop\n\t"
          "nop\n\t"
          "nop\n\t"); //these are NOPS - these let us delay clock cycles for more precise timing

  GPIOB->regs->ODR &= ~WS2812B_HIGH;

  __asm__("nop\n\t"
          "nop\n\t"
          "nop\n\t"
          "nop\n\t"); //these are NOPS - these let us delay clock cycles for more precise timing

  __asm__("nop\n\t"
          "nop\n\t"
          "nop\n\t"
          "nop\n\t"); //these are NOPS - these let us delay clock cycles for more precise timing
}
