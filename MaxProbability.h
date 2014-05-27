#ifndef MAXPROBABILITY_H
#define MAXPROBABILITY_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком "Максимальная вероятность".
    */
    class MaxProbability {
    public:
        /*! 
          Применяет текстурный признак "Максимальная вероятность" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double maxProbability(const Image& image, const int imageI, const int imageJ);
    };
}

#endif