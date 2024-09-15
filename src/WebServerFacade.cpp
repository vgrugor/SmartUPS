#include "WebServerFacade.h"

WebServerFacade::WebServerFacade()
    : server(AsyncWebServer {80})
{
}

void WebServerFacade::init() {
    Serial.println("Start init web server:");

    this->addWsHandler();

    this->initRoutes();

    this->begin();

    Serial.println("Finish init web server");
}

void WebServerFacade::addWsHandler() {
    Serial.println(" - start add handler");

    WebSocketFacade& webSocket = WebSocketFacade::getInstance();

    this->server.addHandler(webSocket.getWebSocketObject());

    Serial.println(" - finish add handler");
}

void WebServerFacade::initRoutes() {
    Serial.println(" - start init routes");

    this->server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/index.html", "text/html");
    });

    this->server.serveStatic("/", LittleFS, "/");

    this->server.on("/outdoor/temperature", HTTP_GET, [](AsyncWebServerRequest *request) {
        Serial.println("Start handle /outdoor/temperature request");
        if (request->hasParam("temp")) {
            //WsData& wsData = WsData::getInstance();
            WebSocketFacade& webSocket = WebSocketFacade::getInstance();

            String outdoorTemperature;
            outdoorTemperature = request->getParam("temp")->value();

            Serial.println("Outdoor temperature");
            Serial.println(outdoorTemperature);

            //wsData.setOutdoorTemperature(atof(outdoorTemperature.c_str()));

            webSocket.notifyClients();

            Serial.println("Finish handle /outdoor/temperature request. Status 200");

            request->send(200, "text/plain", "Ok");
        } else {
            Serial.println("Finish handle /outdoor/temperature request. Request not has parameter temp. Status 400");
        
            request->send(400, "text/plain", "Error");
        }

        //Logger ledLogger {GREEN_LED_PIN, RED_LED_PIN};
        //ledLogger.requestReceived();
    });

    //this->server.onNotFound(notFound);

    Serial.println(" - finish init routes");
}

void WebServerFacade::begin() {
    Serial.println(" - start web server begin");

    this->server.begin();

    Serial.println(" - finish web server begin");
}
