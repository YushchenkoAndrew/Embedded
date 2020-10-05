/*
 Name:		motor_8_2_.ino
 Created:	30-Dec-19 12:27:17 AM
 Author:	Andrew Yushchenko
*/

// the setup function runs once when you press reset or power the board
volatile bool q = false;
volatile int i = 10;
volatile int last;
int j;
bool w = false;
byte mirrow[10] = {
                0,
                3,
                2,
                1,
                0,
                7,
                6,
                5,
                4
};
byte pause[10] = {
                0,
                115,
                72,
                0,
                25,
                40,
                45,
                58,
                65
};
byte mass[90] = { 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x03,
  0x06, 0x0C, 0x18, 0x0C, 0x06, 0x03, 0x03, 0x06, 0x0C, 0x18, 0x30, 0xE0,
  0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x60, 0x30, 0x38, 0x2C, 0x26,
  0x23, 0x23, 0x26, 0x2C, 0x38, 0x30, 0x60, 0xC0, 0x80, 0x00, 0x00, 0xFF,
  0xFF, 0x08, 0x08, 0x08, 0x08, 0x08, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0E,
  0xBF, 0xBF, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void setup()
{
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(7, OUTPUT);
    last = 100;
    attachInterrupt(0, zero, FALLING);
    // attachInterrupt(1, hole, FALLING);
    while (q != 0);
    //  detachInterrupt(1);
}
void zero()
{
    q = 1;
}


bool pixel()
{
    switch (mirrow[i])
    {
    case 0: return bool(mass[j] & 1); break;
    case 1: return bool(mass[j] & 2); break;
    case 2: return bool(mass[j] & 4); break;
    case 3: return bool(mass[j] & 8); break;
    case 4: return bool(mass[j] & 32); break;
    case 5: return bool(mass[j] & 32); break;
    case 6: return bool(mass[j] & 64); break;
    case 7: return bool(mass[j] & 128); break;
    }
}
void readholes()
{
    if (q) { i = 0; q = 0; }
    else {
        if ((digitalRead(3) == 0) && (w))
        {
            i++;
            w = false;
        }
        if (digitalRead(3) == 1)
            w = true;
    }

}

void loop()
{
    readholes();
    if (last != i)
    {

        for (j = 0; j <= pause[i]; j++)
            digitalWrite(7, 0);
        for (j = 0; j <= 84; j++)
        {
            digitalWrite(7, pixel());
            delayMicroseconds(10);
        }
        digitalWrite(7, 0);
        last = i;
    }
}
