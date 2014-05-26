#ifndef POINT_H
#define POINT_H

namespace TexturalAnalysis {
    class Point {
    public:
        Point();

        Point(const double x, const double y);

        double x() const;

        double y() const;

    private:
        double pointX;
        double pointY;
    };
}

#endif