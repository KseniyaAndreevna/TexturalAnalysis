#ifndef RS_H
#define RS_H

#include "Image.h"

#include "PointArray.h"

#include "HirstValues.h"

namespace TexturalAnalysis {
    class RS {
    public:
        static PointArray calculatePoints(const Image& image, const int x1, const int y1, const int x2, const int y2);

        static HirstValues calculateHirstValues(const PointArray& rsPoints);
    };
}

#endif