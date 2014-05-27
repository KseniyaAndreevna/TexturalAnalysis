#ifndef HARALICK4_H
#define HARALICK4_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком 
      "Неоднородность длины серий".
    */
    class Haralick4 {
    public:
        /*! 
          Применяет текстурный признак "Неоднородность длины серий" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick4(const Image& image, const int I, const int J);
    };
}

#endif