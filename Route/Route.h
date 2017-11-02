#pragma once
#ifndef Route_h
#define Route_h

#include "Arduino.h"
#include <SoftwareSerial.h>

#endif

class Route {
public:

    SoftwareSerial *serial;
    String request;
    String mode;

    Route();

    void setBluetooth(SoftwareSerial *BluetoothInterface);

    bool checkMode(String modeName);

    String getValue(int index);

};