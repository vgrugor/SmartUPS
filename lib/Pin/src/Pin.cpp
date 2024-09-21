#include "Pin.h"

Pin::Pin(uint8_t pin) : _pin(pin) {}

uint8_t Pin::getPin() const {
    return _pin;
}
