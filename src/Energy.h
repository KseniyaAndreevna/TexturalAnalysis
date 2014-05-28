#ifndef ENERGY_H
#define ENERGY_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
      Класс содержит функционал, связанный с текстурным признаком "Энергия".
    */
    class Energy {
    public:
        /*! 
          Применяет текстурный признак "Энергия" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применения текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double energy(const Image& image, const int imageI, const int imageJ);
    };
}

#endif