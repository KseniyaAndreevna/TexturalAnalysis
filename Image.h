#ifndef IMAGE_H
#define IMAGE_H

namespace TexturalAnalysis {
    class Image {
    public:
        Image(const int size);

        Image(const int height, const int width);

        ~Image();

        int height() const;

        int width() const;

        int size() const;

        void set(const int i, const int j, const double value);

        double get(const int i, const int j) const;

        double getMin() const;

        double getMax() const;

    private:
        void init(const int height, const int width);

        double ** imageMatrix;

        int imageWidth;

        int imageHeight;
    };
}

#endif