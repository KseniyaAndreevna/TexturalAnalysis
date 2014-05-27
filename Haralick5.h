#ifndef HARALICK5_H
#define HARALICK5_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
       ласс содержит функционал, св€занный с текстурным признаком 
      "ƒол€ изображени€ в сери€х".
    */
    class Haralick5 {
    public:
        /*! 
          ѕримен€ет текстурный признак "ƒол€ изображени€ в сери€х" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применени€ текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double haralick5(const Image& image, const int I, const int J);
    };
}

#endif