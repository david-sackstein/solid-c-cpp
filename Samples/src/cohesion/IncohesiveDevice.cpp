#include "IncohesiveDevice.h"

#include <iostream>

IncohesiveDevice::IncohesiveDevice()
    : ipAddress("192.168.1.1"), port(8080),
      batteryLevel(100.0f), isCharging(false),
      brightness(50), contrast(50) {}

void IncohesiveDevice::connect() const {
    std::cout << "Connecting to " << ipAddress << ":" << port << std::endl;
}

void IncohesiveDevice::disconnect() const {
    std::cout << "Disconnecting from " << ipAddress << ":" << port << std::endl;
}

void IncohesiveDevice::showBatteryStatus() const {
    std::cout << "Battery: " << batteryLevel << "%, "
              << (isCharging ? "Charging" : "Not Charging") << std::endl;
}

void IncohesiveDevice::toggleCharging() {
    isCharging = !isCharging;
    std::cout << "Charging status: " << (isCharging ? "Charging" : "Not Charging") << std::endl;
}

void IncohesiveDevice::adjustBrightness(int delta) {
    brightness += delta;
    std::cout << "Brightness adjusted to " << brightness << std::endl;
}

void IncohesiveDevice::adjustContrast(int delta) {
    contrast += delta;
    std::cout << "Contrast adjusted to " << contrast << std::endl;
}
