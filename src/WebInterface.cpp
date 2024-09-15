#include "WebInterface.h"

WebInterface::WebInterface(
    PowerController &powerController,
    BatteryMonitor &batteryMonitor,
    PowerSupplyMonitor &powerSupplyMonitor,
    TimeManager &timeManager,
    Settings &settings,
    Scheduler &scheduler
) : _server(80),
    _powerController(powerController),
    _batteryMonitor(batteryMonitor),
    _powerSupplyMonitor(powerSupplyMonitor),
    _timeManager(timeManager),
    _settings(settings),
    _scheduler(scheduler)
{}

void WebInterface::begin() {
    // Настройка обработчиков
    _server.on("/", std::bind(&WebInterface::handleRoot, this));
    _server.on("/setTime", std::bind(&WebInterface::handleSetTime, this));
    _server.on("/setSettings", std::bind(&WebInterface::handleSetSettings, this));
    _server.on("/togglePower", std::bind(&WebInterface::handleTogglePower, this));
    _server.begin();
}

void WebInterface::handleClient() {
    _server.handleClient();
}

void WebInterface::handleRoot() {
    String html = "<html><head><title>Router Control</title></head><body>";
    html += "<h1>Router Control Panel</h1>";

    // Отображение режима питания
    if (_powerSupplyMonitor.isMainsPower()) {
        html += "<p>Power Source: <strong>Mains</strong> ⚡</p>";
    } else {
        html += "<p>Power Source: <strong>Battery</strong> 🔋</p>";
    }

    // Уровень заряда батареи
    html += "<p>Battery Level: " + String(_batteryMonitor.getChargeLevel()) + "%</p>";

    // Текущее время
    html += "<p>Current Hour: " + String(_timeManager.getHour()) + "</p>";

    // Переключатель питания роутера
    html += "<p>Router is " + String(_powerController.isOn() ? "ON" : "OFF") + "</p>";
    html += "<form action='/togglePower' method='post'><button type='submit'>Toggle Power</button></form>";

    // Форма для установки времени
    html += "<form action='/setTime' method='post'>Set Hour: <input type='number' name='hour' min='0' max='23'/><button type='submit'>Set Time</button></form>";

    // Форма для настройки интервала автоотключения
    html += "<form action='/setSettings' method='post'>Auto-Off Start Hour: <input type='number' name='startHour' min='0' max='23'/>";
    html += " End Hour: <input type='number' name='endHour' min='0' max='23'/><button type='submit'>Set Auto-Off Interval</button></form>";
    html += "</body></html>";

    _server.send(200, "text/html", html);
}

void WebInterface::handleSetTime() {
    if (_server.hasArg("hour")) {
        uint8_t hour = _server.arg("hour").toInt();
        _timeManager.setHour(hour);
    }

    _server.sendHeader("Location", "/");
    _server.send(303); // Перенаправление
}

void WebInterface::handleSetSettings() {
    if (_server.hasArg("startHour") && _server.hasArg("endHour")) {
        uint8_t startHour = _server.arg("startHour").toInt();
        uint8_t endHour = _server.arg("endHour").toInt();
        _settings.setAutoOffInterval(startHour, endHour);
        _settings.save();
    }

    _server.sendHeader("Location", "/");
    _server.send(303); // Перенаправление
}

void WebInterface::handleTogglePower() {
    bool powerState = _powerController.isOn();
    // Переключаем состояние питания

    if (powerState) {
        _powerController.turnOff();
        // Отменяем запланированную задачу, если была
        //_scheduler.cancelTask(/* ссылка на задачу отключения */);
    } else {
        _powerController.turnOn();

        // Проверяем, нужно ли добавить задачу на отключение через час
        uint8_t startHour, endHour;
        _settings.getAutoOffInterval(startHour, endHour);
        uint8_t currentHour = _timeManager.getHour();

        if (
            _powerSupplyMonitor.isBatteryPower() &&
            ((startHour <= endHour && currentHour >= startHour && currentHour < endHour) ||
            (startHour > endHour && (currentHour >= startHour || currentHour < endHour)))
        ) {
            // Создаем задачу на отключение через час
            uint8_t offHour = (currentHour + 1) % 24; // Следующий час
            RouterControlTask *routerControlTask = new RouterControlTask(offHour, _powerController, _timeManager);
            _scheduler.scheduleTask(routerControlTask);
        }
    }

    _server.sendHeader("Location", "/");
    _server.send(303); // Перенаправление
}
