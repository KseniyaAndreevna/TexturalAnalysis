#ifndef HARALICK4_H
#define HARALICK4_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
       ласс содержит функционал, св€занный с текстурным признаком 
      "Ќеоднородность длины серий".
    */
    class Haralick4 {
    public:
        /*! 
          ѕримен€ет текстурный признак "Ќеоднородность длины серий" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применени€ текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick4(const Image& image, const int I, const int J);
    };
}

#endif