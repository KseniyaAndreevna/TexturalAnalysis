#ifndef MOMENT_H
#define MOMENT_H

#include "Image.h"

namespace TexturalAnalysis {
    class Moment {
    public:
        static Image apply(const Image& image);

    private:
        static double moment(const Image& image, const int imageI, const int imageJ);
    };
}

#endif