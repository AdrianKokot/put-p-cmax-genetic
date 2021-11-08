#include <utility>
#include <vector>

using namespace std;

class GreedyStack
{
private:
  pair<int, int> *stack;
  vector<int> *listWithProcesses;

  int stackLength;

  void sortStack(int changedIndex)
  {
    bool wasChanged = false;
    auto temp = this->stack[changedIndex];

    int operationsCount = 0;
    for (int i = changedIndex; i < this->stackLength - 1; i++)
    {
      operationsCount++;
      if (temp.second > this->stack[i + 1].second)
      {

        this->stack[i] = this->stack[i + 1];
      }
      else
      {
        this->stack[i] = temp;
        wasChanged = true;
        break;
      }
    }

    if (!wasChanged)
    {
      this->stack[this->stackLength - 1] = temp;
    }
  }

public:
  GreedyStack(int processorNum)
  {
    this->stack = new pair<int, int>[processorNum];
    this->stackLength = processorNum;
    this->listWithProcesses = new vector<int>[processorNum];

    for (int i = 0; i < this->stackLength; i++)
    {
      this->stack[i] = pair<int, int>(i, 0);
    }
  }

  int length()
  {
    return this->stackLength;
  }

  void addProcessAt(int index, int processLength)
  {
    int procesorId = this->stack[index].first;
    this->stack[index].second += processLength;
    this->listWithProcesses[procesorId].push_back(processLength);

    this->sortStack(index);
  }

  int valueAt(int index)
  {
    return this->stack[index].second;
  }
};