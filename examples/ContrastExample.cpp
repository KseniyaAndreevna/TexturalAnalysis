#include <Image.h>

#include <Contrast.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Contrast::apply(image);

    return 0;
}