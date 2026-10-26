/*
 * 09_first_signature.ino  -  Phase 9: Key generation, first signature, public key export
 *
 * Purpose (TODO - not implemented yet):
 *   1. Generate an ECDSA P-256 key pair INSIDE the ATECC608 (private key
 *      never leaves the chip and is never readable).
 *   2. Print the public key so it can be saved on the PC for the verifier.
 *   3. Sign a fixed test message and print the message + signature.
 *
 * Prerequisite: phase 8 done (config + data zones locked per the slot plan).
 * Library: SparkFun ATECCX08a Arduino Library
 *
 * Security notes:
 *   - Run key generation deliberately, once. Regenerating replaces the key.
 *   - Capture the I2C bus during this sketch (phase 3 setup) to show that
 *     only the public key and signature appear on the wire.
 */

#include <Arduino.h>
#include <Wire.h>
// TODO: #include <SparkFun_ATECCX08a_Arduino_Library.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  // TODO: begin ATECC608, confirm zones are locked, else stop.
  // TODO: generate key in the slot chosen in docs/atecc608-config-notes.md.
  // TODO: read + print public key (hex), document the format the verifier expects.
  // TODO: hash a fixed test message (SHA-256), sign it, print message and signature (hex).
}

void loop() {
}
