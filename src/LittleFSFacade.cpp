#include "LittleFSFacade.h"

LittleFSFacade::LittleFSFacade()
{
}

void LittleFSFacade::init() {
    if (!LittleFS.begin()) {
        Serial.println("An error has occurred while mounting LittleFS");
    }
    else{
        Serial.println("LittleFS mounted successfully");
    }
}
