#pragma once

#include "Pin.h"

class AnalogInputPin : public Pin {
    public:
        AnalogInputPin(uint8_t pin);
        void init() override;
        uint16_t read() const;
};
