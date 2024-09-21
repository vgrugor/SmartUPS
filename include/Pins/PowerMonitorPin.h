#pragma once

#include <DigitalInputPin.h>

class PowerMonitorPin : public DigitalInputPin {
    public:
        PowerMonitorPin(uint8_t pin);
};
