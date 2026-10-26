/*
 * 04_imu_stream.ino  -  Phase 4: IMU reading + calibration
 *
 * Purpose (TODO - not implemented yet):
 *   Read the MPU-6050 (I2C 0x68) with the Adafruit MPU6050 library and
 *   stream accel (m/s^2) and gyro (rad/s) to Serial as CSV so it can be
 *   plotted (Arduino Serial Plotter or Python).
 *
 * Libraries: Adafruit MPU6050, Adafruit Unified Sensor
 * Wiring:    SDA = GPIO21, SCL = GPIO22, 3.3 V
 */

#include <Arduino.h>
#include <Wire.h>
// TODO: #include <Adafruit_MPU6050.h>
// TODO: #include <Adafruit_Sensor.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  // TODO: begin the MPU-6050 at address 0x68 and halt with a clear message if not found.
  // TODO: choose and document accel range, gyro range, and filter bandwidth.
  // TODO: calibration - keep the sensor still, average N gyro samples, store offsets.
}

void loop() {
  // TODO: read accel + gyro, subtract gyro offsets.
  // TODO: print one CSV line: t_ms,ax,ay,az,gx,gy,gz
  // TODO: pick a fixed sample rate and document it.
}
