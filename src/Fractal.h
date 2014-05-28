#ifndef FRACTAL_H
#define FRACTAL_H

#include <vector>

#include "Image.h"

#include "PointArray.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с фрактальным анализом.
    */
    class Fractal {
    public:
        /*!
          Вычисляет серии точек с помощью алгоритма фрактального анализа.
          \param image соответствует переданному изображению
          \param x1 координата x точки (x1, y1)
          \param y1 координата y точки (x1, y1)
          \param x2 координата x точки (x2, y2)
          \param y2 координата y точки (x2, y2)
          \return вычисленные серии точек
        */
        static std::vector<std::vector<Point>> calculatePointsSerias(const Image& image, const int x1, const int y1, const int x2, const int y2);

    private:
        static double distanse(const std::vector<std::vector<double>>& phasePoints, const int i, const int j, const int dimension);

        static int N(const int initialPointsCount, const int dimension);

        static int L(const int dimension);

        static double C(const std::vector<std::vector<double>>& phasePoints, const int r, const int initialPointsCount, const int dimension);

        static int heaviside(const std::vector<std::vector<double>>& phasePoints, const int r, const int i, const int j, const int dimension);
    };
}

#endif