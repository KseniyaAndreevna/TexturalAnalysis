#ifndef RS_H
#define RS_H

#include "Image.h"

#include "PointArray.h"

#include "HirstValues.h"

namespace TexturalAnalysis {
    /*!
      ����� �������� ����������, ��������� � RS-��������.
    */
    class RS {
    public:
        /*!
          ���������� ������ �������������� ����� {(ln(i), ln(rs[i])} ����������� �� ������ ����������� ����������� � ���� ����� �� ���.
          \param image ������������� ����������� �����������
          \param x1 ���������� x ����� (x1, y1)
          \param y1 ���������� y ����� (x1, y1)
          \param x2 ���������� x ����� (x2, y2)
          \param y2 ���������� y ����� (x2, y2)
          \return ����������� ������ �������������� ����� {(ln(i), ln(rs[i])}.
        */
        static PointArray calculatePoints(const Image& image, const int x1, const int y1, const int x2, const int y2);

        /*!
          ���������� ����������� ո���� � ��������� ����������� ������, ������������ �����.
          \param rsPoints ������ �������������� ����� {(ln(i), ln(rs[i]))}
          \return ����������� �������� ո����.
        */
        static HirstValues calculateHirstValues(const PointArray& rsPoints);
    };
}

#endif