#ifndef PUT_OK_GENETIC_H
#define PUT_OK_GENETIC_H

#include "../Shared/InputData.h"
#include <vector>
#include <iostream>
#include "Random.h"
#include "../Greedy/Greedy.h"


using namespace std;

class Genetic {
private:
    InputData *input;

    int processAt(int index);

    void print(int *genotype);

    int *generateRandomLocalPopulation();

    int **generateGreedyPopulation();

    int **generateRandomPopulation();

    int adaptationScore(int *genotype);

    int **selection(int **population);

    int **crossover(int *firstGenotype, int *secondGenotype);

    void mutation(int **population);

    void breeding(int **population);

    pair<int,int> findBest(int **population);

    Random *random;
    Greedy *greedy;

    int *bestLocalPopulation;
public:
    Genetic(InputData *inputData);

    int getResult();

    int *getPopulation();

    void visualize(ostream& output);

};


#endif //PUT_OK_GENETIC_H
