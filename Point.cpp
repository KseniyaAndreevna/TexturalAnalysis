#include "Point.h"

using namespace TexturalAnalysis;

Point::Point() {
    pointX = 0;
    pointY = 0;
}

Point::Point(const double x, const double y) {
    pointX = x;
    pointY = y;
}

double Point::x() const {
    return pointX;
}

double Point::y() const {
    return pointY;
}