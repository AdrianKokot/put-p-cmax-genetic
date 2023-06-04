#ifndef PUT_OK_RANDOM_H
#define PUT_OK_RANDOM_H

#include <random>

using namespace std;

class Random {
public:
    Random(int processCount, int processorCount);

    int process();

    int processor();

    int percentage();

private:
    mt19937 gen;
    uniform_int_distribution<int> processDistr;
    uniform_int_distribution<int> processorDistr;
    uniform_int_distribution<int> percentageDistr;
    int processCount;
    int processorCount;
};


#endif //PUT_OK_RANDOM_H
