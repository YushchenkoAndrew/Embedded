#include<SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);   //Rx, Tx
void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bluetooth.available()){
    char a = bluetooth.read();
    switch(a){
      case 'q':{
        tone(7, 500);
        delay(100);
        noTone(7);
        break;
      }
      case 'w':{
        tone(7, 100);
        delay(200);
        noTone(7);
        break;
      }
    }
  }
}
