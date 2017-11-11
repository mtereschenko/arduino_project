#include "Arduino.h"
#include "LedSoftBlinkColors.h"

#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3

LedSoftBlinkColors::LedSoftBlinkColors(Route *externalRoute) {
    route = externalRoute;
}

void LedSoftBlinkColors::rainbow() {
    while (route->checkMode("rainbow")) {
        int i;
        int j;
        for (i = 255, j = 0; i > 0; i--, j++) {
            if (!route->checkMode("rainbow")) {
                return;
            }
            analogWrite(BLUE_PIN, i);
            analogWrite(GREEN_PIN, 255);
            analogWrite(RED_PIN, j);
            delay(route->getValue(1).toInt());
        }
        for (i, j; j > 0; j--, i++) {
            if (!route->checkMode("rainbow")) {
                return;
            }
            analogWrite(BLUE_PIN, i);
            analogWrite(GREEN_PIN, j);
            analogWrite(RED_PIN, 255);
            delay(route->getValue(1).toInt());
        }
        for (i, j; i > 0; j++, i--) {
            if (!route->checkMode("rainbow")) {
                return;
            }
            analogWrite(BLUE_PIN, 255);
            analogWrite(GREEN_PIN, j);
            analogWrite(RED_PIN, i);
            delay(route->getValue(1).toInt());
        }
    }
}