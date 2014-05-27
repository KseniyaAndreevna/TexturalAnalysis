#ifndef HARALICK5_H
#define HARALICK5_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком 
      "Доля изображения в сериях".
    */
    class Haralick5 {
    public:
        /*! 
          Применяет текстурный признак "Доля изображения в сериях" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick5(const Image& image, const int I, const int J);
    };
}

#endif