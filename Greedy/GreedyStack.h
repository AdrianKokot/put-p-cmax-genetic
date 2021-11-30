#ifndef PUT_OK_GREEDYSTACK_H
#define PUT_OK_GREEDYSTACK_H

#include <utility>
#include <vector>

using namespace std;

class GreedyStack {
private:
    pair<int, int> *stack;
    vector<int> *listWithProcesses;

    int stackLength;

    void sortStack(int);

public:
    GreedyStack(int);

    int length();

    void addProcessAt(int, int);

    int valueAt(int);
};

#endif //PUT_OK_GREEDYSTACK_H
