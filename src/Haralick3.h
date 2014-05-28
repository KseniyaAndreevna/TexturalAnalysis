#ifndef HARALICK3_H
#define HARALICK3_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком 
      "Неоднородность яркости".
    */
    class Haralick3 {

    public:
        /*! 
          Применяет текстурный признак "Неоднородность яркости" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick3(const Image& image, const int imageI, const int imageJ);
    };
}

#endif