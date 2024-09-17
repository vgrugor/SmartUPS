#ifndef POWERCONTROLLER_H
    #define POWERCONTROLLER_H

    #include <Arduino.h>

    class PowerController {
        public:
            PowerController(uint8_t controlPin);
            virtual void turnOn();
            virtual void turnOff();
            virtual bool isOn() const;
        
        protected:
            uint8_t _controlPin;
            bool _state;
    };

#endif // POWERCONTROLLER_H