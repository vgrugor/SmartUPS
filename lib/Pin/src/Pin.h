#pragma once

#include <Arduino.h>

class Pin {
    protected:
        uint8_t _pin;
    public:
        Pin(uint8_t pin);
        virtual void init() = 0;
        uint8_t getPin() const;
};
