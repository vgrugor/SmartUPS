#pragma once

#include "Pin.h"

class PWMOutputPin : public Pin {
    public:
        PWMOutputPin(uint8_t pin);
        void init() override;
        void write(uint16_t value);
};
