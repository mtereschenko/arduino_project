#pragma once
#ifndef Route_h
#define Route_h

#include "Arduino.h"
#include <SoftwareSerial.h>

#include <../Color/Color.h>

#endif

class Route {
public:

    SoftwareSerial *serial;
    Color *color;
    String request;
    String mode = "solid";

    Route(Color *color);

    void setBluetooth(SoftwareSerial *BluetoothInterface);

    bool checkMode(String modeName);

    String getValue(int index);

};