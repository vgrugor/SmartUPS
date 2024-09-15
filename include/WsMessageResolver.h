// WsMessageResolver.h
#ifndef WSMESSAGERESOLVER_H
    #define WSMESSAGERESOLVER_H

    #include <Arduino.h>
    //#include "App/data/ws/wsData.h"
    //#include "App/Facades/TaskScheduler/TaskSchedulerFacade.h"
    //#include "App/Task/DisableAllLedMatrix/DisableAllLedMatrixTask.h"

    class WsMessageResolver
    {
        public:
            WsMessageResolver();
            bool resolve(String message);

        private:
            //LightController lightController;
            //WsData& wsData;
            //TaskSchedulerFacade& taskScheduler;
            void changeAllLedMatrixLevel(String message);
            void changeTimerMinute(String message);
            void changeLeftLedMatrixLevel(String message);
            void changeCenterLedMatrixLevel(String message);
            void changeRightLedMatrixLevel(String message);
    };

#endif
