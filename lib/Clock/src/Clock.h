#ifndef CLOCK_H
    #define CLOCK_H

    #include <Arduino.h>

    class Clock {
        protected:
            int hours;
            int minutes;

        public:
            Clock();
            virtual void update() = 0;
            int getHours() const;
            int getMinutes() const;
    };

#endif
