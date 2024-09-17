#include "TaskScheduler/Tasks/PowerSupplyMonitorTask.h"
#include <Arduino.h>

PowerSupplyMonitorTask::PowerSupplyMonitorTask(
    PowerSupplyMonitor &powerSupplyMonitor, 
    uint8_t powerSensePin
) : _powerSupplyMonitor(powerSupplyMonitor), _powerSensePin(powerSensePin), _lastRunTime(0) {
    pinMode(_powerSensePin, INPUT);
}

void PowerSupplyMonitorTask::execute() {
    // Проверка источника питания
    bool mainsPower = digitalRead(_powerSensePin) == HIGH; // Настройте уровень сигнала
    _powerSupplyMonitor.setMainsPower(mainsPower);
    _lastRunTime = millis();
}

bool PowerSupplyMonitorTask::isDue() {
    return (millis() - _lastRunTime) >= 10000UL; // Каждые 10 секунд (10000 мс)
}
