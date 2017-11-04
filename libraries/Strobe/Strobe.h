#ifndef Strobe_h
#define Strobe_h

#include "Arduino.h"

#include <../Route/Route.h>

#endif

class Strobe {
protected:
	Route *route;
	int interval;
	int lag;
	int newLag;
	void solidColor(int red, int green, int blue);
public:
	Strobe(Route *externalRoute);

	void strobe();

};