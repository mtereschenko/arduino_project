#include "Route.h"
#include "Arduino.h"

Route::Route() {}

void Route::setBluetooth(SoftwareSerial *BluetoothInterface) {
    serial = BluetoothInterface;
}

bool Route::checkMode(String modeName) {
    if (serial->available() > 0) {
        request = serial->readString();
        mode = getValue(0);
    }

    if (Serial.available() > 0) {
        request = Serial.readString();
        mode = getValue(0);
    }

//    Serial.println(mode);
//    Serial.println(modeName);
    if (modeName != mode) {
        return false;
    } else {
        return true;
    }

}

String Route::getValue(int index)
{
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

