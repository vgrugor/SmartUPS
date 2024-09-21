#pragma once

#include "Pin.h"

class DigitalInputPin : public Pin {
    private:
        bool _pullup;
    public:
        DigitalInputPin(uint8_t pin, bool pullup = false);
        void init() override;
        bool read() const;
        bool isHigh() const;
        bool isLow() const;
};
