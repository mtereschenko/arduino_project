#include "Arduino.h"
#include "Color.h"

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

void Color::setColor(int redColor, int greenColor, int blueColor) {
    red = 255-redColor;
    green = 255-greenColor;
    blue = 255-blueColor;
}