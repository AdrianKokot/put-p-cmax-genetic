#include <iostream>
#include "Greedy/Greedy.h"
#include "Shared/Reader.h"
#include "Genetic/Genetic.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        auto inputData = Reader::readInput(argc, argv);

        auto greedy = new Greedy(inputData);
        int greedyResult = greedy->getResult();

        auto genetic = new Genetic(inputData, greedyResult);
        int geneticResult = genetic->getResult();

        cout << "|\tGreedy\t|\tGenetic\t|\n|\t------\t|\t-------\t|\n|\t" << greedyResult << "\t|\t" << geneticResult << "\t|\n";

    } catch (string msg) {
        cout << msg;
    }

    return 0;
}
