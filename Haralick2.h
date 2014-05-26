#ifndef HARALICK2_H
#define HARALICK2_H

#include "Image.h"

namespace TexturalAnalysis {
    class Haralick2 {
    public:
        static Image apply(const Image& image);

    private:
        static double haralick2(const Image& image, const int imageI, const int imageJ);
    };
}

#endif