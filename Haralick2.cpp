#include "Haralick2.h"

#include <cmath>

using namespace TexturalAnalysis;

Image Haralick2::apply(const Image& image) {
    Image resultImage(image.height(), image.width());

    for (int i = 1; i <= image.height() - 2; i++) {
        for (int j = 1; j <= image.width() - 2; j++) {
            double value = floor(haralick2(image, i, j));

            resultImage.set(i, j, value);
        }
    }

    const double resultImageMax = resultImage.getMax();

    const double resultImageMin = resultImage.getMin();

    const double coefficient = 255.0 / (resultImageMax - resultImageMin);

    for (int i = 1; i < resultImage.height() - 1; i++) {
        for (int j = 1; j < resultImage.width() - 1; j++) {
            double value = floor(coefficient * (resultImage.get(i, j) - resultImageMin));

            if (resultImage.get(i, j) > 255) {
                resultImage.set(i, j, 255);
            } else if (resultImage.get(i, j) < 0) {
                resultImage.set(i, j, 0);
            }
        }
    }

    return resultImage;
}

double Haralick2::haralick2(const Image& image, const int I, const int J) {
    int Seria_index = 0;

    double serias[9][2] = {0};

    for (int i = I - 1; i <= I + 1; i++){//3x3
        for (int j = J - 1; j <= J + 1; j++){
            if (serias[Seria_index][1] == 0) {
                serias[Seria_index][0] = image.get(i, j);
            }

            if (image.get(i, j) == serias[Seria_index][0]) {
                serias[Seria_index][1]++;
            } else {
                Seria_index++;
                serias[Seria_index][0] = image.get(i, j);
                serias[Seria_index][1] = 1;
            }
        }

        Seria_index++;
    }

    int SeriasCount = Seria_index;

    int Ng = 256, Nr = 3;

    double p[9][3] = {0};

    int pSize = 0;

    for (int i = 0; i < SeriasCount; i++) {
        bool isFound = false;

        for (int j = 0; j < pSize; j++) {
            if ((p[j][0] == serias[i][0]) && (p[j][1] == serias[i][1])) {
                p[j][2]++;
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            p[pSize][0] = serias[i][0];
            p[pSize][1] = serias[i][1];
            p[pSize][2] = 1;

            pSize++;
        }
    }

    double UpSumm = 0;
    double DownSumm = 0;

    for (int i = 0; i < pSize; i++){
        UpSumm += pow(p[i][1], 2.0) * p[i][2];
        DownSumm += p[i][2];
    }

    return UpSumm/DownSumm;
}