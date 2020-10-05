boolean q = 0;
int t;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 1; i < 11; i++)
  {
    Serial.println(i);
    delay(100);
  }
}
