#ifndef ENTROPY_H
#define ENTROPY_H

#include "Image.h"

namespace TexturalAnalysis {
    class Entropy {
    public:
        static Image apply(const Image& image);

    private:
        static double entropy(const Image& image, const int imageI, const int imageJ);
    };
}

#endif