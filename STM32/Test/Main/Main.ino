// Arduino script file *.ino

bool flag = true;

void setup()
{
  pinMode(PC13, OUTPUT);
}

void loop()
{
  digitalWrite(PC13, (flag ^= true));
  delay(200);
}
