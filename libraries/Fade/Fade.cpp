#include "Arduino.h"
#include "Fade.h"

#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3

Fade::Fade(Route *externalRoute) {
    route = externalRoute;
}

void Fade::breath() {
    int red, green, blue = 255;
    while (route->checkMode("breath")) {
        int i = 255;
        bool increaseRed;
        bool increaseGreen;
        bool increaseBlue;
        for (i; i > 0; i--) {
            bool changedRed = false;
            bool changedGreen = false;
            bool changedBlue = false;
            if (!route->checkMode("breath")) {
                return;
            }
            if (red >= route->color->red) {
                if (increaseRed) {
                    changedRed = true;
                }
                increaseRed = false;
            }
            if (red == 0 && !changedRed) {
                increaseRed = true;
            }
            if (increaseRed) {
                red++;
            }
            if (!increaseRed) {
                red--;
            }

            if (green >= route->color->green) {
                if (increaseGreen) {
                    changedGreen = true;
                }
                increaseGreen = false;
            }
            if (green == 0 && !changedGreen) {
                increaseGreen = true;
            }
            if (increaseGreen) {
                green++;
            }
            if (!increaseGreen) {
                green--;
            }

            if (blue >= route->color->blue) {
                if (increaseBlue) {
                    changedBlue = true;
                }
                increaseBlue = false;
            }
            if (blue == 0 && !changedBlue) {
                increaseBlue = true;
            }
            if (increaseBlue) {
                blue++;
            }
            if (!increaseBlue) {
                blue--;
            }

            solidColor(255 - red, 255 - green, 255 - blue);

            delay(route->getValue(1).toInt());
        }
    }
}

void Fade::solidColor(int red, int green, int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}