#ifndef IMAGE_H
#define IMAGE_H

namespace TexturalAnalysis {
    /*!
      �����, �������� ���������� �� ����������� � ���� ������� ������������ ����� ��������������� �������������� ��������.
    */
    class Image {
    public:
        /*! 
          ��������� �������, �������� ����������� ���������� �������. ��������� ������.
          \param size ������ �������
        */
        Image(const int size);

        /*!
          ��������� �������, �������� ����������� ��������� �������� ������ � ������. ��������� ������.
          \param height ������ �������
          \param width ������ �������
        */
        Image(const int height, const int width);

        /*!
          ������� ��������� �������.
        */
        ~Image();

        /*!
          ���������� ������ �������.
          \return ������ �������
        */
        int height() const;

        /*!
          ���������� ������ �������. 
          \return ������ �������
        */
        int width() const;

        /*!
          ���������� ������� ������� �������, � ������ ������������� �������.
          \return ������� ����� ������� � �������
        */
        int size() const;

        /*!
          ������������� �� ��������� �������� ��������� ��������.
          \param i ������ ������ � �������
          \param j ������ ������� � �������
          \param value ��������.
        */
        void set(const int i, const int j, const double value);

        /*!
          ���������� �������� � ������� �� ��������� ��������.
          \param i ������ ������ � �������
          \param j ������ ������� � �������
          \return �������� �� ��������
        */
        double get(const int i, const int j) const;

        /*!
          ���������� ����������� �������� � �������.
          \return ����������� ��������.
        */
        double getMin() const;

        /*!
          ���������� ������������ �������� � �������.
          \return ������������ ��������.
        */ 
        double getMax() const;

    private:
        void init(const int height, const int width);

        double ** imageMatrix;

        int imageWidth;

        int imageHeight;
    };
}

#endif