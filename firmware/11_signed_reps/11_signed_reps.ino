/*
 * 11_signed_reps.ino  -  Phase 11: Signed reps with counter + hash chain
 *
 * Purpose (TODO - not implemented yet):
 *   Combine the rep counter (phase 5) with ATECC608 signing (phase 9).
 *   For every detected rep, build a record, sign it, and print it as one
 *   line over Serial for the PC to log and verify.
 *
 * Planned record fields (TODO: finalize and keep in sync with verifier/verify.py):
 *   - version         record format version
 *   - serial          ATECC608 serial number (device ID)
 *   - counter         monotonic counter value (must strictly increase)
 *   - rep data        e.g. timestamp, peak angle, rep duration
 *   - prev_hash       SHA-256 of the previous record (all zeros for the first)
 *   - signature       ECDSA P-256 over SHA-256 of all fields above
 *
 * Libraries: SparkFun ATECCX08a, Adafruit MPU6050, Adafruit Unified Sensor
 */

#include <Arduino.h>
#include <Wire.h>
// TODO: #include <SparkFun_ATECCX08a_Arduino_Library.h>
// TODO: #include <Adafruit_MPU6050.h>
// TODO: #include <Adafruit_Sensor.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  // TODO: init IMU (phase 4/5) and ATECC608 (phase 9).
  // TODO: decide where the monotonic counter lives and how it survives reboots.
  // TODO: decide how prev_hash is initialized after a reboot.
}

void loop() {
  // TODO: run rep state machine; on each completed rep:
  //   1. increment monotonic counter
  //   2. serialize fields in a fixed byte order (document it!)
  //   3. SHA-256 the serialized bytes, sign with the ATECC608
  //   4. print the record line, then set prev_hash = hash of this record
}
