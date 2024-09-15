#ifndef SETTINGS_H
    #define SETTINGS_H

    #include <Arduino.h>

    class Settings {
        public:
            Settings();
            void load();
            void save();
            void setAutoOffInterval(uint8_t startHour, uint8_t endHour);
            void getAutoOffInterval(uint8_t &startHour, uint8_t &endHour);
        private:
            uint8_t _startHour;
            uint8_t _endHour;
            // Добавьте методы для работы с энергонезависимой памятью (например, EEPROM)
    };

#endif // SETTINGS_H
