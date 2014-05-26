#include "DoubleArray.h"

using namespace TexturalAnalysis;

DoubleArray::DoubleArray(const int size) {
    arraySize = size;

    arrayData = new double[arraySize];
}

DoubleArray::~DoubleArray() {
    delete[] arrayData;
}

int DoubleArray::size() const {
    return arraySize;
}

double DoubleArray::get(const int index) {
    return arrayData[index];
}

void DoubleArray::set(const int index, double value) {
    arrayData[index] = value;
}