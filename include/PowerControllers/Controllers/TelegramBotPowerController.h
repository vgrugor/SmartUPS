#ifndef TELEGRAMBOTPOWERCONTROLLER_H
    #define TELEGRAMBOTPOWERCONTROLLER_H

    #include "PowerControllers/PowerController.h"

    class TelegramBotPowerController : public PowerController {
        public:
            TelegramBotPowerController(uint8_t controlPin);
            ~TelegramBotPowerController() override;
    };

#endif
