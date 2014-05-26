#include <Image.h>

#include <MaxProbability.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::MaxProbability::apply(image);

    return 0;
}