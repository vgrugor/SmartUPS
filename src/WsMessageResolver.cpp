#include "WsMessageResolver.h"

WsMessageResolver::WsMessageResolver()
    //: lightController(LightController {}),
    //wsData(WsData::getInstance()),
    //taskScheduler(TaskSchedulerFacade::getInstance())
{
}

bool WsMessageResolver::resolve(String message) {
    Serial.println("Resolved ws message:");
    
    bool result = false;

    if (message.indexOf("1s") >= 0) {
        this->changeAllLedMatrixLevel(message);
        Serial.println(" - change all led matrix level");
        result = true;
    }

    if (message.indexOf("2s") >= 0) {
        this->changeTimerMinute(message);
        Serial.println(" - change timer minute");
        result = true;
    }

    if (message.indexOf("3s") >= 0) {
        this->changeLeftLedMatrixLevel(message);
        Serial.println(" - change left led matrix level");
        result = true;
    }

    if (message.indexOf("4s") >= 0) {
        this->changeCenterLedMatrixLevel(message);
        Serial.println(" - change center led matrix level");
        result = true;
    }

    if (message.indexOf("5s") >= 0) {
        this->changeRightLedMatrixLevel(message);
        Serial.println(" - change right led matrix level");
        result = true;
    }

    if (message.indexOf("getValues") >= 0) {
        Serial.println(" - get values");
        result = true;
    }

    return result;
}

void WsMessageResolver::changeAllLedMatrixLevel(String message) {
    String allSliderValue = message.substring(2);
    //wsData.setAllLedMatrixLevel(allSliderValue.toInt());
    //lightController.allLedMatrixSetLevel(wsData.getAllLedMatrixLevel());
}

void WsMessageResolver::changeTimerMinute(String message) {
    String timerMinute = message.substring(2);
    //wsData.setTimerMinute(timerMinute.toInt());
    //this->taskScheduler.addTaskInMinutes(wsData.getTimerMinute(), DisableAllLedMatrixTask::run);
}

void WsMessageResolver::changeLeftLedMatrixLevel(String message) {
    String leftSliderValue = message.substring(2);
    //wsData.setLeftLedMatrixLevel(leftSliderValue.toInt());
    //lightController.leftLedMatrixSetLevel(wsData.getLeftLedMatrixLevel());
}

void WsMessageResolver::changeCenterLedMatrixLevel(String message) {
    String centerSliderValue = message.substring(2);
    //wsData.setCenterLedMatrixLevel(centerSliderValue.toInt());
    //lightController.centerLedMatrixSetLevel(wsData.getCenterLedMatrixLevel());
}

void WsMessageResolver::changeRightLedMatrixLevel(String message) {
    String rightSliderValue = message.substring(2);
    //wsData.setRightLedMatrixLevel(rightSliderValue.toInt());
    //lightController.rightLedMatrixSetLevel(wsData.getRightLedMatrixLevel());
}
