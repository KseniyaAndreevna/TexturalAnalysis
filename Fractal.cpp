#include "Fractal.h"

#include <cmath>

#include "Math.h"

#include "Bresenham.h"

#include "Point.h"

using namespace TexturalAnalysis;

std::vector<std::vector<Point>> Fractal::calculatePointsSerias(const Image& image, const int x1, const int y1, const int x2, const int y2) {
    std::vector<double> intensivities = Bresenham::determinePoints(image, x1, y1, x2, y2);

    int intensivitiesCount = intensivities.size();

    std::vector<std::vector<Point>> pointsSerias;

    int pointsSeriasIndex = 0;

    for (int n = 2; n <= 21; n++) {
        pointsSerias.push_back(std::vector<Point>());

        int dimension = n;

        int phasePointsCount = N(intensivitiesCount, dimension);

        std::vector<std::vector<double>> phasePoints(phasePointsCount);

        int length = L(dimension);

        for (int i = 0; i < phasePointsCount; i++) {
            int index = i;

            for (int j = 0; j < length; j++) {
                phasePoints[i].push_back(intensivities[index]);

                index++;
            }
        }

        double isit = 0; 
      
        for (int r = 1; r <= 300; r++) {
            double c = C(phasePoints, r, intensivitiesCount, n);

            if (isit != c) {
                Point point(Math::ln(r), Math::ln(c));

                pointsSerias[pointsSeriasIndex].push_back(point);

                isit = c;
            }
        }

        pointsSeriasIndex++;
    }

    return pointsSerias;
}

double Fractal::distanse(const std::vector<std::vector<double>> phasePoints, const int i, const int j, const int dimension) {
    double sum = 0;

    for (int k = 0; k < dimension; k++) {
        sum += pow(phasePoints[j][k] - phasePoints[i][k], 2.0);
    }

    return pow(sum, 1/2.0);
}

int Fractal::N(const int initialPointsCount, const int dimension) {
    return initialPointsCount - (dimension - 1);
}

int Fractal::L(const int demension) {
    return demension;
}

double Fractal::C(const std::vector<std::vector<double>> phasePoints, const int r, const int initialPointsCount, const int dimension) {
    int number = N(initialPointsCount, dimension);

    int innerPointsCount = 0;

    for (int j = 0; j < dimension; j++) {
        innerPointsCount += heaviside(phasePoints, r, 0, j, dimension);
    }

    double totalValue = (1.0 / pow(dimension, 2.0)) * innerPointsCount;

    return totalValue > 0 ? totalValue : 0.01;
}

int Fractal::heaviside(const std::vector<std::vector<double>> phasePoints, const int r, const int i, const int j, const int dimension) {
    return r - distanse(phasePoints, i, j, dimension) > 0 ? 1 : 0;
}