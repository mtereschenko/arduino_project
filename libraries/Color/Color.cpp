#include "Arduino.h"
#include "Color.h"

Color::Color() {
    red = 255;
    green = 255;
    blue = 255;
}

void Color::setColor(int redColor, int greenColor, int blueColor) {
    red = 255-redColor;
    green = 255-greenColor;
    blue = 255-blueColor;
}