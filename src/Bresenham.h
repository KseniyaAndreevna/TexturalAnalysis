#ifndef BRESENHAM_H
#define BRESENHAM_H

#include <vector>

#include "Image.h"

namespace TexturalAnalysis {
    class Bresenham {
    public:
        static std::vector<double> determinePoints(const Image& image, const int x1, const int y1, const int x2, const int y2);
    };
}

#endif