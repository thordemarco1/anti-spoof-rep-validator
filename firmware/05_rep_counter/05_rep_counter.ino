/*
 * 05_rep_counter.ino  -  Phase 5: Rep detection state machine
 *
 * Purpose (TODO - not implemented yet):
 *   Estimate the dumbbell pitch angle from the MPU-6050 and count bicep
 *   curls as a swing from about 0 deg up to about 120 deg and back down.
 *
 * Ideas to explore:
 *   - Pitch from accel (atan2) is noisy but does not drift.
 *   - Pitch from integrating gyro is smooth but drifts.
 *   - A complementary filter combines both. TODO: choose and justify.
 *
 * Libraries: Adafruit MPU6050, Adafruit Unified Sensor
 */

#include <Arduino.h>
#include <Wire.h>
// TODO: #include <Adafruit_MPU6050.h>
// TODO: #include <Adafruit_Sensor.h>

// TODO: tune these from real data, do not guess.
// const float BOTTOM_DEG = ...;   // "arm extended" threshold
// const float TOP_DEG    = ...;   // "arm curled" threshold
// const unsigned long MIN_REP_MS = ...;  // reject too-fast "reps" (shaking)
// const unsigned long MAX_REP_MS = ...;  // reject incomplete reps

enum RepState { WAIT_BOTTOM, GOING_UP, AT_TOP, GOING_DOWN };

RepState state = WAIT_BOTTOM;
unsigned long repCount = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  // TODO: init IMU + calibration (reuse code from 04_imu_stream).
}

void loop() {
  // TODO: update pitch estimate.
  // TODO: advance the state machine (WAIT_BOTTOM -> GOING_UP -> AT_TOP -> GOING_DOWN -> count).
  // TODO: add hysteresis so noise near a threshold does not double-count.
  // TODO: print each counted rep with timestamp and peak angle.
}
