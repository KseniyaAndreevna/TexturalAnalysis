#include "MaxProbability.h"

#include <cmath>

using namespace TexturalAnalysis;

Image MaxProbability::apply(const Image& image) {
    Image resultImage(image.height(), image.width());

    for (int i = 2; i <= image.height() - 3; i++) {
        for (int j = 2; j <= image.width() - 3; j++) {
            resultImage.set(i, j, maxProbability(image, i, j));
        }
    }

    const double resultImageMax = resultImage.getMax();

    const double resultImageMin = resultImage.getMin();

    const double coefficient = 255.0 / (resultImageMax - resultImageMin);

    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            double value = floor(coefficient * (resultImage.get(i, j) - resultImageMin));

            resultImage.set(i, j, value);
        }
    }

    return resultImage;
}

double MaxProbability::maxProbability(const Image& image, const int imageI, const int imageJ) {
    double max = 0;

    for (int i = imageI - 1; i <= imageI + 1; i++) {
        for (int j = imageJ - 1; j <= imageJ + 1; j++) {
            max = image.get(i, j) > max ? image.get(i, j) : max;
        }
    }

    return max;
}