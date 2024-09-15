#include "Settings.h"

Settings::Settings() : _startHour(0), _endHour(0) {}

void Settings::load() {
    // Реализуйте загрузку настроек из энергонезависимой памяти
}

void Settings::save() {
    // Реализуйте сохранение настроек в энергонезависимую память
}

void Settings::setAutoOffInterval(uint8_t startHour, uint8_t endHour) {
    if (startHour < 24 && endHour < 24) {
        _startHour = startHour;
        _endHour = endHour;
    }
}

void Settings::getAutoOffInterval(uint8_t &startHour, uint8_t &endHour) {
    startHour = _startHour;
    endHour = _endHour;
}
