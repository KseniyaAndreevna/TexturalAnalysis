#include "Contrast.h"

#include <cmath>

using namespace TexturalAnalysis;

Image Contrast::apply(const Image& image) {
    Image resultImage(image.height(), image.width());

    for (int i = 2; i <= image.height() - 3; i++) {
        for (int j = 2; j <= image.width() - 3; j++) {
            resultImage.set(i, j, contrast(image, i, j));
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

double Contrast::contrast(const Image& image, int imageI, int imageJ) {
    double sum = 0;

    sum += 1.0 * pow(image.get(imageI - 1, imageJ), 2.0);
    sum += 1.0 * pow(image.get(imageI + 1, imageJ), 2.0);

    sum += 4.0 * pow(image.get(imageI - 1, imageJ + 1), 2.0);
    sum += 4.0 * pow(image.get(imageI + 1, imageJ - 1), 2.0);

    sum += 1.0 * pow(image.get(imageI, imageJ - 1), 2.0);
    sum += 1.0 * pow(image.get(imageI, imageJ + 1), 2.0);

    return sum;
}