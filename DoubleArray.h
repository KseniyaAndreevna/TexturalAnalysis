#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

namespace TexturalAnalysis {
    /*!
      ����� �������� ������ ������������ �����.
    */
    class DoubleArray {
    public:
        /*!
          ������� ������ ������������ ����� ���������� �������.
          \param size ������ �������
        */
        DoubleArray(const int size);

        /*!
          ������� ��������� ������.        
        */
        ~DoubleArray();

        /*!
          ���������� ������ �������.
          \return ������ �������.
        */
        int size() const;

        /*!
         ���������� �������� ������� �� ���������� �������. 
         \param index ������ � �������
         \return �������� �� �������.
        */
        double get(const int index);

        /*!
          ������������� ��������� �������� �� ���������� �������. 
          \param index ������ � �������
          \param value ��������
        */
        void set(const int index, double value);

    private:
        int arraySize;

        double * arrayData;
    };
}

#endif