#include "RS.h"

#include <cmath>

#include <vector>

#include "Math.h"

#include "Bresenham.h"

using namespace TexturalAnalysis;

std::vector<Point> RS::calculatePoints(const Image& image, const int x1, const int y1, const int x2, const int y2) {
    std::vector<double> h = Bresenham::determinePoints(image, x1, y1, x2, y2);

    std::vector<double> H(h.size());

    H[0] = h[0];

    for (int i = 1; i < h.size(); i++) {
        H[i] = H[i - 1] + h[i];
    }

    std::vector<double> averageH(H.size());

    for (int i = 0; i < H.size(); i++) {
        averageH[i] = H[i] / (i + 1);
    }

    std::vector<double> r(h.size());

    r[0] = 0;

    for (int n = 1; n < h.size(); n++) {
        for (int k = 0; k < n; k++) {
            double sum = 0;

            double Max = 0;
            double Min = 0;

            for (int i = 0; i <= k; i++) {
                sum += h[i] - averageH[n];

                if (sum < Min) { Min = sum; }

                if (sum > Max) { Max = sum; }

            }

            r[n] = Max - Min;
        }
    }

    std::vector<double> s(h.size());

    for (int n = 0; n < h.size(); n++) {
        double sum = 0;

        for (int i = 0; i < n; i++){
            sum += pow(h[i] - averageH[n], 2.0);
        }

        s[n] = sqrt(sum / (n + 1));
    }

    std::vector<double> rs(h.size());

    rs[0] = 0;

    for (int i = 1; i < r.size(); i++) {
        rs[i] = r[i] / s[i];
    }

    std::vector<Point> points(rs.size());

    for (int i = 1; i < rs.size(); i++) {
        double pointX = Math::ln(i);
        double pointY = Math::ln(rs[i]);

        points[i] = Point(pointX, pointY);
    }

    return points;
}

HirstValues RS::calculateHirstValues(const std::vector<Point>& rsPoints) {
    double c1 = 0;
    double c2 = 0;
    double g1 = 0;
    double g2 = 0;

    for (int i = 0; i < rsPoints.size(); i++) {
        Point point = rsPoints[i];

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