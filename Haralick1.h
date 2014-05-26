#ifndef HARALICK1_H
#define HARALICK1_H

#include "Image.h"

namespace TexturalAnalysis {
    class Haralick1 {
    public:
        static Image apply(const Image& image);

    private:
        static double haralick1(const Image& image, const int imageI, const int imageJ);
    };
}

#endif