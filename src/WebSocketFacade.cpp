#include "WebSocketFacade.h"

WebSocketFacade& WebSocketFacade::getInstance() {
    static WebSocketFacade instance;
    return instance;
}

WebSocketFacade::WebSocketFacade()
    : webSocket(AsyncWebSocket {"/ws"})
{
    using namespace std::placeholders;

    this->webSocket.onEvent(
        std::bind(&WebSocketFacade::handleEvent, this, _1, _2, _3, _4, _5, _6)
    );
}

AsyncWebSocket* WebSocketFacade::getWebSocketObject() {
    return &this->webSocket;
}

void WebSocketFacade::handleEvent(
    AsyncWebSocket *server,
    AsyncWebSocketClient *client,
    AwsEventType type,
    void *arg,
    uint8_t *data,
    size_t len
) {
    switch (type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            break;
        case WS_EVT_DISCONNECT:
            Serial.printf("WebSocket client #%u disconnected\n", client->id());
            break;
        case WS_EVT_DATA:
            Serial.println("WebSocket client event WS_EVT_DATA");
            this->handleMessage(arg, data, len);
            break;
        case WS_EVT_PONG:
            case WS_EVT_ERROR:
            break;
    }
}

void WebSocketFacade::handleMessage(
    void *arg,
    uint8_t *data,
    size_t len
) {
    Serial.println("Run ws handler");
    AwsFrameInfo *info = (AwsFrameInfo*)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        data[len] = 0;

        String message = (char*)data;

        //WsMessageResolver wsMessageResolver {};
        //bool result = wsMessageResolver.resolve(message);

        //if (result) {
             //this->notifyClients();
        //}
    }
}

void WebSocketFacade::notifyClients() {
    Serial.println("Notify clients");
    //WsData& wsData = WsData::getInstance();

    //this->webSocket.textAll(wsData.toJSON());
}

void WebSocketFacade::cleanupClients() {
    this->webSocket.cleanupClients();
}
