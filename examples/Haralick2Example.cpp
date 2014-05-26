#include <Image.h>

#include <Haralick2.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Haralick2::apply(image);

    return 0;
}