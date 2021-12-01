#ifndef PUT_OK_GENETIC_H
#define PUT_OK_GENETIC_H

#include "../Shared/InputData.h"
#include <vector>
#include <iostream>
#include "Random.h"

using namespace std;

class Genetic {
private:
    InputData *input;

    int processAt(int index);

    pair<int, int> processNotation(int index);

    void print(vector<pair<int, int>> *localPopulation);

    void print(int *genotype);

    vector<pair<int, int>> *generateRandomLocalPopulation();

    vector<pair<int, int>> **generateRandomPopulation();

    int *encode(vector<pair<int, int>> *localPopulation);

    vector<pair<int, int>> *decode(int *genotype);

    int adaptationScore(int *genotype);

    vector<pair<int, int>> **selection(vector<pair<int, int>> **population);

    int **crossover(int *firstGenotype, int *secondGenotype);

    void mutation(int **population);

    Random *random;

public:
    Genetic(InputData *inputData);

    int getResult();

};


#endif //PUT_OK_GENETIC_H
