/*
 * This sketch demonstrates the use of flash memory
 * 
 * Ameba's flash memory can be edit in a unit of sector which has size of 
 * 4K bytes.
 *
 * To read data from flash memory, we can just read it.
 *
 * To write data to flash memory, each bit on flash memory can only change
 * from '1' to '0' and it cannot change from '0' to '1'. To make sure the
 * data are correctly written we do erase flash memory sector before write
 * data on it.
 * 
 * This sketch store boot count in flash. Each time device boot up, it read
 * boot count from flash, add one, and write back to flash.
 */

#include <FlashMemory.h>

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    continue; // wait for serial port to connect. Needed for native USB port only
  }
  int k = 3.5;
  // default start: 0xFF000
  // sector size: 0x1000
  FlashMemory.begin(0x00010000, 0x1000);
  Serial.println("Hello ARTEM");
}

void loop() {
  Serial.println("start:");
  for (unsigned int offset = 0; offset < 0x1000; offset += 4) {
    Serial.print(FlashMemory.readWord(offset), HEX);
  }
   Serial.println("\n\n\n\n");
  delay(2000);
}
