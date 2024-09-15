#include <Arduino.h>
#include "AccessPoint.h"

AccessPoint accessPoint("SmartUPS", "12091209");

void setup() {
    Serial.begin(115200);

    accessPoint.start(); // Запускаем точку доступа
}

void loop() {
    accessPoint.printConnectedDevices(); // Периодически выводим количество подключённых устройств
    delay(10000);  // Проверяем каждые 10 секунд
}
