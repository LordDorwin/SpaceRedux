//utility.cpp

#include "utility.h"
#include <cmath>

double pointDirection(int x1, int y1, int x2, int y2) {
	return radDeg(atan2(y1 - y2, x1 - x2)) + 180;
}

double degRad(double deg) {
	return deg / 180 * 3.1415926535897932;
}

double radDeg(double rad) {
	return rad * 180 / 3.1415926535897932;
}