#include "OfflineClock.h"

OfflineClock::OfflineClock() : Clock(), lastMillis(millis()) {}

void OfflineClock::update() {
    unsigned long currentMillis = millis();
    unsigned long elapsedTime = calculateElapsedTime(currentMillis);
    
    unsigned long elapsedMinutes = elapsedTime / 60000;
    minutes += elapsedMinutes;
    hours += minutes / 60;
    
    minutes %= 60;
    hours %= 24;
    
    lastMillis = currentMillis;
}

unsigned long OfflineClock::calculateElapsedTime(unsigned long currentMillis) const {
    return (currentMillis >= lastMillis) 
        ? (currentMillis - lastMillis) 
        : (ULONG_MAX - lastMillis + currentMillis + 1);
}
