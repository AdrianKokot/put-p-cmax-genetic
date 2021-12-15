#include "GreedyStack.h"

GreedyStack::GreedyStack(int processorNum, int processesNum) {
    this->stack = new pair<int, int>[processorNum];
    this->stackLength = processorNum;
    this->listWithProcesses = new vector<int>[processorNum];
    this->population = new int[processesNum];

    for (int i = 0; i < this->stackLength; i++) {
        this->stack[i] = pair<int, int>(i, 0);
    }
}

int GreedyStack::length() {
    return this->stackLength;
}

void GreedyStack::addProcessAt(int index, int processLength) {
    int id = this->stack[index].first;
    this->stack[index].second += processLength;
    this->listWithProcesses[id].push_back(processLength);

    this->population[this->processId] = id;
    this->processId++;

    this->sortStack(index);
}

int GreedyStack::valueAt(int index) {
    return this->stack[index].second;
}

void GreedyStack::sortStack(int changedIndex) {
    bool wasChanged = false;
    auto temp = this->stack[changedIndex];

    int operationsCount = 0;
    for (int i = changedIndex; i < this->stackLength - 1; i++) {
        operationsCount++;
        if (temp.second > this->stack[i + 1].second) {
            this->stack[i] = this->stack[i + 1];
        } else {
            this->stack[i] = temp;
            wasChanged = true;
            break;
        }
    }

    if (!wasChanged) {
        this->stack[this->stackLength - 1] = temp;
    }
}