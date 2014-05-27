#ifndef HIRST_VALUES_H
#define HIRST_VALUES_H

namespace TexturalAnalysis {
    /*!
      Структура для хранения коэффициента Хёрста и свободного коэффициента прямой, приближающей точки.
    */
    struct HirstValues {
        /*!
          Коэффициент Хёрста.
        */
        double coefficient;

        /*!
          Свободный коэффициент прямой, приближающей точки.
        */
        double offset;
    };
}

#endif