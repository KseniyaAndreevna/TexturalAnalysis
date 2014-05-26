#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "Point.h"

namespace TexturalAnalysis {
    class PointArray {
    public:
        PointArray(const int size);

        ~PointArray();

        int size() const;

        Point get(const int index) const;

        void set(const int index, const Point& point);

    private:
        int arraySize;

        Point * arrayData;
    };
}

#endif