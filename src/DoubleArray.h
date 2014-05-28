#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

namespace TexturalAnalysis {
    /*!
      Класс содержит массив вещественных чисел.
    */
    class DoubleArray {
    public:
        /*!
          Создает массив вещественных чисел указанного размера.
          \param size размер массива
        */
        DoubleArray(const int size);

        /*!
          Создается массив на основе указанного массива.
          \param doubleArray массив
        */
        DoubleArray(const DoubleArray& doubleArray);

        /*!
          Удаляет созданный массив.
        */
        ~DoubleArray();

        /*!
          Присваивает содержимое указанного массива.
          \param doubleArray массив
          \return ссылку на текущий объект
        */
        DoubleArray& operator=(const DoubleArray& doubleArray);

        /*!
          Возвращает размер массива.
          \return размер массива.
        */
        int size() const;

        /*!
         Возвращает значение массива по указанному индексу.
         \param index индекс в массиве
         \return значение по индексу.
        */
        double get(const int index) const;

        /*!
          Устанавливает указанное значение по указанному индексу.
          \param index индекс в массиве
          \param value значение
        */
        void set(const int index, double value);

    private:
        int arraySize;

        double * arrayData;
    };
}

#endif