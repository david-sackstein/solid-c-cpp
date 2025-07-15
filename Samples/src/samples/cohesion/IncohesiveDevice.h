#pragma once

#include <string>

class IncohesiveDevice {
private:
    std::string ipAddress;
    int port;

    float batteryLevel;
    bool isCharging;

    int brightness;
    int contrast;

public:
    IncohesiveDevice();

    void connect() const;
    void disconnect() const;

    void showBatteryStatus() const;
    void toggleCharging();

    void adjustBrightness(int delta);
    void adjustContrast(int delta);
};