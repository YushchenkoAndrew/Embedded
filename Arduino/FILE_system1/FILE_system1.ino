#include <SPI.h>
#include <SD.h>


File test;

String string="";
int i=0;
int j=-1;

void  setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Initializing SD card...");

  if(!SD.begin(4))
  {
    Serial.println("failed");
    return;
  }
  Serial.println("Okey");

  test=SD.open("test.txt",FILE_WRITE);

  if (test)
  {
    Serial.println("test.txt open");
    Serial.println("write: This is my first work with file and SD");
    test.println("12345");
    test.close();
  }
  else  Serial.println("test.txt don't open");

  Serial.println("Done.");
  
  test=SD.open("test.txt");

  if (test)
  {
     Serial.println("test.txt open");
     while (test.available())
     {
     string+=char(test.read());
     
     }
     test.close();
  }
  else  Serial.println("test.txt don't open");

 for(i=0; i<=string.length(); i++)
 Serial.print(string[i]);
  Serial.println("Okey");
  
 // string="123/45";
  Serial.print(string.toInt());
//  Serial.println(" ");

  
  
  SD.remove("test.txt");
  Serial.end();
  
}
void loop()
{
  
}

