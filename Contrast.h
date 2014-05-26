#ifndef CONTRAST_H
#define CONTRAST_H

#include "Image.h"

namespace TexturalAnalysis {
    class Contrast {
    public:
        static Image apply(const Image& image);

    private:
        static double contrast(const Image& image, const int imageI, const int imageJ);
    };
}

#endif