#include "Random.h"
#include <time.h>

Random::Random(int processCount, int processorCount) {
    this->gen = (mt19937(random_device()()));
    this->gen.seed(time(NULL));

    this->processDistr = uniform_int_distribution<>(0, processCount - 1);
    this->processorDistr = uniform_int_distribution<>(0, processorCount - 1);
    this->percentageDistr = uniform_int_distribution<>(0, 100);
}

int Random::percentage() {
    return percentageDistr(this->gen);
}

int Random::process() {
    return processDistr(this->gen);
}

int Random::processor() {
    return processorDistr(this->gen);
}