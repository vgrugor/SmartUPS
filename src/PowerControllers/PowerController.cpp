#include "PowerControllers/PowerController.h"

PowerController::PowerController(uint8_t controlPin) : _controlPin(controlPin), _state(false) {
    pinMode(_controlPin, OUTPUT);
    digitalWrite(_controlPin, LOW); // Предполагаем, что LOW = выключено
}

PowerController::~PowerController() {}

void PowerController::turnOn() {
    digitalWrite(_controlPin, HIGH);
    _state = true;
}

void PowerController::turnOff() {
    digitalWrite(_controlPin, LOW);
    _state = false;
}

bool PowerController::isOn() const {
    return _state;
}