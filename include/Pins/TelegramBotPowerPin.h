#pragma once

#include <DigitalOutputPin.h>

class TelegramBotPowerPin : public DigitalOutputPin {
    public:
        TelegramBotPowerPin(uint8_t pin);
};
