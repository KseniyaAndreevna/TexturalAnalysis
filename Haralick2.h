#ifndef HARALICK2_H
#define HARALICK2_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
       ласс содержит функционал, св€занный с текстурным признаком 
      "ћоменты увеличены при длинных сери€х".
    */
    class Haralick2 {
    public:
        /*! 
          ѕримен€ет текстурный признак "ћоменты увеличены при длинных сери€х" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применени€ текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick2(const Image& image, const int imageI, const int imageJ);
    };
}

#endif