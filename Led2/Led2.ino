#include <SoftwareSerial.h>
#include <Wire.h>
#include <Route.h>
#include <LedSolidColors.h>
#include <LedSoftBlinkColors.h>
#include <Fade.h>
#include <Strobe.h>
#include <Color.h>

#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3

SoftwareSerial BluetoothSerialInterface(10, 11);

Color color;
Route route(&color);
LedSolidColors ledSolidColors(&route);
LedSoftBlinkColors ledSoftBlinkColors(&route);
Fade fade(&route);
Strobe strobe(&route);

int firstLoop = 1;

void setup() {
  Serial.begin(9600);
  BluetoothSerialInterface.begin(9600);
  route.setBluetooth(&BluetoothSerialInterface);
}

void  loop() {
  firstStart();
  if (firstLoop == 0) {
    ledSolidColors.solid();
    ledSoftBlinkColors.rainbow();
    fade.breath();
    strobe.strobe();
  }
}

//    solid/0/0/0 - мод/красный/зеленый/синий
//    rainbow/1  - мод/интенсивность
//    breathBlue/10  - мод/интенсивность
//    breathGreen/10  - мод/интенсивность
//    breathRed/10  - мод/интенсивность
//    strobe/300/50/255/104/0 - мод/темнота/свет/красный/зеленый/синий
//    color/0/0/0 - установить цвет/р/г/б

void firstStart() {
  int i;
  int j;
  int delayTime = 5;
  initRGB();
  if (firstLoop == 1) {
    firstLoop = 0;
    for (i = 255, j = 0; i > 0; i--, j++) {
      analogWrite(BLUE_PIN, i);
      analogWrite(RED_PIN, 255);
      analogWrite(GREEN_PIN, 255);
      delay(delayTime);
    }
    delay(delayTime);
    for (i, j; i < 255; i++, j--) {
      analogWrite(BLUE_PIN, i);
      analogWrite(GREEN_PIN, 255);
      analogWrite(RED_PIN, j);
      delay(delayTime);
    }
    for (i, j; i > 0; i--, j++) {
      analogWrite(BLUE_PIN, 255);
      analogWrite(RED_PIN, j);
      analogWrite(GREEN_PIN, 255);
      delay(delayTime);
    }
  }
  initRGB();
}

void initRGB()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  analogWrite(BLUE_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(RED_PIN, 255);
}