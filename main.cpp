#include <iostream>
#include "Greedy/Greedy.h"
#include "Shared/Reader.h"
#include "Genetic/Genetic.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        auto inputData = Reader::readInput(argc, argv);

        // auto greedy = new Greedy(inputData);
        // int greedyResult = greedy->getResult();

        auto genetic = new Genetic(inputData);
        int geneticResult = genetic->getResult();

        // cout << "Greedy:  " << greedyResult << "\nGenetic: " << geneticResult;

        cout << geneticResult;

    } catch (const char* msg) {
        cout << msg;
    }

    return 0;
}
