#include<SPI.h>
#include<SD.h>
File file;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(250000);
  while(!Serial);
  if (!SD.begin(4)){Serial.println("failed"); return;}
  Serial.println("OK");
  file=SD.open("test.txt");
  boolean b=file.seek(2);
  Serial.print(b);
  Serial.write(file.read());
  file.close();
}

void loop() {
  // put your main code here, to run repeatedly:

}
