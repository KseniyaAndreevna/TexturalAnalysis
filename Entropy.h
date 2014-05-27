#ifndef ENTROPY_H
#define ENTROPY_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком "Энтропия".
    */
    class Entropy {
    public:
        /*! 
          Применяет текстурный признак "Энтропия" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double entropy(const Image& image, const int imageI, const int imageJ);
    };
}

#endif