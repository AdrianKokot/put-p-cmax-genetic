#include "Reader.h"

const string Reader::defaultFile = "../instances/2m50.txt";

InputData *Reader::readInput(int argc, char **argv) {
    fstream input;

    input.open(argc > 1 ? argv[1] : Reader::defaultFile, ios::in);

    if (!input) {
        throw "File doesn't exist.";
    }

    int processors, processes;

    input >> processors >> processes;

    InputData *inputData = new InputData(processors, processes);

    inputData->fileName = argc > 1 ? argv[1] : Reader::defaultFile;

    for (int i = 0; i < inputData->processes; i++) {
        input >> (*inputData)[i];
    }

    return inputData;
}
