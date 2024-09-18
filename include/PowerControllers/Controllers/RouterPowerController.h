#ifndef ROUTERPOWERCONTROLLER_H
    #define ROUTERPOWERCONTROLLER_H

    #include "PowerControllers/PowerController.h"

    class RouterPowerController : public PowerController {
        public:
            RouterPowerController(uint8_t controlPin);
            ~RouterPowerController() override;
    };

#endif
