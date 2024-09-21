#include "Clock.h"

Clock::Clock() : hours(0), minutes(0) {}

int Clock::getHours() const {
    return hours;
}

int Clock::getMinutes() const {
    return minutes;
}
