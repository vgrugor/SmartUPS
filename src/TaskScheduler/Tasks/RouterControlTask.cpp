#include "TaskScheduler/Tasks/RouterControlTask.h"

RouterControlTask::RouterControlTask(
    uint8_t offHour, 
    MediaConverterPowerController &mediaConverterPowerController,
    RouterPowerController &routerPowerController,
    TimeManager &timeManager
) : _offHour(offHour), 
    _mediaConverterPowerController(mediaConverterPowerController), 
    _routerPowerController(routerPowerController),
    _timeManager(timeManager) 
{}

void RouterControlTask::execute() {
    _mediaConverterPowerController.turnOff();
    _routerPowerController.turnOff();
}

bool RouterControlTask::isDue() {
    return _timeManager.getHour() == _offHour;
}
