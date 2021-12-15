#include <iostream>
#include "Greedy/Greedy.h"
#include "Shared/Reader.h"
#include "Genetic/Genetic.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        auto inputData = Reader::readInput(argc, argv);

        auto genetic = new Genetic(inputData);
        int geneticResult = genetic->getResult();

        cout << geneticResult;

        fstream output;

        auto logFileName = inputData->fileName.replace(inputData->fileName.length() - 4, 9, "_best.txt");

        output.open(logFileName,ios::in);

        int bestFromFile;
        output >> bestFromFile;

        if (geneticResult < bestFromFile) {
            output.close();

            output.open(logFileName, ios::out | ios::trunc);
            output << geneticResult << endl << endl;

            genetic->visualize(output);
        }

    } catch (const char *msg) {
        cout << msg;
    }

    return 0;
}
