#ifndef WEBINTERFACE_H
    #define WEBINTERFACE_H

    #include <ESP8266WebServer.h>
    #include "PowerController.h"
    #include "BatteryMonitor.h"
    #include "PowerSupplyMonitor.h"
    #include "TimeManager.h"
    #include "Settings.h"
    #include "Scheduler.h"
    #include "RouterControlTask.h"

    class WebInterface {
        public:
            WebInterface(
                PowerController &powerController,
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
            void handleSetTime();
            void handleSetSettings();
            void handleTogglePower();
            ESP8266WebServer _server;
            PowerController &_powerController;
            BatteryMonitor &_batteryMonitor;
            PowerSupplyMonitor &_powerSupplyMonitor;
            TimeManager &_timeManager;
            Settings &_settings;
            Scheduler &_scheduler;
            // Другие приватные члены
    };

#endif // WEBINTERFACE_H
