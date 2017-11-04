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
        Serial.println(route->color->blue);
        Serial.println(route->color->green);
        Serial.println(route->color->red);
        Serial.println("========");
        analogWrite(BLUE_PIN, route->color->blue);
        analogWrite(GREEN_PIN, route->color->green);
        analogWrite(RED_PIN, route->color->red);

        delay(1000);
    }
};