#include <Image.h>

#include <Haralick4.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Haralick4::apply(image);

    return 0;
}