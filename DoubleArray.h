#ifndef DOUBLE_ARRAY_H
#define DOUBLE_ARRAY_H

namespace TexturalAnalysis {
    class DoubleArray {
    public:
        DoubleArray(const int size);

        ~DoubleArray();

        int size() const;

        double get(const int index);

        void set(const int index, double value);

    private:
        int arraySize;

        double * arrayData;
    };
}

#endif