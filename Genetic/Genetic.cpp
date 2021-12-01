#include "Genetic.h"
#include "../Config.cpp"

// Printing
void Genetic::print(int *genotype) {
    for (int i = 0; i < this->input->processes; i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << genotype[i];
    }
}

void Genetic::visualize(int *genotype) {
    auto processorsWithProcesses = new vector<int>[this->input->processors];

    for (int i = 0; i < this->input->processes; i++) {
        processorsWithProcesses[genotype[i]].push_back(this->processAt(i));
    }

    for (int i = 0; i < this->input->processors; i++) {
        cout << "Processor " << i << ": ";
        int score = 0;
        for (long long unsigned int j = 0; j < processorsWithProcesses[i].size(); j++) {
            score += processorsWithProcesses[i][j];
            cout << processorsWithProcesses[i][j] << " ";
        }

        cout << "\n\t\tDuration: " << score << "\n==================================\n";
    }
}

// Data handling helpers
int Genetic::processAt(int index) {
    return (*this->input)[index];
}

// Random generator
int *Genetic::generateRandomLocalPopulation() {
    auto population = new int[this->input->processes];

    for (int i = 0; i < this->input->processes; i++) {
        int processorId = this->random->processor();
        population[i] = processorId;
    }

    return population;
}

int **Genetic::generateRandomPopulation() {
    auto population = new int *[POPULATION_SIZE];

    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = this->generateRandomLocalPopulation();
    }

    return population;
}

// Adaptation & selection

int Genetic::adaptationScore(int *genotype) {
    int score = 0;

    auto processorsScore = new int[this->input->processors]{0};

    for (int i = 0; i < this->input->processes; i++) {
        processorsScore[genotype[i]] += this->processAt(i);
    }

    for (int i = 0; i < this->input->processors; i++) {
        if (processorsScore[i] > score) {
            score = processorsScore[i];
        }
    }

    return -1 * score;
}

int **Genetic::selection(int **population) {
    pair<int, int> best[2] = {
            make_pair(INT_MIN, 0),
            make_pair(INT_MIN, 0)
    };

    for (int i = 0; i < POPULATION_SIZE; i++) {
        int score = this->adaptationScore(population[i]);

        if (score > best[0].first) {
            best[1] = best[0];
            best[0] = make_pair(score, i);
        } else if (score > best[1].first) {
            best[1] = make_pair(score, i);
        }
    }

    return new int *[2]{
            population[best[0].second],
            population[best[1].second]
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

void Genetic::breeding(int **population) {
    auto best = this->selection(population);

    auto children = this->crossover(best[0], best[1]);

    pair<int, int> worst[2] = {
            make_pair(this->adaptationScore(population[0]), 0),
            make_pair(this->adaptationScore(population[1]), 1)
    };

    for (int i = 2; i < POPULATION_SIZE; i++) {
        int score = -1 * this->adaptationScore(population[i]);

        if (score > worst[0].first) {
            worst[1] = worst[0];
            worst[0] = make_pair(score, i);
        } else if (score > worst[1].first) {
            worst[1] = make_pair(score, i);
        }
    }

    population[worst[0].second] = children[0];
    population[worst[0].second] = children[1];
}

pair<int, int> Genetic::findBest(int **population) {
    pair<int, int> currentBest = make_pair(this->adaptationScore(population[0]), 0);

    for (int i = 1; i < POPULATION_SIZE; i++) {
        int score = this->adaptationScore(population[i]);

        if (score > currentBest.first) {
            currentBest.first = score;
            currentBest.second = i;
        }
    }

    return currentBest;
}

Genetic::Genetic(InputData *inputData) {
    this->input = inputData;

    this->random = new Random(this->input->processes, this->input->processors);
}

int Genetic::getResult() {
    pair<int, int *> best = make_pair(INT_MIN, new int[this->input->processes]{0});

    int withoutProgress = 0;
    auto population = this->generateRandomPopulation();

    int x = 0;
    for (x = 0; x < MAX_LOOP_COUNT && withoutProgress < MAX_WITHOUT_PROGRESS; x++) {
        this->breeding(population);

        this->mutation(population);

        auto currentBest = this->findBest(population);

        if (currentBest.first > best.first) {
            best.first = currentBest.first;

            for (int i = 0; i < this->input->processes; i++) {
                best.second[i] = population[currentBest.second][i];
            }

            withoutProgress = 0;
        } else {
            withoutProgress++;
        }
    }

    this->visualize(best.second);
//    cout << "\nBreak on x: " << x << " and no progress count: " << withoutProgress << endl;

    return -1 * best.first;
}
