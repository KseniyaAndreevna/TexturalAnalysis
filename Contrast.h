#ifndef CONTRAST_H
#define CONTRAST_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком "Контраст".
    */
    class Contrast {
    public:
        /*! 
          Применяет текстурный признак "Контраст" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double contrast(const Image& image, const int imageI, const int imageJ);
    };
}

#endif