#include "DigitalInputPin.h"

DigitalInputPin::DigitalInputPin(uint8_t pin, bool pullup)
    : Pin(pin), _pullup(pullup) {
    init();
}

void DigitalInputPin::init() {
    pinMode(_pin, _pullup ? INPUT_PULLUP : INPUT);
}

bool DigitalInputPin::read() const {
    return digitalRead(_pin);
}

bool DigitalInputPin::isHigh() const {
    return digitalRead(_pin) == HIGH;
}

bool DigitalInputPin::isLow() const {
    return digitalRead(_pin) == LOW;
}
