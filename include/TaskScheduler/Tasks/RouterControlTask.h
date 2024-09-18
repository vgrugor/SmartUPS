#ifndef ROUTERCONTROLTASK_H
    #define ROUTERCONTROLTASK_H

    #include "TaskScheduler/Task.h"
    #include "PowerControllers/Controllers/MediaConverterPowerController.h"
    #include "PowerControllers/Controllers/RouterPowerController.h"
    #include "TimeManager.h"

    class RouterControlTask : public Task {
        public:
            RouterControlTask(
                uint8_t offHour, 
                MediaConverterPowerController &mediaConverterPowerController,
                RouterPowerController &routerPowerController,
                TimeManager &timeManager
            );
            void execute() override;
            bool isDue() override;
        private:
            uint8_t _offHour;
            MediaConverterPowerController &_mediaConverterPowerController;
            RouterPowerController &_routerPowerController;
            TimeManager &_timeManager;
    };

#endif // ROUTERCONTROLTASK_H
