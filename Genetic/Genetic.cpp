#include "Genetic.h"
#include "../Config.cpp"

//TEMP

void Genetic::print(int *genotype) {
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

pair<int, int> Genetic::processNotation(int index) {
    return make_pair(index, this->processAt(index));
}


// Random generator
vector<pair<int, int>> *Genetic::generateRandomLocalPopulation() {
    auto *localPopulation = new vector<pair<int, int>>[this->input->processors];

    for (int i = 0; i < this->input->processes; i++) {
        int processorId = this->random->processor();
        localPopulation[processorId].emplace_back(this->processNotation(i));
    }

    return localPopulation;
}

vector<pair<int, int>> **Genetic::generateRandomPopulation() {
    auto population = new vector<pair<int, int>> *[POPULATION_SIZE];

    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = this->generateRandomLocalPopulation();
    }

    return population;
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

// Adaptation & selection

int Genetic::adaptationScore(int *genotype) {
    auto localPopulation = this->decode(genotype);
    int genotypeScore = 0;

    for (int i = 0; i < this->input->processors; i++) {
        int processorScore = 0;

        for (int j = 0; j < localPopulation[i].size(); j++) {
            processorScore += localPopulation[i][j].second;
        }

        if (processorScore > genotypeScore) {
            genotypeScore = processorScore;
        }
    }

    return -1 * genotypeScore;
}

vector<pair<int, int>> **Genetic::selection(vector<pair<int, int>> **population) {
    pair<int, int> bestLocalPopulations[2];

    bestLocalPopulations[0] = make_pair(INT_MIN, 0);
    bestLocalPopulations[1] = make_pair(INT_MIN, 0);

    for (int i = 0; i < POPULATION_SIZE; i++) {
        int score = this->adaptationScore(this->encode(population[i]));

        if (score > bestLocalPopulations[0].first) {
            bestLocalPopulations[1] = bestLocalPopulations[0];
            bestLocalPopulations[0] = make_pair(score, i);
        } else if (score > bestLocalPopulations[1].first) {
            bestLocalPopulations[1] = make_pair(score, i);
        }
    }

    return new vector<pair<int, int>> *[2]{
            population[bestLocalPopulations[0].second],
            population[bestLocalPopulations[1].second]
    };
}

// Crossover & mutation

int **Genetic::crossover(int *firstGenotype, int *secondGenotype) {
    auto newPopulation = new int *[2];

    newPopulation[0] = new int[this->input->processes]{};
    newPopulation[1] = new int[this->input->processes]{};


    for (int i = 0; i < this->input->processes / 2; i++) {

        newPopulation[0][i] = firstGenotype[i];
        newPopulation[0][this->input->processes - i - 1] = secondGenotype[this->input->processes - i - 1];
        newPopulation[1][i] = secondGenotype[i];
        newPopulation[1][this->input->processes - i - 1] = firstGenotype[this->input->processes - i - 1];
    }

    return newPopulation;
}

void Genetic::mutation(int **population) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        int rand = this->random->percentage();
        if (rand <= MUTATION_PROBABILITY) {
            int randProcess = this->random->process();
            int randProcessor = this->random->processor();

            population[i][randProcess] = randProcessor;
        }
    }
}

// Main

Genetic::Genetic(InputData *inputData) {
    this->input = inputData;

    this->random = new Random(this->input->processes, this->input->processors);
}

int Genetic::getResult() {
    int bestScore = INT_MIN;
    int *bestGenotype;

    int withoutProgress = 0;
    auto population = this->generateRandomPopulation();

    for (int x = 0; x < 256 && withoutProgress < 100; x++) {
        cout << "Run " << x << endl;
        auto bestLocalPopulations = this->selection(population);

        auto newChildren = this->crossover(
                this->encode(bestLocalPopulations[0]),
                this->encode(bestLocalPopulations[1])
        );

        auto populationGenotype = new int*[POPULATION_SIZE];

        for(int i = 0; i < POPULATION_SIZE; i++){
            populationGenotype[i] = this->encode(population[i]);
        }

        int idx1 = 0, idx2 = 1;
        int idx1Score = this->adaptationScore(populationGenotype[0]),
                idx2Score = this->adaptationScore(populationGenotype[1]);

        for (int i = 2; i < POPULATION_SIZE; i++) {
            int score = this->adaptationScore(populationGenotype[i]);

            if (score < idx1Score) {
                idx2 = idx1;
                idx2Score = idx1Score;
                idx1 = i;
                idx1Score = score;
            } else if (score < idx2Score) {
                idx2Score = score;
                idx2 = i;
            }
        }

        populationGenotype[idx1] = newChildren[0];
        populationGenotype[idx2] = newChildren[1];

        this->mutation(populationGenotype);

        int currentBestScore = this->adaptationScore(populationGenotype[0]);
        int currentBestScoreIdx = 0;

        for (int i = 1; i < POPULATION_SIZE; i++) {
            int score = this->adaptationScore(populationGenotype[i]);

            if (score > currentBestScore) {
                currentBestScore = score;
                currentBestScoreIdx = i;
            }
        }

        if (currentBestScore > bestScore) {
            bestScore = currentBestScore;
            bestGenotype = populationGenotype[currentBestScoreIdx];
            withoutProgress = 0;
        } else {
            withoutProgress++;
        }

    }

    cout << "\n===============\nBest genotype:\n";


    this->print(bestGenotype);
    cout << "\n===============\n\n";

    return -1 * bestScore;
}
