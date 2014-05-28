#include "DoubleArray.h"

using namespace TexturalAnalysis;

DoubleArray::DoubleArray(const int size) {
    arraySize = size;

    arrayData = new double[arraySize];
}

DoubleArray::DoubleArray(const DoubleArray& doubleArray) {
    arraySize = doubleArray.size();

    arrayData = new double[arraySize];

    for (int i = 0; i < arraySize; i++) {
        set(i, doubleArray.get(i));
    }
}

DoubleArray::~DoubleArray() {
    delete[] arrayData;
}

DoubleArray& DoubleArray::operator=(const DoubleArray& doubleArray) {
    delete[] arrayData;

    arraySize = doubleArray.size();

    arrayData = new double[arraySize];

    for (int i = 0; i < arraySize; i++) {
        set(i, doubleArray.get(i));
    }

    return *this;
}

int DoubleArray::size() const {
    return arraySize;
}

double DoubleArray::get(const int index) const {
    return arrayData[index];
}

void DoubleArray::set(const int index, double value) {
    arrayData[index] = value;
}