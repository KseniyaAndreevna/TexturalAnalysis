#include <Image.h>

#include <Haralick1.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Haralick1::apply(image);

    return 0;
}