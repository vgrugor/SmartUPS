#pragma once

#include "Pin.h"

class DigitalOutputPin : public Pin {
    public:
        DigitalOutputPin(uint8_t pin);
        void init() override;
        void write(bool state);
        void toggle();
        void turnOn();
        void turnOff();
        bool isOn();
};
