#include "WebInterface.h"

WebInterface::WebInterface(
    MediaConverterPowerController &mediaConverterPowerController,
    RouterPowerController &routerPowerController,
    TelegramBotPowerController &telegramBotPowerController,
    BatteryMonitor &batteryMonitor,
    PowerSupplyMonitor &powerSupplyMonitor,
    TimeManager &timeManager,
    Settings &settings,
    Scheduler &scheduler
) : _server(80),
    _mediaConverterPowerController(mediaConverterPowerController),
    _routerPowerController(routerPowerController),
    _telegramBotPowerController(telegramBotPowerController),
    _batteryMonitor(batteryMonitor),
    _powerSupplyMonitor(powerSupplyMonitor),
    _timeManager(timeManager),
    _settings(settings),
    _scheduler(scheduler)
{}

void WebInterface::begin() {
    // Инициализация LittleFS
    if (!LittleFS.begin()) {
        Serial.println("An error has occurred while mounting LittleFS");
        return;
    }

    Serial.println("LittleFS mounted successfully");

    // Настройка обработчиков
    _server.on("/", HTTP_GET, std::bind(&WebInterface::handleRoot, this));
    _server.on("/api/status", HTTP_GET, std::bind(&WebInterface::handleGetStatus, this));
    _server.on("/api/toggleInternetPower", HTTP_POST, std::bind(&WebInterface::handleToggleInternetPower, this));
    _server.on("/api/setTime", HTTP_POST, std::bind(&WebInterface::handleSetTime, this));
    _server.on("/api/setSettings", HTTP_POST, std::bind(&WebInterface::handleSetSettings, this));
    _server.onNotFound(std::bind(&WebInterface::handleNotFound, this));
    _server.begin();
}

void WebInterface::handleClient() {
    _server.handleClient();
}

void WebInterface::handleRoot() {
    File file = LittleFS.open("/index.html", "r");

    if (!file) {
        _server.send(500, "text/plain", "File not found");

        return;
    }

    _server.streamFile(file, "text/html");
    file.close();
}

void WebInterface::handleNotFound() {
    if (LittleFS.exists(_server.uri())) {
        File file = LittleFS.open(_server.uri(), "r");

        if (file) {
            String contentType = "text/plain";
            if (_server.uri().endsWith(".html")) contentType = "text/html";
            else if (_server.uri().endsWith(".css")) contentType = "text/css";
            else if (_server.uri().endsWith(".js")) contentType = "application/javascript";
            else if (_server.uri().endsWith(".png")) contentType = "image/png";
            else if (_server.uri().endsWith(".jpg") || _server.uri().endsWith(".jpeg")) contentType = "image/jpeg";

            _server.streamFile(file, contentType);
            file.close();

            return;
        }
    }
    _server.send(404, "text/plain", "Not Found");
}

void WebInterface::handleGetStatus() {
    String json = "{";
    json += "\"powerSource\":\"" + String(_powerSupplyMonitor.isMainsPower() ? "mains" : "battery") + "\",";
    json += "\"batteryLevel\":" + String(_batteryMonitor.getChargeLevel()) + ",";
    json += "\"mediaConverterState\":\"" + String(_mediaConverterPowerController.isOn() ? "on" : "off") + "\",";
    json += "\"routerState\":\"" + String(_routerPowerController.isOn() ? "on" : "off") + "\",";
    json += "\"telegramBotState\":\"" + String(_telegramBotPowerController.isOn() ? "on" : "off") + "\",";
    json += "\"currentHour\":" + String(_timeManager.getHour());
    json += "}";

    _server.send(200, "application/json", json);
}

void WebInterface::handleToggleInternetPower() {
    bool powerState = _mediaConverterPowerController.isOn();

    // Переключаем состояние питания
    if (powerState) {
        _mediaConverterPowerController.turnOff();
        _routerPowerController.turnOff();
        // Отменяем запланированную задачу, если была
        //_scheduler.cancelTask(/* ссылка на задачу отключения */);
    } else {
        _mediaConverterPowerController.turnOn();
        _routerPowerController.turnOn();
    
        // Проверяем, нужно ли добавить задачу на отключение через час
        uint8_t startHour, endHour;
        _settings.getAutoOffInterval(startHour, endHour);
        uint8_t currentHour = _timeManager.getHour();

        if (
            _powerSupplyMonitor.isBatteryPower() 
            && ((startHour <= endHour && currentHour >= startHour && currentHour < endHour)
            || (startHour > endHour && (currentHour >= startHour || currentHour < endHour)))
        ) {
            // Создаем задачу на отключение через час
            uint8_t offHour = (currentHour + 1) % 24; // Следующий час
            RouterControlTask *routerControlTask = new RouterControlTask(offHour, _mediaConverterPowerController, _routerPowerController, _timeManager);
            _scheduler.scheduleTask(routerControlTask);
        }
    }

    // Возвращаем текущий статус
    handleGetStatus();
}

void WebInterface::handleSetTime() {
    if (_server.hasArg("hour")) {
        uint8_t hour = _server.arg("hour").toInt();
        _timeManager.setHour(hour);

        // Возвращаем текущий статус
        handleGetStatus();
    } else {
        _server.send(400, "text/plain", "Invalid parameters");
    }
}

void WebInterface::handleSetSettings() {
    if (_server.hasArg("startHour") && _server.hasArg("endHour")) {
        uint8_t startHour = _server.arg("startHour").toInt();
        uint8_t endHour = _server.arg("endHour").toInt();
        _settings.setAutoOffInterval(startHour, endHour);
        _settings.save();

        // Возвращаем текущий статус
        handleGetStatus();
    } else {
        _server.send(400, "text/plain", "Invalid parameters");
    }
}
