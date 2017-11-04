#include "Arduino.h"
#include "Strobe.h"

#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3

Strobe::Strobe(Route *externalRoute) {
    route = externalRoute;
}

void Strobe::strobe() {

    int red, green, blue;
    interval = route->getValue(1).toInt();
    lag = route->getValue(2).toInt();
    newLag = lag;
    int poisition = 0;
    while (route->checkMode("strobe")) {
        if (poisition == 0) {
            poisition = 255;
            newLag = route->getValue(1).toInt();;
            red  = green = blue = 255;
        } else {
            poisition = 0;
            newLag = route->getValue(2).toInt();
            red = route->color->red;
            green = route->color->green;
            blue = route->color->blue;
        }
        solidColor(red, green, blue);
        delay(newLag);
    }
}

void Strobe::solidColor(int red, int green, int blue)
{
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}