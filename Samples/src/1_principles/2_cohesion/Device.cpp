#include "Device.h"

// NetworkManager implementation
NetworkManager::NetworkManager()
    : ipAddress("192.168.1.1"), port(8080) {}

void NetworkManager::connect() const {
    std::cout << "Connecting to " << ipAddress << ":" << port << std::endl;
}

void NetworkManager::disconnect() const {
    std::cout << "Disconnecting from " << ipAddress << ":" << port << std::endl;
}

// BatteryMonitor implementation
BatteryMonitor::BatteryMonitor()
    : batteryLevel(100.0f), isCharging(false) {}

void BatteryMonitor::showBatteryStatus() const {
    std::cout << "Battery: " << batteryLevel << "%, "
              << (isCharging ? "Charging" : "Not Charging") << std::endl;
}

void BatteryMonitor::toggleCharging() {
    isCharging = !isCharging;
    std::cout << "Charging status: " << (isCharging ? "Charging" : "Not Charging") << std::endl;
}

// DisplayConfig implementation
DisplayConfig::DisplayConfig()
    : brightness(50), contrast(50) {}

void DisplayConfig::adjustBrightness(int delta) {
    brightness += delta;
    std::cout << "Brightness adjusted to " << brightness << std::endl;
}

void DisplayConfig::adjustContrast(int delta) {
    contrast += delta;
    std::cout << "Contrast adjusted to " << contrast << std::endl;
}

NetworkManager& Device::getNetworkManager() {
    return network;
}

BatteryMonitor& Device::getBatteryMonitor() {
    return battery;
}

DisplayConfig& Device::getDisplayConfig() {
    return display;
}
