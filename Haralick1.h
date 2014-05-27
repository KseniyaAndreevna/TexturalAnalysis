#ifndef HARALICK1_H
#define HARALICK1_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
       ласс содержит функционал, св€занный с текстурным признаком 
      "ќбратные моменты увеличены при коротких сери€х".
    */
    class Haralick1 {
    public:
        /*! 
          ѕримен€ет текстурный признак "ќбратные моменты увеличены при коротких сери€х" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применени€ текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick1(const Image& image, const int imageI, const int imageJ);
    };
}

#endif