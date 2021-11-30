#include <iostream>
#include "Greedy.cpp"
#include "../Shared/Reader.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        auto inputData = Reader::readInput(argc, argv);

        auto greedy = new Greedy(inputData);

        cout << greedy->getResult() << endl;

    } catch (string msg) {
        cout << msg;
    }

    return 0;
}
