#include "TimeManager.h"

TimeManager::TimeManager() : _currentHour(0) {}

void TimeManager::setHour(uint8_t hour) {
    if (hour < 24) {
        _currentHour = hour;
    }
}

uint8_t TimeManager::getHour() {
    return _currentHour;
}
