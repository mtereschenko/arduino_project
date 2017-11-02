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

void LedSoftBlinkColors::fade() {
    while (route->checkMode("fade")) {
        int pins[3];
        pins[0] = (route->getValue(2).toInt() != RED_PIN) ? 0 : RED_PIN;
        pins[1] = (route->getValue(3).toInt() != BLUE_PIN) ? 0 : BLUE_PIN;
        pins[2] = (route->getValue(4).toInt() != GREEN_PIN) ? 0 : GREEN_PIN;
        int j = 255;
        for (int i = 0; i < 3; i++) {
            if (pins[i] == 0) {
                continue;
            }
            for (j; j > 0; j--) {
                if (!route->checkMode("fade")) {
                    return;
                }
                analogWrite(pins[i], j);
                delay(route->getValue(1).toInt());
            }
            for (j; j < 255; j++) {
                if (!route->checkMode("fade")) {
                    return;
                }
                analogWrite(pins[i], j);
                delay(route->getValue(1).toInt());
            }
            delay(route->getValue(1).toInt() * 5);
        }
    }
}