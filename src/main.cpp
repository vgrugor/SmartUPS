#include <Arduino.h>
#include "AccessPoint.h"
#include <Arduino.h>
#include "PowerController.h"
#include "BatteryMonitor.h"
#include "PowerSupplyMonitor.h"
#include "TimeManager.h"
#include "Settings.h"
#include "Scheduler.h"
#include "WebInterface.h"
#include "BatteryMonitorTask.h"
#include "PowerSupplyMonitorTask.h"
// Другие необходимые включения

// Пины и конфигурации
#define ROUTER_CONTROL_PIN D6
#define BATTERY_ANALOG_PIN A0
#define POWER_SENSE_PIN D2

// Создание объектов
PowerController powerController(ROUTER_CONTROL_PIN);
BatteryMonitor batteryMonitor;
PowerSupplyMonitor powerSupplyMonitor;
TimeManager timeManager;
Settings settings;
Scheduler scheduler;
BatteryMonitorTask *batteryMonitorTask;
PowerSupplyMonitorTask *powerSupplyMonitorTask;
WebInterface webInterface(
    powerController,
    batteryMonitor,
    powerSupplyMonitor,
    timeManager,
    settings,
    scheduler
);
AccessPoint accessPoint("SmartUPS", "12091209");

void setup() {
    Serial.begin(115200);

    accessPoint.start(); // Запускаем точку доступа

    // Инициализация веб-интерфейса
    webInterface.begin();
    // Загрузка настроек
    settings.load();
    // Создание и планирование задач
    batteryMonitorTask = new BatteryMonitorTask(batteryMonitor, BATTERY_ANALOG_PIN, 4.2, 3.0);
    powerSupplyMonitorTask = new PowerSupplyMonitorTask(powerSupplyMonitor, POWER_SENSE_PIN);
    scheduler.scheduleTask(batteryMonitorTask);
    scheduler.scheduleTask(powerSupplyMonitorTask);
    // Установка начального времени
    timeManager.setHour(12); // Например, 12 часов дня
}

void loop() {
    //accessPoint.printConnectedDevices(); // Периодически выводим количество подключённых устройств
    //delay(10000);  // Проверяем каждые 10 секунд

    scheduler.update();
    webInterface.handleClient();

    // Симуляция времени для тестирования
    static unsigned long lastTimeUpdate = millis();
    if (millis() - lastTimeUpdate >= 60000UL) { // Каждую минуту
        uint8_t currentHour = timeManager.getHour();
        timeManager.setHour((currentHour + 1) % 24);
        lastTimeUpdate = millis();
    }
    // Другие действия, если необходимо

}
