#ifndef BATTERYMONITOR_H
    #define BATTERYMONITOR_H

    class BatteryMonitor {
        public:
            BatteryMonitor();
            void setChargeLevel(float chargeLevel);
            float getChargeLevel();
            void setVoltage(float voltage);
            float getVoltage();
        private:
            float _voltage;
            float _chargeLevel;
    };

#endif // BATTERYMONITOR_H
