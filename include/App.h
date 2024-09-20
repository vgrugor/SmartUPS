#ifndef APP_H
    #define APP_H

    #include <Arduino.h>
    #include "Pins/BatteryMonitorPin.h"
    #include "Pins/MediaConverterPowerPin.h"
    #include "Pins/PowerMonitorPin.h"
    #include "Pins/RouterPowerPin.h"
    #include "Pins/TelegramBotPowerPin.h"

    class App {
        public:
            App(
                uint8_t powerMonitorPin,
                uint8_t batteryMonitorPin,
                uint8_t mediaConverterPowerPin,
                uint8_t routerPowerPin,
                uint8_t telegramBotPowerPin
            );

            bool isBatteryPower();
            bool isMainPower();
            float getBatteryVoltage();
            float getBatteryProcent();
            void turnOnInternet();
            void turnOffInternet();
            void turnOnTelegramBot();
            void turnOffTelegramBot();

        private:
            PowerMonitorPin _powerMonitorPin;
            BatteryMonitorPin _batteryMonitorPin;
            MediaConverterPowerPin _mediaConverterPowerPin;
            RouterPowerPin _routerPowerPin;
            TelegramBotPowerPin _telegramBotPowerPin;
    };

#endif
