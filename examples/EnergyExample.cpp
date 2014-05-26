#include <Image.h>

#include <Energy.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Energy::apply(image);

    return 0;
}