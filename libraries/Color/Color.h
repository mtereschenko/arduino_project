#pragma once
#ifndef Color_h
#define Color_h

#include "Arduino.h"

#endif


class Color {
public:
    int red;
    int green;
    int blue;

    Color();
    void setColor(int redColor, int greenColor, int blueColor);
};