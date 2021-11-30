#include "Genetic.h"

//TEMP

void Genetic::print(int *genotype) {
    cout << "\nGenotype: ";
    for (int i = 0; i < this->input->processes; i++) {
        cout << genotype[i] << ", ";
    }
}

void Genetic::print(vector<pair<int, int>> *localPopulation) {
    for (int i = 0; i < this->input->processors; i++) {
        cout << "\nProcessor " << i << ": ";

        for (int j = 0; j < localPopulation[i].size(); j++) {
            cout << localPopulation[i][j].first << ", ";
        }
    }
}

//ENDTEMP

// Data handling helpers
int Genetic::processAt(int index) {
    return (*this->input)[index];
}

pair<int, int> Genetic::processNotation(int index)  {
    return make_pair(index, this->processAt(index));
}

// Random generator
vector<pair<int, int>> *Genetic::generateRandomLocalPopulation() {
    auto *localPopulation = new vector<pair<int, int>>[this->input->processors];

    mt19937 gen((*(new random_device))());
    uniform_int_distribution<> distribution(0, this->input->processors - 1);

    for (int i = 0; i < this->input->processes; i++) {
        int processorId = distribution(gen);
        localPopulation[processorId].emplace_back(this->processNotation(i));
    }

    return localPopulation;
}

// Encode & decode

int *Genetic::encode(vector<pair<int, int>> *localPopulation) {
    auto genotype = new int[this->input->processes];

    for (int processorId = 0; processorId < this->input->processors; processorId++) {
        for (int j = 0; j < localPopulation[processorId].size(); j++) {
            int processId = localPopulation[processorId][j].first;
            genotype[processId] = processorId;
        }
    }

    return genotype;
}

vector<pair<int, int>> *Genetic::decode(int *genotype) {
    auto *localPopulation = new vector<pair<int, int>>[this->input->processors];

    for (int i = 0; i < this->input->processes; i++) {
        int processProcessorId = genotype[i];
        localPopulation[processProcessorId].emplace_back(this->processNotation(i));
    }

    return localPopulation;
}


// Main

Genetic::Genetic(InputData *inputData) {
    this->input = inputData;
}

int Genetic::getResult()  {

//    auto localPopulation = this->generateRandomLocalPopulation();
//
//    this->print(localPopulation);
//
//    auto encoded = this->encode(localPopulation);
//
//    this->print(encoded);
//
//    auto decoded = this->decode(encoded);
//
//    this->print(decoded);

    return 0;
}
