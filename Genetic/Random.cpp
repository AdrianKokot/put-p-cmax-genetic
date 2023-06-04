#include "Random.h"
#include <time.h>
#include <iostream>

Random::Random(int processCount, int processorCount)
{
  // this->gen = (mt19937(random_device()()));
  // this->gen.seed(time(NULL));
  this->gen = mt19937(42);
  this->processDistr = uniform_int_distribution<>(0, processCount - 1);
  this->processorDistr = uniform_int_distribution<>(0, processorCount - 1);
  this->percentageDistr = uniform_int_distribution<>(0, 100);
  this->processCount = processCount;
  this->processorCount = processorCount;
}

int Random::percentage()
{
  srand(1685223251);
  return rand() % 100;
  // return percentageDistr(this->gen);
}

int Random::process()
{
  srand(1665223251);
  return rand() % processCount;
  // return processDistr(this->gen);
}

int Random::processor()
{
  srand(1675223251);
  return rand() % processorCount;
  // return processorDistr(this->gen);
}