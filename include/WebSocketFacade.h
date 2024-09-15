// WebSocketFacade.h
#ifndef WEBSOCKETFACADE_H
    #define WEBSOCKETFACADE_H

    #include <ESPAsyncWebServer.h>
    //#include "App/data/ws/wsData.h"
    //#include "App/WsMessageResolver/WsMessageResolver.h"

    class WebSocketFacade
    {
        public:
            static WebSocketFacade& getInstance();
            AsyncWebSocket* getWebSocketObject();
            void notifyClients();
            void cleanupClients();

        private:
            AsyncWebSocket webSocket;
            void handleEvent(
                AsyncWebSocket *server,
                AsyncWebSocketClient *client,
                AwsEventType type,
                void *arg,
                uint8_t *data,
                size_t len
            );
            void handleMessage(void *arg, uint8_t *data, size_t len);
            WebSocketFacade();
            ~WebSocketFacade() = default;
            WebSocketFacade(const WebSocketFacade&) = delete;
            WebSocketFacade& operator=(const WebSocketFacade&) = delete;
    };

#endif
