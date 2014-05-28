#include "Math.h"

#define _USE_MATH_DEFINES
#include <cmath>

using namespace TexturalAnalysis;

double Math::ln(double x) {
    return log10(x) / log10(M_E);
}