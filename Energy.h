#ifndef ENERGY_H
#define ENERGY_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
       ласс содержит функционал, св€занный с текстурным признаком "Ёнерги€".
    */
    class Energy {
    public:
        /*! 
          ѕримен€ет текстурный признак "Ёнерги€" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применени€ текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double energy(const Image& image, const int imageI, const int imageJ);
    };
}

#endif