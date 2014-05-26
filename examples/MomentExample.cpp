#include <Image.h>

#include <Moment.h>

int main(int argc, char ** argv) {
    TexturalAnalysis::Image image(100, 100);

    TexturalAnalysis::Moment::apply(image);

    return 0;
}