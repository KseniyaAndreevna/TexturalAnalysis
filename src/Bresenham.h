#ifndef BRESENHAM_H
#define BRESENHAM_H

#include <vector>

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с алгоритмом Брезенхема.
    */
    class Bresenham {
    public:
        /*!
          Возвращает значения интенсивностей пикселей изображения на отрезке, лежащем между заданными точками.
          \param image соответствует переданному изображению
          \param x1 координата x точки (x1, y1)
          \param y1 координата y точки (x1, y1)
          \param x2 координата x точки (x2, y2)
          \param y2 координата y точки (x2, y2)
          \return интенсивностей пикселей изображения на отрезке
        */
        static std::vector<double> determinePoints(const Image& image, const int x1, const int y1, const int x2, const int y2);
    };
}

#endif