// Acknowledgments
// Utilizes example RFID code from https://github.com/miguelbalboa/rfid and https://www.instructables.com/Arduino-MFRC522-RFID-READER/ 

#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9 
#define SS_PIN          10 

MFRC522 mfrc522(SS_PIN, RST_PIN); 
MFRC522::MIFARE_Key key;
Servo servo1;

const int buttonPin = 7;
byte masterUID[] = {0x63, 0x4A, 0xE9, 0xFB};

void setup() {
    Serial.begin(9600);
    while (!Serial); 
    SPI.begin();
    mfrc522.PCD_Init();

    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

    servo1.attach(3);
    servo1.write(120);
    pinMode(7, OUTPUT);

    mfrc522.PCD_AntennaOn(); 

    byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
    Serial.print(F("Reader Version: 0x"));
    Serial.println(v, HEX);
    Serial.println(F("System Ready"));
}

void loop() {
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;
    
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // code for rfid tag
    if (mfrc522.uid.uidByte[0] == 0x63 && mfrc522.uid.uidByte[1] == 0x4A && mfrc522.uid.uidByte[2] == 0xE9 && mfrc522.uid.uidByte[3] == 0xFB)
    {
      Serial.println("THIS IS THE RFID TAG");
      servo1.write(120);
      delay(1000); 
      servo1.write(0);
      digitalWrite(7, HIGH); 
      delay(1000); 
    } 
    // code for rfid card
    else if (mfrc522.uid.uidByte[0] == 0x1B && mfrc522.uid.uidByte[1] == 0x79 && mfrc522.uid.uidByte[2] == 0xF3 && mfrc522.uid.uidByte[3] == 0x00)
    {
      Serial.println("THIS IS THE RFID CARD");
      servo1.write(120);
      delay(2500); 
      digitalWrite(7, LOW); 
    }
    // unknown/unrecognized card
    else {
      Serial.println("UNKNOWN CARD");
      digitalWrite(7, HIGH); 
      delay(100); 
      digitalWrite(7, LOW);
      delay(100);
      digitalWrite(7, HIGH); 
      delay(100); 
      digitalWrite(7, LOW);
      delay(100);  
    }
  
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}

// FOR DEBUG: Helper routine to dump a byte array as hex values to Serial. 
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}