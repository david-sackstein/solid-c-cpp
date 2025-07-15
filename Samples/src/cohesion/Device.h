#pragma once

#include <string>
#include <iostream>

class NetworkManager {
    std::string ipAddress;
    int port;

public:
    NetworkManager();
    void connect() const;
    void disconnect() const;
};

class BatteryMonitor {
    float batteryLevel;
    bool isCharging;

public:
    BatteryMonitor();
    void showBatteryStatus() const;
    void toggleCharging();
};

class DisplayConfig {
    int brightness;
    int contrast;

public:
    DisplayConfig();
    void adjustBrightness(int delta);
    void adjustContrast(int delta);
};

class Device {
    NetworkManager network;
    BatteryMonitor battery;
    DisplayConfig display;

public:
    NetworkManager& getNetworkManager();
    BatteryMonitor& getBatteryMonitor();
    DisplayConfig& getDisplayConfig();
};
