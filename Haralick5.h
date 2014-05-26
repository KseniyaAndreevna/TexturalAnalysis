#ifndef HARALICK5_H
#define HARALICK5_H

#include "Image.h"

namespace TexturalAnalysis {
    class Haralick5 {
    public:
        static Image apply(const Image& image);

    private:
        static double haralick5(const Image& image, const int I, const int J);
    };
}

#endif