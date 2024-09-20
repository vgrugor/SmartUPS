#include "DigitalOutputPin.h"

DigitalOutputPin::DigitalOutputPin(uint8_t pin) : Pin(pin) {
    init();
}

void DigitalOutputPin::init() {
    pinMode(_pin, OUTPUT);
}

void DigitalOutputPin::write(bool state) {
    digitalWrite(_pin, state);
}

void DigitalOutputPin::toggle() {
    digitalWrite(_pin, !digitalRead(_pin));
}
