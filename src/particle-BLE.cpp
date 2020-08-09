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
const uint32_t myColor = 0xff0000;
void setAdvertisingData();

uint16_t lastRate = 0;
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  BLE.on();
  RGB.control(true);
  setAdvertisingData();
}

void setAdvertisingData() {
    uint8_t buf[BLE_MAX_ADV_DATA_LEN];

    size_t offset = 0;

    // Manufacturer-specific data
    // 16-bit: Company ID (0xffff)
    // Byte: Internal packet identifier (0x55)
    // 32-bit: Color code

    // Company ID (0xffff internal use/testing)
    buf[offset++] = 0xff;
    buf[offset++] = 0xff;

    // Internal packet type. This is arbitrary, but provides an extra
    // check to make sure the data is my data, since we use the 0xffff company
    // code.
    buf[offset++] = 0x55;

    // Our specific data, color code
    memcpy(&buf[offset], &myColor, 4);
    offset += 4;

    BleAdvertisingData advData;
    advData.appendCustomData(buf, offset);

    // Advertise every 100 milliseconds. Unit is 0.625 millisecond intervals.
    BLE.setAdvertisingInterval(100);

    // Continuously advertise
    BLE.advertise(&advData);
}
// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  if (BLE.connected()) {
        // We're currently connected to a sensor
    RGB.color(255, 255, 255);
  }
  else {
    RGB.color(0, 0, 255);
  }
}