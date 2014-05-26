#ifndef HARALICK3_H
#define HARALICK3_H

#include "Image.h"

namespace TexturalAnalysis {
    class Haralick3 {
    public:
        static Image apply(const Image& image);

    private:
        static double haralick3(const Image& image, const int imageI, const int imageJ);
    };
}

#endif