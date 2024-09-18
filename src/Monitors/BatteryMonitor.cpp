#include "Monitors/BatteryMonitor.h"

BatteryMonitor::BatteryMonitor() : _voltage(0.0), _chargeLevel(0.0) {}

void BatteryMonitor::setChargeLevel(float chargeLevel) {
    _chargeLevel = chargeLevel;
}

float BatteryMonitor::getChargeLevel() {
    return _chargeLevel;
}

void BatteryMonitor::setVoltage(float voltage) {
    _voltage = voltage;
}

float BatteryMonitor::getVoltage() {
    return _voltage;
}
