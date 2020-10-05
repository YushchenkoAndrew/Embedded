// Arduino script file *.ino

bool flag = true;

void setup()
{
  pinMode(PC13, OUTPUT);
}

void loop()
{
  // digitalWrite(PC13, (flag ^= true));
  GPIOC->regs->ODR |= 0b0010000000000000;
  delay(200);
  GPIOC->regs->ODR &= ~(0b0010000000000000);
  delay(200);
}
