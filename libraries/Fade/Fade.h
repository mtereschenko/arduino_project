#ifndef Fade_h
#define Fade_h

#include "Arduino.h"

#include <../Route/Route.h>

#endif

class Fade {
protected:
    Route *route;

    void solidColor(int red, int green, int blue);

public:
    Fade(Route *externalRoute);

    void start();

    void breath();
};