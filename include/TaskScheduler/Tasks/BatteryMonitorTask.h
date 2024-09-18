#ifndef BATTERYMONITORTASK_H
    #define BATTERYMONITORTASK_H

    #include <Arduino.h>
    #include "TaskScheduler/Task.h"
    #include "BatteryMonitor.h"

    class BatteryMonitorTask : public Task {
        public:
            BatteryMonitorTask(BatteryMonitor &batteryMonitor, uint8_t analogPin, float maxVoltage, float minVoltage);
            void execute() override;
            bool isDue() override;
        private:
            BatteryMonitor &_batteryMonitor;
            uint8_t _analogPin;
            float _maxVoltage;
            float _minVoltage;
            unsigned long _lastRunTime;
    };

#endif // BATTERYMONITORTASK_H
