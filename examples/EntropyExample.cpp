#include <Image.h>

#include <Entropy.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Entropy::apply(image);

    return 0;
}