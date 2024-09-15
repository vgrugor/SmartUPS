#ifndef TIMEMANAGER_H
    #define TIMEMANAGER_H

    #include <Arduino.h>

    class TimeManager {
        public:
            TimeManager();
            void setHour(uint8_t hour);
            uint8_t getHour();
        private:
            uint8_t _currentHour;
    };
#endif // TIMEMANAGER_H
