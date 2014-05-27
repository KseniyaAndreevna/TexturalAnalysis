#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "Point.h"

namespace TexturalAnalysis {
    /*!
      ����� �������� ������ �������������� �����.
    */
    class PointArray {
    public:
        /*!
          ������� ������ �������������� ����� ��������� �������.
          \param size ������ �������
        */
        PointArray(const int size);

        /*!
          ������� ��������� ������.
        */
        ~PointArray();

        /*!
          ���������� ������ �������.
          \return ������ �������
        */
        int size() const;

        /*!
          ���������� �������� � ������� �� ���������� �������.
          \param index ������ � �������
          \return �������� �� �������.
        */
        Point get(const int index) const;

        /*!
          ������������� ��������� �������� �� ���������� �������. 
          \param index ������ � �������
          \param point ��������
        */
        void set(const int index, const Point& point);

    private:
        int arraySize;

        Point * arrayData;
    };
}

#endif