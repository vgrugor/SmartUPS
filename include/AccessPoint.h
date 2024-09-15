#ifndef ACCESS_POINT_H
    #define ACCESS_POINT_H

    #include <ESP8266WiFi.h>

    class AccessPoint {
        public:
            AccessPoint(
                const char* ssid,
                const char* password, 
                IPAddress local_ip = IPAddress(192, 168, 1, 10),
                IPAddress gateway = IPAddress(192, 168, 1, 1),
                IPAddress subnet = IPAddress(255, 255, 255, 0)
            );
            void start();
            int getConnectedDevices();
            void printConnectedDevices();

        private:
            const char* ssid;
            const char* password;
            IPAddress local_ip;
            IPAddress gateway;
            IPAddress subnet;
    };  

#endif
