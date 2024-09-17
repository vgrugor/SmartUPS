#ifndef POWERSUPPLYMONITORTASK_H
    #define POWERSUPPLYMONITORTASK_H

    #include <Arduino.h>
    #include "Task.h"
    #include "PowerSupplyMonitor.h"

    class PowerSupplyMonitorTask : public Task {
        public:
            PowerSupplyMonitorTask(PowerSupplyMonitor &powerSupplyMonitor, uint8_t powerSensePin);
            void execute() override;
            bool isDue() override;
        private:
            PowerSupplyMonitor &_powerSupplyMonitor;
            uint8_t _powerSensePin;
            unsigned long _lastRunTime;
    };

#endif // POWERSUPPLYMONITORTASK_H
