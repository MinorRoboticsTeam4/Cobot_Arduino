#include <PN532.h>

#define MISO 50 // Master-in Slave-out
#define MOSI 51 // Master-out Slave-in
#define SCK 52  
#define SS 53 // Version-Firmware

PN532 nfc(SCK, MISO, MOSI, SS);

void setup(void) {
  Serial.begin(9600);
  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
   }
   
  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println
  ((versiondata>>24) & 0xFF, HEX);
   Serial.print("Firmware ver. "); Serial.print
  ((versiondata>>16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata>>8) &
  0xFF, DEC);
  Serial.print("Supports "); Serial.println(versiondata &
  0xFF, HEX);

  // configure board to read RFID tags and cards
  nfc.SAMConfig();
}

void loop(void) {
  uint32_t id;
  // look for MiFare type cards
  id = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A);
  if (id != 0) {
    Serial.print("Read card #"); Serial.println(id);
  }
}
