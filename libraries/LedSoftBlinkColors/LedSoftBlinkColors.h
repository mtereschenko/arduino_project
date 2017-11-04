#ifndef LedSoftBlinkColors_h
#define LedSoftBlinkColors_h

#include "Arduino.h"

#include <../Route/Route.h>

#endif

class LedSoftBlinkColors {
protected:
    Route *route;
public:
    LedSoftBlinkColors(Route *externalRoute);

    void rainbow();
    void fade();
};