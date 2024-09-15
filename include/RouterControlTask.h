#ifndef ROUTERCONTROLTASK_H
#define ROUTERCONTROLTASK_H

#include "Task.h"
#include "PowerController.h"
#include "TimeManager.h"

class RouterControlTask : public Task {
    public:
        RouterControlTask(uint8_t offHour, PowerController &powerController, TimeManager &timeManager);
        void execute() override;
        bool isDue() override;
    private:
        uint8_t _offHour;
        PowerController &_powerController;
        TimeManager &_timeManager;
};

#endif // ROUTERCONTROLTASK_H
