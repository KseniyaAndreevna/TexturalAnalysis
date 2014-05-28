#include "Bresenham.h"

using namespace TexturalAnalysis;

std::vector<double> Bresenham::determinePoints(
  const Image& image, 
  const int x1,
  const int y1,
  const int x2, 
  const int y2)
{
    const int deltaX = std::abs(x2 - x1);
    const int deltaY = std::abs(y2 - y1);

    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;

    const int N = deltaX > deltaY ? deltaX + 1 : deltaY + 1;

    std::vector<double> intensivities;

    intensivities.push_back(image.get(y2, x2));

    int error = deltaX - deltaY;

    double currentX = x1;
    double currentY = y1;

    while ((currentX != x2) || (currentY != y2)) {
        intensivities.push_back(image.get(currentY, currentX));

        int error2 = error * 2;

        if (error2 > -deltaY) {
            error -= deltaY;

            currentX += signX;
        }

        if (error2 < deltaX) {
          error += deltaX;

          currentY += signY;
        }
    }

    return intensivities;
}   