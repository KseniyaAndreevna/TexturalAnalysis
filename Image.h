#ifndef IMAGE_H
#define IMAGE_H

namespace TexturalAnalysis {
    /*!
      Класс, хранящий информацию об изображении в виде матрицы вещественных чисел соответствующих интенсивностям пикселей.
    */
    class Image {
    public:
        /*! 
          Создается матрица, задающая изображение указанного размера. Заполнена нулями.
          \param size размер матрицы
        */
        Image(const int size);

        /*!
          Создается матрица, задающая изображения указанных размеров высоты и ширины. Заполнена нулями.
          \param height высота матрицы
          \param width ширина матрицы
        */
        Image(const int height, const int width);

        /*!
          Удаляет созданную матрицу.
        */
        ~Image();

        /*!
          Возвращает высоту матрицы.
          \return высоту массима
        */
        int height() const;

        /*!
          Возвращает ширину матрицы. 
          \return ширину массима
        */
        int width() const;

        /*!
          Возвращает меньшую сторону матрицы, в случае прямоугольной матрицы.
          \return минимум между высотой и шириной
        */
        int size() const;

        /*!
          Устанавливает по указанным индексам указанное значение.
          \param i индекс строки в матрице
          \param j индекс столбца в матрице
          \param value значение.
        */
        void set(const int i, const int j, const double value);

        /*!
          Возвращает значение в матрице по указанным индексам.
          \param i индекс строки в матрице
          \param j индекс столбца в матрице
          \return значение по индексам
        */
        double get(const int i, const int j) const;

        /*!
          Возвращает мининальное значение в матрице.
          \return минимальное значение.
        */
        double getMin() const;

        /*!
          Возвращает максимальное значение в матрице.
          \return максимальное значение.
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