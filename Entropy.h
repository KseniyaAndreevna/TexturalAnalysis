#ifndef ENTROPY_H
#define ENTROPY_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
       ласс содержит функционал, св€занный с текстурным признаком "Ёнтропи€".
    */
    class Entropy {
    public:
        /*! 
          ѕримен€ет текстурный признак "Ёнтропи€" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применени€ текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double entropy(const Image& image, const int imageI, const int imageJ);
    };
}

#endif