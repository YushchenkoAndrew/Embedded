bool q = 0;
int t = millis();

void setup() {
pinMode(13,OUTPUT);

Serial.begin(9600);
}

void loop() {
/*  q = !q;
 digitalWrite(10, q);
 digitalWrite(11, !q);
 delay(500);
 digitalWrite(10, !q);
 digitalWrite(11, q);
 delay(500);*/

  if (millis() - t >= 1000)
    {
      t = millis();
      digitalWrite(13, q=!q);
      if (q)
        Serial.println("led on");
      else 
        Serial.println("led off");
      
    }
 
}
