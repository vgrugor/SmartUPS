#include "PowerSupplyMonitor.h"

PowerSupplyMonitor::PowerSupplyMonitor() : _mainsPower(true) {}
    void PowerSupplyMonitor::setMainsPower(bool isMainsPower) {
    _mainsPower = isMainsPower;
}

bool PowerSupplyMonitor::isMainsPower() {
    return _mainsPower;
}

bool PowerSupplyMonitor::isBatteryPower() {
    return !_mainsPower;
}
