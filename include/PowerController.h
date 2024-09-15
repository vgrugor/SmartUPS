#ifndef POWERCONTROLLER_H
    #define POWERCONTROLLER_H

    #include <Arduino.h>

    class PowerController {
        public:
            PowerController(uint8_t controlPin);
            void turnOn();
            void turnOff();
            bool isOn();
        private:
            uint8_t _controlPin;
            bool _state;
    };
#endif // POWERCONTROLLER_H
