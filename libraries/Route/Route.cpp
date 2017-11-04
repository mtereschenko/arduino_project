#include "Route.h"
#include "Arduino.h"

Route::Route(Color *referenceColor) {
    color = referenceColor;
}

void Route::setBluetooth(SoftwareSerial *BluetoothInterface) {
    serial = BluetoothInterface;
}

bool Route::checkMode(String modeName) {
    String requestedMode;
    if (serial->available() > 0) {
        request = serial->readString();
        requestedMode = getValue(0);
        if (requestedMode == "color") {
            color->setColor(getValue(1).toInt(), getValue(2).toInt(), getValue(3).toInt());
        } else {
            mode = requestedMode;
        }
    }

    if (Serial.available() > 0) {
        request = Serial.readString();
        requestedMode = getValue(0);
        if (requestedMode == "color") {
            color->setColor(getValue(1).toInt(), getValue(2).toInt(), getValue(3).toInt());
        } else {
            mode = requestedMode;
        }
    }

//    Serial.println(mode);
//    Serial.println(modeName);
    if (modeName != mode) {
        return false;
    } else {
        return true;
    }

}

String Route::getValue(int index) {
    char separator = '/';
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = request.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (request.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }

    return found > index ? request.substring(strIndex[0], strIndex[1]) : "";
}

