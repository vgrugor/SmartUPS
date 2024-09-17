#include "TaskScheduler/Tasks/BatteryMonitorTask.h"
#include <Arduino.h>

BatteryMonitorTask::BatteryMonitorTask(
    BatteryMonitor &batteryMonitor, 
    uint8_t analogPin, 
    float maxVoltage, 
    float minVoltage
) : _batteryMonitor(batteryMonitor), _analogPin(analogPin), _maxVoltage(maxVoltage), _minVoltage(minVoltage), _lastRunTime(0) {
    // Конфигурация пина при необходимости
}

void BatteryMonitorTask::execute() {
    // Измерение напряжения
    int rawValue = analogRead(_analogPin);
    float voltage = (rawValue / 1023.0) * 3.3 * (1/* коэффициент делителя напряжения */);

    // Расчёт уровня заряда
    float chargeLevel = ((voltage - _minVoltage) / (_maxVoltage - _minVoltage)) * 100.0;
    if (chargeLevel < 0) chargeLevel = 0;
    if (chargeLevel > 100) chargeLevel = 100;

    // Обновление данных
    _batteryMonitor.setVoltage(voltage);
    _batteryMonitor.setChargeLevel(chargeLevel);
    _lastRunTime = millis();
}

bool BatteryMonitorTask::isDue() {
    return (millis() - _lastRunTime) >= 300000UL; // Каждые 5 минут (300000 мс)
}
