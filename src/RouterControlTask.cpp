#include "RouterControlTask.h"

RouterControlTask::RouterControlTask(
    uint8_t offHour, 
    PowerController &powerController, 
    TimeManager &timeManager
) : _offHour(offHour), _powerController(powerController), _timeManager(timeManager) {}

void RouterControlTask::execute() {
    // Отключаем роутер
    _powerController.turnOff();
}

bool RouterControlTask::isDue() {
    return _timeManager.getHour() == _offHour;
}
