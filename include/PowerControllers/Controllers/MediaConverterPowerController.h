#ifndef MEDIACONVERTERPOWERCONTROLLER_H
    #define MEDIACONVERTERPOWERCONTROLLER_H

    #include "PowerControllers/PowerController.h"

    class MediaConverterPowerController : public PowerController {
        public:
            MediaConverterPowerController(uint8_t controlPin);
            ~MediaConverterPowerController() override;
    };

#endif
