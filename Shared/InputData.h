#ifndef PUT_OK_INPUTDATA_H
#define PUT_OK_INPUTDATA_H

#include <iostream>

class InputData {

private:
    int *_arr;

public:
    int processors;
    int processes;

    InputData(int, int);

    int length();

    int &operator[](int);

    std::string fileName;
};

#endif //PUT_OK_INPUTDATA_H
