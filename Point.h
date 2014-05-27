#ifndef POINT_H
#define POINT_H

namespace TexturalAnalysis {
    /*!
      Класс реализует геометрическое представление точки на плоскости.
    */
    class Point {
    public:
        /*!
          Создает точку с координатами (0, 0).
        */
        Point();

        /*!
          Создает точку с координатами (x, y).
          \param x координата x точки (x, y)
          \param y координата y точки (x, y)
        */
        Point(const double x, const double y);

        /*!
          Возвращает координату x точки (x, y).
          \return координату x точки (x, y).
        */
        double x() const;

        /*!
          Возвращает координату y точки (x, y).
          \return координату y точки (x, y).
        */
        double y() const;

    private:
        double pointX;

        double pointY;
    };
}

#endif