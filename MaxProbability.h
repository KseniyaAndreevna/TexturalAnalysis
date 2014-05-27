#ifndef MAXPROBABILITY_H
#define MAXPROBABILITY_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      ����� �������� ����������, ��������� � ���������� ��������� "������������ �����������".
    */
    class MaxProbability {
    public:
        /*! 
          ��������� ���������� ������� "������������ �����������" � ����������� �����������.
          \param image ������������� ����������� �����������
          \return ��������� ���������� ����������� ��������
        */
        static Image apply(const Image& image);

    private:
        static double maxProbability(const Image& image, const int imageI, const int imageJ);
    };
}

#endif