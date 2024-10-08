#include <Arduino.h>
#include <AccessPoint.h>
#include <Arduino.h>
#include "PowerControllers/Controllers/MediaConverterPowerController.h"
#include "PowerControllers/Controllers/RouterPowerController.h"
#include "PowerControllers/Controllers/TelegramBotPowerController.h"
#include "Monitors/BatteryMonitor.h"
#include "Monitors/PowerSupplyMonitor.h"
#include "TimeManager.h"
#include "Settings.h"
#include "TaskScheduler/Scheduler.h"
#include "WebInterface.h"
#include "TaskScheduler/Tasks/BatteryMonitorTask.h"
#include "TaskScheduler/Tasks/PowerSupplyMonitorTask.h"
#include "App.h"
// Другие необходимые включения

// Пины и конфигурации
#define ROUTER_POWER_CONTROL_PIN D6
#define MEDIA_CONVERTER_POwER_CONTROL_PIN D6
#define TELEGRAM_BOT_POWER_CONTROL_PIN D6
#define BATTERY_ANALOG_PIN A0
#define POWER_SENSE_PIN D2

// Создание объектов
MediaConverterPowerController mediaConverterPowerController(MEDIA_CONVERTER_POwER_CONTROL_PIN);
RouterPowerController routerPowerController(ROUTER_POWER_CONTROL_PIN);
TelegramBotPowerController telegramBotPowerController(TELEGRAM_BOT_POWER_CONTROL_PIN);
BatteryMonitor batteryMonitor;
PowerSupplyMonitor powerSupplyMonitor;
TimeManager timeManager;
Settings settings;
Scheduler scheduler;
BatteryMonitorTask *batteryMonitorTask;
PowerSupplyMonitorTask *powerSupplyMonitorTask;
App app(
    POWER_SENSE_PIN,
    BATTERY_ANALOG_PIN,
    MEDIA_CONVERTER_POwER_CONTROL_PIN,
    ROUTER_POWER_CONTROL_PIN,
    TELEGRAM_BOT_POWER_CONTROL_PIN
);
WebInterface webInterface(
    mediaConverterPowerController,
    routerPowerController,
    telegramBotPowerController,
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

    
    webInterface.begin(); // Инициализация веб-интерфейса
    settings.load(); // Загрузка настроек

    // Создание и планирование задач
    batteryMonitorTask = new BatteryMonitorTask(batteryMonitor, BATTERY_ANALOG_PIN, 4.2, 3.0);
    powerSupplyMonitorTask = new PowerSupplyMonitorTask(powerSupplyMonitor, POWER_SENSE_PIN);
    scheduler.scheduleTask(batteryMonitorTask);
    scheduler.scheduleTask(powerSupplyMonitorTask);
    
    timeManager.setHour(12); // Установка начального времени
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
