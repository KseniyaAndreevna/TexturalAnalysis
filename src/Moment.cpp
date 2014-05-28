#include "Moment.h"

#include <cmath>

using namespace TexturalAnalysis;

Image Moment::apply(const Image& image) {
    Image resultImage(image.height(), image.width());

    for (int i = 0; i < resultImage.height(); i++) {
        for (int j = 0; j < resultImage.width(); j++) {
            resultImage.set(i, j, 1.);
        }
    }

    for (int i = 2; i <= image.height() - 3; i++) {
        for (int j = 2; j <= image.width() - 3; j++) {
            if (i != j) {
                resultImage.set(i, j, moment(image, i, j));
            }
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

    for (int i = 0; i < resultImage.size(); i++) {
        resultImage.set(i, i, image.get(i, i));
    }

    return resultImage;
}

double Moment::moment(const Image& image, const int imageI, const int imageJ) {
    double sum = 0;

    sum += pow(image.get(imageI - 1, imageJ), 2.0) / 1.0;
    sum += pow(image.get(imageI + 1, imageJ), 2.0) / 1.0;
 
    sum += pow(image.get(imageI, imageJ - 1), 2.0) / 1.0;
    sum += pow(image.get(imageI, imageJ + 1), 2.0) / 1.0;

    sum += pow(image.get(imageI - 1, imageJ + 1), 2.0) / 4.0;
    sum += pow(image.get(imageI + 1, imageJ - 1), 2.0) / 4.0;

    return sum;
}