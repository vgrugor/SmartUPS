#pragma once

#include <DigitalOutputPin.h>

class MediaConverterPowerPin : public DigitalOutputPin {
    public:
        MediaConverterPowerPin(uint8_t pin);
};
