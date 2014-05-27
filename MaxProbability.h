#ifndef MAXPROBABILITY_H
#define MAXPROBABILITY_H

#include "Image.h"

namespace TexturalAnalysis {
    /*!
       ласс содержит функционал, св€занный с текстурным признаком "ћаксимальна€ веро€тность".
    */
    class MaxProbability {
    public:
        /*! 
          ѕримен€ет текстурный признак "ћаксимальна€ веро€тность" к переданному изображению.
          \param image соответствует переданному изображению
          \return результат применени€ текстурного признака
        */
        static Image apply(const Image& image);

    private:
        static double maxProbability(const Image& image, const int imageI, const int imageJ);
    };
}

#endif