/*
    PROJECT NAME - Programming EEPROM 
    DISCRIPTION  - Promgram EEPROM for z80 may in future complate project for programming another EEPROM, EPROM
    DATE - 13.01.20
    AUTOR - Andrew Yushchenko

 */
 
#define eeprom 0   //For program EEPROM this value shoud be 1 for FLASH or else 0

#define WE 14
#define OE 15
#define CE 16

//counter pin
#define CLK1 17
#define CLK2 18
#define Reset 19

#define RedLed 10
#define GreenLed 11

char data[1024] = {
0x3e, 0x38, 0xd3, 0x50, 0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x06, 0x00, 0x3e, 0x0f, 0xd3, 0x50,
0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x12, 0x00, 0x3e, 0x06, 0xd3, 0x50, 0x3e, 0x00, 0x3c, 0xfe,
0x2f, 0xc2, 0x1e, 0x00, 0x3e, 0x48, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x2a, 0x00,
0x3e, 0x45, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x36, 0x00, 0x3e, 0x4c, 0xd3, 0x60,
0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x42, 0x00, 0x3e, 0x4c, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe,
0x2f, 0xc2, 0x4e, 0x00, 0x3e, 0x4f, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x5a, 0x00,
0x3e, 0x20, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x66, 0x00, 0x3e, 0x57, 0xd3, 0x60,
0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x72, 0x00, 0x3e, 0x4f, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe,
0x2f, 0xc2, 0x7e, 0x00, 0x3e, 0x52, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x8a, 0x00,
0x3e, 0x4c, 0xd3, 0x60, 0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0x96, 0x00, 0x3e, 0x44, 0xd3, 0x60,
0x3e, 0x00, 0x3c, 0xfe, 0x2f, 0xc2, 0xa2, 0x00, 0xc3, 0xab, 0x00, 0xdb, 0x00, 0xd3, 0x10, 0xc3,
0xab, 0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, };


void setup() {
    initializeInput();
    


    //Make disable EEPROM
    defaultState();
    
    //set into started position clock
    digitalWrite(CLK1, 0);
    digitalWrite(CLK2, 0);
    digitalWrite(Reset, 1);
    delay(1);
    digitalWrite(Reset, 0);

    ready();

    Serial.begin(9600);

    menuCommand();
}

void defaultState() {
  
    digitalWrite(CE, eeprom);
    digitalWrite(OE, eeprom);
    digitalWrite(WE, !eeprom);
}

void readData() {
    //Input pin 2 - 9 (for data write/read)
    for (int i = 2; i < 10; i++)
        pinMode(i, INPUT);

    digitalWrite(CE, 0);
    digitalWrite(OE, 0);
    digitalWrite(WE, !eeprom);

    resetClock();
    for (int k = 0; k < 8; k++) {
        for (int i = 0; i < 256; i++)
        {
            int sum = 0;
            int scale = 1;
    
            for (int j = 2; j < 10; j++) {
    //            Serial.print(digitalRead(j));
                sum += digitalRead(j) * scale;
                scale *= 2;
            }
    
            if (i % 16 == 0)
                Serial.println("\n");
            Serial.print(sum, HEX);
            Serial.print("\t");
            
    
            nextAdressCLK1();
        }
        Serial.println("\n");
        nextAdressCLK2();
    }

    ready();
}

//This function make a signal for EEPROM to save data
void nextAdressCLK1() {
    delay(1);
    digitalWrite(CLK1, 0);
    delay(1);
    digitalWrite(CLK1, 1);
    delay(1);
}

void nextAdressCLK2() {
    delay(1);
    digitalWrite(CLK2, 0);
    delay(1);
    digitalWrite(CLK2, 1);
    delay(1);
}

void resetClock() {
    delay(1);
    digitalWrite(Reset, 1);
    delay(1);
    digitalWrite(Reset, 0);
    delay(1);
}


//Print out that it's  --busy--
void busy() {
    digitalWrite(RedLed, 1);
    digitalWrite(GreenLed, 0);
}

//Print out that it's  --ready--
void ready() {
    digitalWrite(RedLed, 0);
    digitalWrite(GreenLed, 1);
}

//If am I right, lines below not needed

//Initialize input pin
void initializeInput()
{
    pinMode(RedLed, OUTPUT);
    pinMode(GreenLed, OUTPUT);

    pinMode(WE, OUTPUT);
    pinMode(OE, OUTPUT);
    pinMode(CE, OUTPUT);

    pinMode(CLK1, OUTPUT);
    pinMode(CLK2, OUTPUT);
    pinMode(Reset, OUTPUT);
}


//Function for write data in EEPROM
void writeData()
{
    for (int i = 2; i < 10; i++)
        pinMode(i, OUTPUT);

    digitalWrite(OE, 1);
    digitalWrite(WE, 1);
    
    resetClock();
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i <= 255; i++) {
            digitalWrite(CE, 0);
            digitalWrite(WE, 0);
            delay(1);
    
            int scale = 1;
    
            for (int j = 2; j < 10; j++) {
                digitalWrite(j, bool(data[i + k * 256] & scale));
                scale *= 2;
            }
            delay(1);
    
            digitalWrite(WE, 1);
            delay(1);
            digitalWrite(CE, 1);
    
            nextAdressCLK1();
    
        }
        nextAdressCLK2();
    }
    digitalWrite(OE, 0);
}

void menuCommand() {
    Serial.println("\nCommand for Program_EEPROM");

    Serial.println("0\t--\tRead from EEPROM HEX");
    Serial.println("1\t--\tWrite data to EEPROM");
    Serial.println("\\n\t--\tPrint Menu");
}

void loop() {
    if (Serial.available() > 0) {
        switch (Serial.read())
        {
        case '0': {
            busy();
            readData();
            ready();
            break;
        }
        case '1': {
            busy();
            writeData();
            ready();
            break;
        }

        case '\n': {
            busy();
            menuCommand();
            ready();
            break;
        }
        default:
            Serial.println("Your command not exist, check it again!\n");
            menuCommand();
            break;
        }
    }
    
    defaultState();
    delay(100);
}
