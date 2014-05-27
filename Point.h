#ifndef POINT_H
#define POINT_H

namespace TexturalAnalysis {
    /*!
      ����� ��������� �������������� ������������� ����� �� ���������.
    */
    class Point {
    public:
        /*!
          ������� ����� � ������������ (0, 0).
        */
        Point();

        /*!
          ������� ����� � ������������ (x, y).
          \param x ���������� x ����� (x, y)
          \param y ���������� y ����� (x, y)
        */
        Point(const double x, const double y);

        /*!
          ���������� ���������� x ����� (x, y).
          \return ���������� x ����� (x, y).
        */
        double x() const;

        /*!
          ���������� ���������� y ����� (x, y).
          \return ���������� y ����� (x, y).
        */
        double y() const;

    private:
        double pointX;

        double pointY;
    };
}

#endif