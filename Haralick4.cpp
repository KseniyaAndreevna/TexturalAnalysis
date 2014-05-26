#include "Haralick4.h"

#include <cmath>

using namespace TexturalAnalysis;

Image Haralick4::apply(const Image& image) {
    Image resultImage(image.height(), image.width());

    for (int i = 1; i <= image.height() - 2; i++) {
        for (int j = 1; j <= image.width() - 2; j++) {
            double value = floor(haralick4(image, i, j));

            resultImage.set(i, j, value);
        }
    }

    const double resultImageMax = resultImage.getMax();

    const double resultImageMin = resultImage.getMin();

    const double coefficient = 255.0 / (resultImageMax - resultImageMin);

    for (int i = 1; i < resultImage.height() - 1; i++) {
        for (int j = 1; j < resultImage.width() - 1; j++) {
            double value = floor(coefficient * (resultImage.get(i, j) - resultImageMin));

            resultImage.set(i, j, value);

            if (resultImage.get(i, j) > 255) {
                resultImage.set(i, j, 255);
            } else if (resultImage.get(i, j) < 0) {
                resultImage.set(i, j, 0);
            }
        }
    }

    return resultImage;
}

double Haralick4::haralick4(const Image& image, const int I, const int J) {
    int Seria_index = 0;

    double serias[9][2] = {0};


    for (int i = I - 1; i <= I + 1; i++) {
        for (int j = J - 1; j <= J + 1; j++) {
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

    double k = 0;
    double l = 0;
    double m = 0;

    for (int i = 0; i < pSize - 1; i++) {
        for (int j = 0; j < pSize - 1; j++) {
            if ( p[j+1][1] > p[j][1] ) {
                k = p[j][0]; p[j][0] = p[j+1][0]; p[j+1][0] = k;
                l = p[j][1]; p[j][1] = p[j+1][1]; p[j+1][1] = l;
                m = p[j][2]; p[j][2] = p[j+1][2]; p[j+1][2] = m;
            }
        }
    }

    double UpSumm = 0;
    double DownSumm = 0;

    int M = 0;
    M = p[0][2];

    for (int i = 0; i < pSize; i++) {
        if (p[i][1] != p[i + 1][1]) {
            UpSumm += pow(M, 2.0);
            M = p[i + 1][2];
        } else {
            M += p[i+1][2];
        }
    }

    for (int i = 0; i < pSize; i++) {
        DownSumm += p[i][2];
    }

    return UpSumm/DownSumm;
}