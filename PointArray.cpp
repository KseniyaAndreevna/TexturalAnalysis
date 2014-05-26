#include "PointArray.h"

using namespace TexturalAnalysis;

PointArray::PointArray(const int size) {
    arraySize = size;

    arrayData = new Point[arraySize];
}

PointArray::~PointArray() {
    delete[] arrayData;
}

int PointArray::size() const {
    return arraySize;
}

Point PointArray::get(const int index) const {
    return arrayData[index];
}

void PointArray::set(const int index, const Point& point) {
    arrayData[index] = point;
}