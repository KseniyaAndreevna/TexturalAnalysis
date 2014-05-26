#include "Image.h"

using namespace TexturalAnalysis;

Image::Image(const int size) {
    init(size, size);
}

Image::Image(const int height, const int width) {
    init(height, width);
}

Image::~Image() {
    for (int i = 0; i < imageHeight; i++) {
        delete[] imageMatrix[i];
    }

    delete[] imageMatrix;
}

int Image::height() const {
    return imageHeight;
}

int Image::width() const {
    return imageWidth;
}

int Image::size() const {
    return imageHeight < imageWidth ? imageHeight : imageWidth;
}

void Image::set(const int i, const int j, const double value) {
    imageMatrix[i][j] = value;
}

double Image::get(const int i, const int j) const {
    return imageMatrix[i][j];
}

double Image::getMin() const {
    double min = imageMatrix[0][0];

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            min = imageMatrix[i][j] < min ? imageMatrix[i][j] : min;
        }
    }

    return min;
}

double Image::getMax() const {
    double max = imageMatrix[0][0];

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            max = imageMatrix[i][j] > max ? imageMatrix[i][j] : max;
        }
    }

    return max;
}

void Image::init(const int height, const int width) {
    imageHeight = height;
    imageWidth = width;

    imageMatrix = new double *[imageHeight];

    for (int i = 0; i < imageHeight; i++) {
        imageMatrix[i] = new double[imageWidth];
    }

    for (int i = 0; i < imageHeight; i++) {
        for (int j = 0; j < imageWidth; j++) {
            imageMatrix[i][j] = 0;
        }
    }
}
