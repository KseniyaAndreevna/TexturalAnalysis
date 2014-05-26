#ifndef ENERGY_H
#define ENERGY_H

#include "Image.h"

namespace TexturalAnalysis {
    class Energy {
    public:
        static Image apply(const Image& image);

    private:
        static double energy(const Image& image, const int imageI, const int imageJ);
    };
}

#endif