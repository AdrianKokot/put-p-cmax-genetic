#ifndef PUT_OK_GENETIC_H
#define PUT_OK_GENETIC_H

#include "../Shared/InputData.h"

class Genetic {
private:
    InputData *input;
    int greedyResult;

public:
    Genetic(InputData *, int);

    int getResult();

};


#endif //PUT_OK_GENETIC_H
