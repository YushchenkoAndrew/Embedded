#include <Servo.h>
#include <IRremote.h>

Servo servo;

IRrecv irrecv(4);
decode_results result;

boolean r = 1, b = 1, g = 1; 

void setup() {
  servo.attach(8);
  servo.write(10);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(5, r);
  digitalWrite(6, r);
  digitalWrite(7, r);
  irrecv.enableIRIn();
}

int degree = 0;

void loop() {
  if (irrecv.decode(&result)) {
    Serial.println(result.value, HEX);
    switch(result.value){
      case 0xEF625707:
      digitalWrite(5, r);
      r = !r;
      break;
      case 0x484D1545:
      digitalWrite(6, g);
      g = !g;
      break;
      case 0x89DB6CC9:
      digitalWrite(7, b);
      b = !b;
      break;

      case 0xF84D5447:
      if(r){
        degree += 20;
        if (degree > 170)
        degree = 170;
        servo.write(degree);
      }
      break;
     case 0xBCEC76CB:
     if(r){
        degree -= 20;
        if (degree < 10)
        degree = 10;
        servo.write(degree);
       }
      break;
    }
    irrecv.resume();
  }

}
