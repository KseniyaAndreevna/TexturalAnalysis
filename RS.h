#ifndef RS_H
#define RS_H

#include "Image.h"

#include "PointArray.h"

#include "HirstValues.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с RS-анализом.
    */
    class RS {
    public:
        /*!
          Возвращает массив геометрических точек {(ln(i), ln(rs[i])} вычисленный на основе переданного изображения и двух точек на нем.
          \param image соответствует переданному изображению
          \param x1 координата x точки (x1, y1)
          \param y1 координата y точки (x1, y1)
          \param x2 координата x точки (x2, y2)
          \param y2 координата y точки (x2, y2)
          \return вычисленный массив геометрических точек {(ln(i), ln(rs[i])}.
        */
        static PointArray calculatePoints(const Image& image, const int x1, const int y1, const int x2, const int y2);

        /*!
          Возвращает коэффициент Хёрста и свободный коэффициент прямой, приближающей точки.
          \param rsPoints массив геометрических точек {(ln(i), ln(rs[i]))}
          \return вычисленные значения Хёрста.
        */
        static HirstValues calculateHirstValues(const PointArray& rsPoints);
    };
}

#endif