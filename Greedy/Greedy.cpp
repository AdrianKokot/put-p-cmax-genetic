#include "Greedy.h"

int Greedy::getResult(int step) {
    auto stack = new GreedyStack(this->input->processors, this->input->processes);

    for (int i = 0; i < this->input->processes; i++) {
        stack->addProcessAt(0, (*this->input)[(i + step)%this->input->processes]);
    }

    return stack->valueAt(this->input->processors - 1);
}

int *Greedy::getPopulation(int step) {
    auto stack = new GreedyStack(this->input->processors, this->input->processes);

    for (int i = 0; i < this->input->processes; i++) {
        stack->addProcessAt(0, (*this->input)[(i + step)%this->input->processes]);
    }

    return stack->population;
}

Greedy::Greedy(InputData *inputData) {
    this->input = inputData;
}