#include "Entropy.h"

#include <iostream>
#include <cmath>

using namespace TexturalAnalysis;

Image Entropy::apply(const Image& image) {
    Image resultImage(image.height(), image.width());

    for (int i = 1; i <= image.height() - 2; i++) {
        for (int j = 1; j <= image.width() - 2; j++) {
            resultImage.set(i, j, entropy(image, i, j));
        }
    }

    const double resultImageMax = resultImage.getMax();

    const double resultImageMin = resultImage.getMin();

    const double coefficient = 255.0 / (resultImageMax - resultImageMin);

    for (int i = 0; i < resultImage.height(); i++) {
        for (int j = 0; j < resultImage.width(); j++) {
            double value = floor(coefficient * (resultImage.get(i, j) - resultImageMin));

            resultImage.set(i, j, value);
        }
    }

    return resultImage;
}

double Entropy::entropy(const Image& image, const int imageI, const int imageJ) {
    double sum = 0;

    for (int i = imageI - 1; i <= imageI + 1; i++) {
        for (int j = imageJ - 1; j <= imageJ + 1; j++) {
          sum += image.get(i, j) * log10(image.get(i, j) + 0.0001);
        }
    }

    return sum;
}
