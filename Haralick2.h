#ifndef HARALICK2_H
#define HARALICK2_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком 
      "Моменты увеличены при длинных сериях".
    */
    class Haralick2 {
    public:
        /*! 
          Применяет текстурный признак "Моменты увеличены при длинных сериях" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick2(const Image& image, const int imageI, const int imageJ);
    };
}

#endif