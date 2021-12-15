#ifndef PUT_OK_GREEDY_H
#define PUT_OK_GREEDY_H

#include "GreedyStack.h"
#include "../Shared/InputData.h"

class Greedy {
private:
    InputData *input;
public:
    Greedy(InputData *);

    int getResult(int step = 0);

    int *getPopulation(int step = 0);
};

#endif //PUT_OK_GREEDY_H
