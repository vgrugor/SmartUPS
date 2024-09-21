#include "AnalogInputPin.h"

AnalogInputPin::AnalogInputPin(uint8_t pin) : Pin(pin) {
    init();
}

void AnalogInputPin::init() {
    pinMode(_pin, INPUT);
}

uint16_t AnalogInputPin::read() const {
    return analogRead(_pin);
}
