#ifndef OFFLINECLOCK_H
    #define OFFLINECLOCK_H

    #include "Clock.h"

    class OfflineClock : public Clock {
        private:
            unsigned long lastMillis;
            unsigned long calculateElapsedTime(unsigned long currentMillis) const;

        public:
            OfflineClock();
            void update() override;
    };

#endif
