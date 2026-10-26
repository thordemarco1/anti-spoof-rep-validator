/*
 * 06_atecc_info.ino  -  Phase 6: ATECC608 read-only intro
 *
 * Purpose (TODO - not implemented yet):
 *   Wake the ATECC608 (I2C 0x60), print its serial number, revision, and
 *   config zone, and report whether the config and data zones are locked.
 *
 * !! READ-ONLY !!  This sketch must NEVER write config or call any lock
 * function. Locking is permanent - see docs/atecc608-config-notes.md.
 *
 * Library: SparkFun ATECCX08a Arduino Library
 */

#include <Arduino.h>
#include <Wire.h>
// TODO: #include <SparkFun_ATECCX08a_Arduino_Library.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  // TODO: begin the ATECC608 and print a clear error if it does not respond.
  // TODO: read config zone and print: serial number, revision, lock status.
  // TODO: copy the output into docs/lab-notebook.md.
}

void loop() {
  // Nothing to do repeatedly.
}
