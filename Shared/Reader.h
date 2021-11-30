#ifndef PUT_OK_READER_H
#define PUT_OK_READER_H

#include <iostream>
#include <fstream>
#include "InputData.h"

using namespace std;

class Reader {
private:
    static const string defaultFile;

public:
    static InputData *readInput(int, char **);
};

#endif //PUT_OK_READER_H
