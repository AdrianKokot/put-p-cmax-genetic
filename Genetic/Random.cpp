#include "Random.h"

Random::Random(int processCount, int processorCount) {
    random_device dev;
    this->gen = (mt19937(dev()));
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