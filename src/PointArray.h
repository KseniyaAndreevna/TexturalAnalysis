#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "Point.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит массив геометрических точек.
    */
    class PointArray {
    public:
        /*!
          Создает массив геометрических точек заданного размера.
          \param size размер массива
        */
        PointArray(const int size);

        /*!
          Создается массив на основе указанного массива.
          \param pointArray массив
        */
        PointArray(const PointArray& pointArray);

        /*!
          Удаляет созданный массив.
        */
        ~PointArray();

        /*!
          Присваивает содержимое указанного массива.
          \param pointArray массив
          \return ссылку на текущий объект
        */
        PointArray& operator=(const PointArray& pointArray);

        /*!
          Возвращает размер массива.
          \return размер массива
        */
        int size() const;

        /*!
          Возвращает значение в массиве по указанному индексу.
          \param index индекс в массиве
          \return значение по индексу.
        */
        Point get(const int index) const;

        /*!
          Устанавливает указанное значение по указанному индексу. 
          \param index индекс в массиве
          \param point значение
        */
        void set(const int index, const Point& point);

    private:
        int arraySize;

        Point * arrayData;
    };
}

#endif