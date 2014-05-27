#include "RS.h"

#include <cmath>

#include "DoubleArray.h"

#include "Math.h"

using namespace TexturalAnalysis;

PointArray RS::calculatePoints(const Image& image, const int x1, const int y1, const int x2, const int y2) {
  const int deltaX = std::abs(x2 - x1);
  const int deltaY = std::abs(y2 - y1);

    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;

    const int N = deltaX > deltaY ? deltaX + 1 : deltaY + 1;

    DoubleArray h(N);

    int count = 0;

    h.set(count, image.get(y2, x2));

    int error = deltaX - deltaY;

    double currentX = x1;
    double currentY = y1;

    while ((currentX != x2) || (currentY != y2)) {
        count++;

        h.set(count, image.get(currentY, currentX));

        int error2 = error * 2;

        if(error2 > -deltaY) {
            error -= deltaY;

            currentX += signX;
        }

        if(error2 < deltaX) {
            error += deltaX;

            currentY += signY;
        }
    }

    DoubleArray H(h.size());

    H.set(0, h.get(0));

    for (int i = 1; i < h.size(); i++) {
        H.set(i, H.get(i - 1) + h.get(i));
    }

    DoubleArray averageH(H.size());

    for (int i = 0; i < H.size(); i++) {
        averageH.set(i, H.get(i) / (i + 1));
    }

    DoubleArray r(h.size());

    r.set(0, 0);

    for (int n = 1; n < h.size(); n++) {
        for (int k = 0; k < n; k++) {
            double sum = 0;

            double Max = 0;
            double Min = 0;

            for (int i = 0; i <= k; i++) {
                sum += h.get(i) - averageH.get(n);

                if (sum < Min) { Min = sum; }

                if (sum > Max) { Max = sum; }

            }

            r.set(n, Max - Min);
        }
    }

    DoubleArray s(h.size());

    for (int n = 0; n < h.size(); n++) {
        double sum = 0;

        for (int i = 0; i < n; i++){
            sum += pow((h.get(i) - averageH.get(n)), 2.0);
        }

        s.set(n, sqrt(sum / (n + 1)));
    }

    DoubleArray rs(h.size());

    rs.set(0, 0);

    for (int i = 1; i < r.size(); i++) {
        rs.set(i, r.get(i) / s.get(i));
    }

    PointArray points(rs.size());

    for (int i = 1; i < rs.size(); i++) {
        double pointX = Math::ln(i);
        double pointY = Math::ln(rs.get(i));

        points.set(i, Point(pointX, pointY));
    }

    return points;
}

HirstValues RS::calculateHirstValues(const PointArray& rsPoints) {
    double c1 = 0;
    double c2 = 0;
    double g1 = 0;
    double g2 = 0;

    for (int i = 0; i < rsPoints.size(); i++) {
        Point point = rsPoints.get(i);

        c1 += pow(point.x(), 2.0);
        c2 += point.x();
        g1 += point.x() * point.y();
        g2 += point.y();
    }

    int size = rsPoints.size();

    HirstValues hirstValues;
    hirstValues.coefficient = ((size - 1) * g1 - c2 * g2) / ((size - 1) * c1 - pow(c2, 2.0));
    hirstValues.offset = (1.0 / (size - 1)) * (g2 - hirstValues.coefficient * c2);

    return hirstValues;
}