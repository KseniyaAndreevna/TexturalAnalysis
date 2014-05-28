#ifndef FRACTAL_H
#define FRACTAL_H

#include <vector>

#include "Image.h"

#include "PointArray.h"

namespace TexturalAnalysis {
    class Fractal {
    public:
        static std::vector<std::vector<Point>> calculatePointsSerias(const Image& image, const int x1, const int y1, const int x2, const int y2);

    private:
        static double distanse(const std::vector<std::vector<double>> phasePoints, const int i, const int j, const int dimension);

        static int N(const int initialPointsCount, const int dimension);

        static int L(const int dimension);

        static double C(const std::vector<std::vector<double>> phasePoints, const int r, const int initialPointsCount, const int dimension);

        static int heaviside(const std::vector<std::vector<double>> phasePoints, const int r, const int i, const int j, const int dimension);
    };
}

#endif