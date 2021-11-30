#include "Greedy.h"

int Greedy::getResult() {
    auto stack = new GreedyStack(this->input->processors);

    for (int i = 0; i < this->input->processes; i++) {
        stack->addProcessAt(0, (*this->input)[i]);
    }

    return stack->valueAt(this->input->processors - 1);
}

Greedy::Greedy(InputData *inputData) {
    this->input = inputData;
}