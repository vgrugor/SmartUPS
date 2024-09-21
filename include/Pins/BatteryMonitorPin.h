#pragma once

#include <AnalogInputPin.h>

class BatteryMonitorPin : public AnalogInputPin {
    public:
        BatteryMonitorPin(uint8_t pin);
};
