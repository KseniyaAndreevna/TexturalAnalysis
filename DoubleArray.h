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
          Удаляет созданный массив.        
        */
        ~DoubleArray();

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
        double get(const int index);

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