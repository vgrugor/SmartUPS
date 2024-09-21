#include "App.h"

App::App(
    uint8_t powerMonitorPin,
    uint8_t batteryMonitorPin,
    uint8_t mediaConverterPowerPin,
    uint8_t routerPowerPin,
    uint8_t telegramBotPowerPin
) : 
    _powerMonitorPin(powerMonitorPin),
    _batteryMonitorPin(batteryMonitorPin),
    _mediaConverterPowerPin(mediaConverterPowerPin),
    _routerPowerPin(routerPowerPin),
    _telegramBotPowerPin(telegramBotPowerPin)
{
}

bool App::isBatteryPower() {
    return _powerMonitorPin.isLow();
}

bool App::isMainPower() {
    return _powerMonitorPin.isHigh();
}

float App::getBatteryVoltage() {
    return _batteryMonitorPin.read() * (3.3 / 1023.0) * 2;
}

float App::getBatteryProcent() {
    float voltage = getBatteryVoltage();

    return (voltage - 2.5) / (4.2 - 2.5) * 100;
}

void App::turnOnInternet() {
    _mediaConverterPowerPin.turnOn();
    _routerPowerPin.turnOn();
}

void App::turnOffInternet() {
    _mediaConverterPowerPin.turnOn();
    _routerPowerPin.turnOn();
}

void App::turnOnTelegramBot() {
    _telegramBotPowerPin.turnOn();

void App::turnOffTelegramBot() {
    _telegramBotPowerPin.turnOff();
}
