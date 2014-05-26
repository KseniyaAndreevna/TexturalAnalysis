#include <Image.h>

#include <Haralick3.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Haralick3::apply(image);

    return 0;
}