#include <Image.h>

#include <Haralick5.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Haralick5::apply(image);

    return 0;
}