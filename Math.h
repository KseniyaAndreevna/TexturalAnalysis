#ifndef MATH_H
#define MATH_H

namespace TexturalAnalysis {
    /*!
      Класс, содержащий математические функции.
    */
    class Math {
    public:
        /*!
          Возвращает натуральный логарифм от указанного аргумента.
          \param x аргумент
          \return натуральный логарифм от аргумента
        */
        static double ln(double x);
    };
}

#endif