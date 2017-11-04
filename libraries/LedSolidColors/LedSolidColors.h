#ifndef LedSolidColors_h
#define LedSolidColors_h

#include "Arduino.h"

#include <../Route/Route.h>

#endif

class LedSolidColors {
protected:
    Route *route;
public:
    LedSolidColors(Route *externalRoute);

    void solid();

};