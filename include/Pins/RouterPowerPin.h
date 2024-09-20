#pragma once

#include <DigitalOutputPin.h>

class RouterPowerPin : public DigitalOutputPin {
    public:
        RouterPowerPin(uint8_t pin);
};
