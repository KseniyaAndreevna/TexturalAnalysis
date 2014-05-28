#include "PointArray.h"

using namespace TexturalAnalysis;

PointArray::PointArray(const int size) {
    arraySize = size;

    arrayData = new Point[arraySize];
}

PointArray::PointArray(const PointArray& pointArray) {
    arraySize = pointArray.size();

    arrayData = new Point[arraySize];

    for (int i = 0; i < arraySize; i++) {
        set(i, pointArray.get(i));
    }
}

PointArray::~PointArray() {
    delete[] arrayData;
}

PointArray& PointArray::operator=(const PointArray& pointArray) {
    delete[] arrayData;

    arraySize = pointArray.size();

    arrayData = new Point[arraySize];

    for (int i = 0; i < arraySize; i++) {
        set(i, pointArray.get(i));
    }

    return *this;
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