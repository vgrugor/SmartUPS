#include "DigitalOutputPin.h"

DigitalOutputPin::DigitalOutputPin(uint8_t pin) : Pin(pin) {
    init();
}

void DigitalOutputPin::init() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void DigitalOutputPin::write(bool state) {
    digitalWrite(_pin, state);
}

void DigitalOutputPin::toggle() {
    digitalWrite(_pin, !digitalRead(_pin));
}

void DigitalOutputPin::turnOn() {
    digitalWrite(_pin, HIGH);
}

void DigitalOutputPin::turnOff() {
    digitalWrite(_pin, LOW);
}

bool DigitalOutputPin::isOn() {
    return digitalRead(_pin);
}
