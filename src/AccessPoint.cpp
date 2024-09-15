#include "AccessPoint.h"
#include <ESP8266WiFi.h>

// Конструктор класса AccessPoint
AccessPoint::AccessPoint(
    const char* ssid,
    const char* password, 
    IPAddress local_ip, 
    IPAddress gateway, 
    IPAddress subnet
) : ssid(ssid), password(password), local_ip(local_ip), gateway(gateway), subnet(subnet) {}

// Функция запуска точки доступа
void AccessPoint::start() {
    WiFi.softAPConfig(local_ip, gateway, subnet); // Устанавливаем статический IP, если задан

    WiFi.softAP(ssid, password); // Запускаем точку доступа
    
    Serial.println("Access Point started.");
    Serial.print("SSID: ");
    Serial.println(ssid);

    Serial.print("Local IP: ");
    Serial.println(WiFi.softAPIP());
}

// Получение количества подключённых устройств
int AccessPoint::getConnectedDevices() {
    return WiFi.softAPgetStationNum();
}

// Вывод информации о подключённых устройствах
void AccessPoint::printConnectedDevices() {
    int numDevices = getConnectedDevices();
    Serial.print("Connected devices: ");
    Serial.println(numDevices);

    // Список всех подключённых станций можно вывести через цикл
    for (int i = 0; i < numDevices; i++) {
        Serial.print("Device ");
        Serial.print(i + 1);
        Serial.println(" connected.");
    }
}
