#ifndef HARALICK1_H
#define HARALICK1_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком 
      "Обратные моменты увеличены при коротких сериях".
    */
    class Haralick1 {
    public:
        /*! 
          Применяет текстурный признак "Обратные моменты увеличены при коротких сериях" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick1(const Image& image, const int imageI, const int imageJ);
    };
}

#endif