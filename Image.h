#ifndef IMAGE_H
#define IMAGE_H

namespace TexturalAnalysis {
    /*!
       ласс, хран€щий информацию об изображении в виде матрицы вещественных чисел соответствующих интенсивност€м пикселей.
    */
    class Image {
    public:
        /*! 
          —оздаетс€ матрица, задающа€ изображение указанного размера. «аполнена нул€ми.
          \param size размер матрицы
        */
        Image(const int size);

        /*!
          —оздаетс€ матрица, задающа€ изображени€ указанных размеров высоты и ширины. «аполнена нул€ми.
          \param height высота матрицы
          \param width ширина матрицы
        */
        Image(const int height, const int width);

        /*!
          ”дал€ет созданную матрицу.
        */
        ~Image();

        /*!
          ¬озвращает высоту матрицы.
          \return высоту массима
        */
        int height() const;

        /*!
          ¬озвращает ширину матрицы. 
          \return ширину массима
        */
        int width() const;

        /*!
          ¬озвращает меньшую сторону матрицы, в случае пр€моугольной матрицы.
          \return минимум между высотой и шириной
        */
        int size() const;

        /*!
          ”станавливает по указанным индексам указанное значение.
          \param i индекс строки в матрице
          \param j индекс столбца в матрице
          \param value значение.
        */
        void set(const int i, const int j, const double value);

        /*!
          ¬озвращает значение в матрице по указанным индексам.
          \param i индекс строки в матрице
          \param j индекс столбца в матрице
          \return значение по индексам
        */
        double get(const int i, const int j) const;

        /*!
          ¬озвращает мининальное значение в матрице.
          \return минимальное значение.
        */
        double getMin() const;

        /*!
          ¬озвращает максимальное значение в матрице.
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