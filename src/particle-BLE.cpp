/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/Dev/particle-BLE/src/particle-BLE.ino"
/*
 * Project particle-BLE
 * Description: Particle BLE testing
 * Author: Todd Rylaarsdam
 * Date: 8/8/2020
 */
void setup();
void loop();
#line 7 "d:/Dev/particle-BLE/src/particle-BLE.ino"
BleCharacteristic heartRateMeasurementCharacteristic;

const size_t SCAN_RESULT_MAX = 30;

BleScanResult scanResults[SCAN_RESULT_MAX];
BlePeerDevice peer;

uint16_t lastRate = 0;
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  BLE.on();

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}