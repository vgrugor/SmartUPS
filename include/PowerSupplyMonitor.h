#ifndef POWERSUPPLYMONITOR_H
    #define POWERSUPPLYMONITOR_H

    class PowerSupplyMonitor {
        public:
            PowerSupplyMonitor();
            void setMainsPower(bool isMainsPower);
            bool isMainsPower();
            bool isBatteryPower();
        private:
            bool _mainsPower;
    };

#endif // POWERSUPPLYMONITOR_H
