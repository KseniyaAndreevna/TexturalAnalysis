#ifndef MOMENT_H
#define MOMENT_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком "Обратный момент".
    */
    class Moment {
    public:
        /*! 
          Применяет текстурный признак "Обратный момент" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double moment(const Image& image, const int imageI, const int imageJ);
    };
}

#endif