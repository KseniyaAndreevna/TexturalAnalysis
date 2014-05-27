#ifndef HARALICK4_H
#define HARALICK4_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      ����� �������� ����������, ��������� � ���������� ��������� 
      "�������������� ����� �����".
    */
    class Haralick4 {
    public:
        /*! 
          ��������� ���������� ������� "�������������� ����� �����" � ����������� �����������.
          \param image ������������� ����������� �����������
          \return ��������� ���������� ����������� ��������
        */
        static Image apply(const Image& image);

    private:
        static double haralick4(const Image& image, const int I, const int J);
    };
}

#endif