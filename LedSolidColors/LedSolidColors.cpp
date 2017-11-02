#include "Arduino.h"
#include "LedSolidColors.h"

#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3

LedSolidColors::LedSolidColors(Route *externalRoute) {
    route = externalRoute;
}

void LedSolidColors::solid() {
    while (route->checkMode("solid")) {
        analogWrite(BLUE_PIN, route->getValue(1).toInt());
        analogWrite(GREEN_PIN, route->getValue(2).toInt());
        analogWrite(RED_PIN, route->getValue(3).toInt());
    }
};