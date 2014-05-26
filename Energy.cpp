#include "Energy.h"

#include <cmath>

using namespace TexturalAnalysis;

Image Energy::apply(const Image& image) {
    Image resultImage(image.height(), image.width());

    for (int i = 0; i < resultImage.height(); i++) {
        resultImage.set(i, 0, image.get(i, 0));

        resultImage.set(i, resultImage.width() - 1, image.get(i, image.width() - 1));
    }

    for (int i = 0; i < resultImage.width(); i++) {
        resultImage.set(0, i, image.get(0, i));

        resultImage.set(resultImage.height() - 1, i, image.get(image.height() - 1, i));
    }

    for (int i = 1; i <= (image.height() - 2); i++) {
        for (int j = 1; j <= (image.width() - 2); j++) {
            resultImage.set(i, j, energy(image, i, j));
        }
    }

    const double resultImageMax = resultImage.getMax();

    const double resultImageMin = resultImage.getMin();

    const double coefficient = 255.0 / (resultImageMax - resultImageMin);

    for (int i = 0; i < resultImage.height(); i++) {
        for (int j = 0; j < resultImage.width(); j++) {
            double newValue = floor(coefficient * (resultImage.get(i, j) - resultImageMin));

            resultImage.set(i, j, newValue);
        }
    }

    return resultImage;
}

double Energy::energy(const Image& image, const int imageI, const int imageJ) {
    double sum = 0;

    for (int i = (imageI - 1); i <= (imageI + 1); i++) {
        for (int j = (imageJ - 1); j <= (imageJ + 1); j++) {
            sum += pow(image.get(i, j), 2.0);
        }
    }

    return sum;
}