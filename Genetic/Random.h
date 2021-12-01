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
    mersenne_twister_engine<uint_fast32_t, 32, 624, 397, 31, 0x9908b0dfUL, 11, 0xffffffffUL, 7, 0x9d2c5680UL, 15, 0xefc60000UL, 18, 1812433253UL> gen;
    uniform_int_distribution<int> processDistr;
    uniform_int_distribution<int> processorDistr;
    uniform_int_distribution<int> percentageDistr;
};


#endif //PUT_OK_RANDOM_H
