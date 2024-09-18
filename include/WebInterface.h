#ifndef WEBINTERFACE_H
    #define WEBINTERFACE_H

    #include <ESP8266WebServer.h>
    #include <LittleFS.h>
    #include "PowerControllers/Controllers/MediaConverterPowerController.h"
    #include "PowerControllers/Controllers/RouterPowerController.h"
    #include "PowerControllers/Controllers/TelegramBotPowerController.h"
    #include "BatteryMonitor.h"
    #include "PowerSupplyMonitor.h"
    #include "TimeManager.h"
    #include "Settings.h"
    #include "TaskScheduler/Scheduler.h"
    #include "TaskScheduler/Tasks/RouterControlTask.h"

    class WebInterface {
        public:
            WebInterface(
                MediaConverterPowerController &mediaConverterPowerController,
                RouterPowerController &routerPowerController,
                TelegramBotPowerController &telegramBotPowerController,
                BatteryMonitor &batteryMonitor,
                PowerSupplyMonitor &powerSupplyMonitor,
                TimeManager &timeManager,
                Settings &settings,
                Scheduler &scheduler
            );
            void begin();
            void handleClient();
        private:
            void handleRoot();
            void handleNotFound();
            void handleToggleInternetPower();
            void handleSetTime();
            void handleSetSettings();
            void handleGetStatus();
            ESP8266WebServer _server;
            MediaConverterPowerController &_mediaConverterPowerController;
            RouterPowerController &_routerPowerController;
            TelegramBotPowerController &_telegramBotPowerController;
            BatteryMonitor &_batteryMonitor;
            PowerSupplyMonitor &_powerSupplyMonitor;
            TimeManager &_timeManager;
            Settings &_settings;
            Scheduler &_scheduler;
    };

#endif // WEBINTERFACE_H
