#define i_CLK  14
#define o_MISO 15
#define i_MOSI 16
#define i_CS   17

#define NEGATIVE_WAIT_STATE 0
#define DATA_RECIVE_STATE 1
#define DATA_END_STATE 2
#define ENABLE_STATE 3
#define ENABLE_WAIT_STATE 4
#define POSITIVE_WAIT_STATE 5


#define DATA_IN_ONE_BITE 8


#define CHECK_RESIVED_DATA_STATE 0
#define ECHO_STATE 227                // 'hE3
#define RESET_COMMAND_STATE 255       // 'hFF
#define RESEND_DATA_STATE 254         // 'hFE
#define EMPTY_STATE 240               // 'hF0
#define SEND_DATA_STATE 243           // 'hF3
#define STREAM_SIZE_STATE 247         // 'hF7

#define SERIAL_WRITE_BYTE_STATE 253   // 'hFD
#define SERIAL_WRITE_STATE 252        // 'hFC
#define SERIAL_READ_STATE 251         // 'hFB

#define READ_SD_STATE 224             // 'hE0

#define OPERATION_FAILED 0
#define OPERATION_SUCCESSED 255

byte MasterData = 0;
byte SlaveData = 0;
byte PrevSlaveData = 0;

byte RecivedData = 0;

byte Index = 0;

byte Buffer[200];
byte BufferIndex = 0;                       // Current position of curson in buffer
byte DataStreamIndex = 0;

byte SPI_STATE = 0;
byte PREV_COMMAND_STATE = EMPTY_STATE;
byte COMMAND_STATE = 0;

boolean getData = 0;

void setup() {
  // Set pinout for SPI in Slave Mode
  pinMode(i_CLK,  INPUT);
  pinMode(o_MISO, OUTPUT);
  pinMode(i_MOSI, INPUT);
  pinMode(i_CS,   INPUT);
  
  pinMode(13,   OUTPUT);

  digitalWrite(o_MISO, 0);

  Serial.begin(2000000);

  Serial.println("Start!");
}

void SPI_State_Machine() {
   switch (SPI_STATE) {
    
     case NEGATIVE_WAIT_STATE: 
        SPI_STATE = PINC & B000001 ? ENABLE_STATE : NEGATIVE_WAIT_STATE;
        break;
  
     case ENABLE_STATE:
        SPI_STATE = PINC & B001000 ? DATA_END_STATE : DATA_RECIVE_STATE;
        break;
  
     case DATA_RECIVE_STATE:
        MasterData = MasterData | ((PINC & B000100) ? 1 << Index : 0);
        if (SlaveData & (1 << Index))
          PORTC |= (1 << 1);
        else
          PORTC &= ~(1 << 1);
        Index++;
        SPI_STATE = POSITIVE_WAIT_STATE;
        break;
   
     case DATA_END_STATE:
        Index = 0;
        RecivedData = MasterData;
        MasterData = 0;
        COMMAND_STATE = CHECK_RESIVED_DATA_STATE;
        SPI_STATE = ENABLE_WAIT_STATE;
        break;
  
     case ENABLE_WAIT_STATE:
        SPI_STATE = PINC & B001000 ? ENABLE_WAIT_STATE : NEGATIVE_WAIT_STATE;
        break;
  
     case POSITIVE_WAIT_STATE: 
        SPI_STATE = PINC & B000001 ? POSITIVE_WAIT_STATE : NEGATIVE_WAIT_STATE;
        break;
      
   }
}

void deviceCommand() {
  switch (COMMAND_STATE) {

    // -------------SYSTEM COMMAND-------------
    
    case CHECK_RESIVED_DATA_STATE:
      COMMAND_STATE = RecivedData & (1 << 7) ? RecivedData :  PREV_COMMAND_STATE;
      PREV_COMMAND_STATE = COMMAND_STATE;
      break;

    case ECHO_STATE:
      PrevSlaveData = SlaveData;
      SlaveData = RecivedData;
      break;

    case RESET_COMMAND_STATE:
      COMMAND_STATE = EMPTY_STATE;
      PREV_COMMAND_STATE = EMPTY_STATE;
      PrevSlaveData = SlaveData;
      BufferIndex = 0;
      DataStreamIndex = 0;
      SlaveData = 0;
      break;

    case RESEND_DATA_STATE:
      SlaveData = PrevSlaveData;
      break;

    case SEND_DATA_STATE:
      SlaveData = DataStreamIndex < BufferIndex ? Buffer[DataStreamIndex++] : 0;
      PrevSlaveData = SlaveData;
      break;

    case SERIAL_WRITE_BYTE_STATE:
      Serial.print("Data - ");
      Serial.println(RecivedData, HEX);
      COMMAND_STATE = EMPTY_STATE;
      break;

    case SERIAL_WRITE_STATE:
      Serial.print(char(RecivedData));
      COMMAND_STATE = EMPTY_STATE;
      break;

    case SERIAL_READ_STATE:
      if (Serial.available() > 0) {
        byte storeSize = BufferIndex;
        while (Serial.available() && (storeSize + DATA_IN_ONE_BITE) > BufferIndex) {
          Buffer[BufferIndex++] = Serial.read();
        }
        DataStreamIndex = 0;
        SlaveData = Serial.available() ? OPERATION_FAILED : OPERATION_SUCCESSED;
        Serial.println("Reading....");
      }
      else {
        SlaveData = OPERATION_FAILED;
      }
      
      COMMAND_STATE = EMPTY_STATE;
      break;

    case STREAM_SIZE_STATE:
      if (Serial.available()) {
        SlaveData = OPERATION_FAILED;
        COMMAND_STATE = PREV_COMMAND_STATE;
      }
      else {
        SlaveData = BufferIndex;
        COMMAND_STATE = EMPTY_STATE;
      }
      break;

    case EMPTY_STATE:
      break;



    // -------------SD CARD COMMAND-------------

    case READ_SD_STATE:
      break;    




    // -------------Error COMMAND-------------
    default:
      SlaveData = 33;                 // 'h21 - This code mean that "Such Command doesn't Exist!"
      break;
  }
}

void loop() {
 
  SPI_State_Machine();
  deviceCommand();

  digitalWrite(13, digitalRead(i_CS));
  
}
