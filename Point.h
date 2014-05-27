#ifndef POINT_H
#define POINT_H

namespace TexturalAnalysis {
    /*!
       ласс реализует геометрическое представление точки на плоскости.
    */
    class Point {
    public:
        /*!
          —оздает точку с координатами (0, 0).
        */
        Point();

        /*!
          —оздает точку с координатами (x, y).
          \param x координата x точки (x, y)
          \param y координата y точки (x, y)
        */
        Point(const double x, const double y);

        /*!
          ¬озвращает координату x точки (x, y).
          \return координату x точки (x, y).
        */
        double x() const;

        /*!
          ¬озвращает координату y точки (x, y).
          \return координату y точки (x, y).
        */
        double y() const;

    private:
        double pointX;

        double pointY;
    };
}

#endif