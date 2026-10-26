/*
 * 02_i2c_scanner.ino  -  Phase 2: I2C basics + bus scan
 *
 * Purpose:
 *   Scan every 7-bit I2C address and print which ones respond (ACK).
 *   With the wiring in docs/wiring.md you should expect:
 *     0x60  -> ATECC608 secure element (SparkFun Qwiic breakout)
 *     0x68  -> MPU-6050 IMU (0x69 if its AD0 pin is pulled high)
 *
 * Wiring: SDA = GPIO21, SCL = GPIO22, both modules powered from 3.3 V.
 * Serial: 115200 baud
 *
 * How it works:
 *   For each address we start a transmission and end it immediately with no
 *   data. Wire.endTransmission() returns 0 if a device acknowledged.
 *
 * Note about the ATECC608:
 *   The ATECC608 sleeps when idle and needs a special "wake" condition
 *   before it talks. Depending on its state it may or may not ACK a plain
 *   address probe, so 0x60 missing from the scan does not by itself mean a
 *   wiring fault. TODO: investigate the wake behavior in phases 3 and 6 and
 *   record what you actually see in docs/lab-notebook.md.
 */

#include <Arduino.h>
#include <Wire.h>

const int I2C_SDA = 21;
const int I2C_SCL = 22;
const unsigned long SCAN_INTERVAL_MS = 5000;

// Print a byte as 0xNN
void printHex(uint8_t value) {
  Serial.print("0x");
  if (value < 0x10) Serial.print('0');
  Serial.print(value, HEX);
}

// Return a short label for addresses this project expects to see.
const char* labelFor(uint8_t address) {
  switch (address) {
    case 0x60: return "  <- ATECC608 secure element?";
    case 0x68: return "  <- MPU-6050 IMU?";
    case 0x69: return "  <- MPU-6050 IMU (AD0 high)?";
    default:   return "";
  }
}

void scanBus() {
  uint8_t found = 0;
  Serial.println("Scanning I2C bus (0x01 - 0x7E)...");

  // Addresses 0x00 and 0x7F are reserved, so skip them.
  for (uint8_t address = 1; address < 0x7F; address++) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("  Device found at ");
      printHex(address);
      Serial.println(labelFor(address));
      found++;
    } else if (error == 4) {
      Serial.print("  Unknown error at ");
      printHex(address);
      Serial.println();
    }
    // Other error codes (2 = NACK on address, etc.) just mean "nothing here".
  }

  Serial.print("Scan done. Devices found: ");
  Serial.println(found);
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println();
  Serial.println("Anti-Spoof Rep Validator - 02_i2c_scanner");

  Wire.begin(I2C_SDA, I2C_SCL);   // ESP32 lets us choose the I2C pins
  Wire.setClock(100000);          // Standard mode 100 kHz: easy to sniff later
}

void loop() {
  scanBus();
  delay(SCAN_INTERVAL_MS);
}
