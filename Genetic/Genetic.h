#ifndef PUT_OK_GENETIC_H
#define PUT_OK_GENETIC_H

#include "../Shared/InputData.h"
#include <vector>
#include <random>
#include <iostream>

using namespace std;

class Genetic {
private:
    InputData *input;

    int processAt(int index);

    pair<int, int> processNotation(int index);

    void print(vector<pair<int, int>> *localPopulation);

    void print(int *genotype);

    vector<pair<int, int>> *generateRandomLocalPopulation();

    int *encode(vector<pair<int, int>> *localPopulation);

    vector<pair<int, int>> *decode(int *genotype);

public:
    Genetic(InputData *inputData);

    int getResult();
};


#endif //PUT_OK_GENETIC_H
