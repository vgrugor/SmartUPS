#include "PWMOutputPin.h"

PWMOutputPin::PWMOutputPin(uint8_t pin) : Pin(pin) {
    init();
}

void PWMOutputPin::init() {
    pinMode(_pin, OUTPUT);
    analogWriteFreq(1000); // Set PWM frequency to 1 kHz
}

void PWMOutputPin::write(uint16_t value) {
    analogWrite(_pin, value);
}
