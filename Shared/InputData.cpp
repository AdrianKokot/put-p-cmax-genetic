#include "InputData.h"

InputData::InputData(int processors, int processes) {
    this->processors = processors;
    this->processes = processes;
    this->_arr = new int[this->processes]{0};
}

int InputData::length() {
    return this->processes;
}

int &InputData::operator[](int index) {
    return this->_arr[index];
}