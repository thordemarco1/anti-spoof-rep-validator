/*
 * 01_blink.ino  -  Phase 1: Bring-up
 *
 * Purpose:
 *   Prove the toolchain works: the board is detected, a sketch uploads,
 *   the on-board LED blinks, and text appears in the Serial Monitor.
 *
 * Board:  ESP32 dev board (Arduino-ESP32 core)
 * Serial: 115200 baud
 *
 * Note on the LED pin:
 *   Many ESP32 dev boards (e.g. ESP32-DevKit V1 clones) have a blue LED on
 *   GPIO2. Some boards use a different pin or have no user LED at all.
 *   If nothing blinks, check your board's pinout and change LED_PIN.
 */

#include <Arduino.h>

const int LED_PIN = 2;                 // Common on-board LED pin for ESP32 dev boards
const unsigned long BLINK_MS = 500;    // Time the LED stays on/off

unsigned long blinkCount = 0;

void setup() {
  Serial.begin(115200);
  delay(500);                          // Give the USB serial a moment to come up

  pinMode(LED_PIN, OUTPUT);

  Serial.println();
  Serial.println("Anti-Spoof Rep Validator - 01_blink");
  Serial.print("Blinking LED on GPIO");
  Serial.println(LED_PIN);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_MS);
  digitalWrite(LED_PIN, LOW);
  delay(BLINK_MS);

  blinkCount++;
  Serial.print("Blink #");
  Serial.println(blinkCount);
}
