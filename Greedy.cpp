#include <fstream>
#include <iostream>

#include <vector>

using namespace std;

int findLeastUsedProcessor(int *processorsWithAssignedProcessesLength, int arrLength);

struct Process
{
  int id;
  int length;
};

int main()
{
  int processes, processors;

  fstream input;
  input.open("wyniki.txt", ios::in);

  input >> processors >> processes;

  vector<Process> *processorsWithProcesses = new vector<Process>[processors] {};
  int *processorsWithAssignedProcessesLength = new int[processors]{0};

  int currentProcessLength;
  for (int i = 0; i < processes; i++)
  {
    input >> currentProcessLength;

    int bestProcessorIndex = findLeastUsedProcessor(processorsWithAssignedProcessesLength, processors);

    struct Process currentProcess;
    currentProcess.id = i;
    currentProcess.length = currentProcessLength;

    processorsWithProcesses[bestProcessorIndex].push_back(currentProcess);
    processorsWithAssignedProcessesLength[bestProcessorIndex] += currentProcessLength;
  }

  int result = processorsWithAssignedProcessesLength[0];

  for (int i = 1; i < processors; i++)
  {
    if (processorsWithAssignedProcessesLength[i] > result)
    {
      result = processorsWithAssignedProcessesLength[i];
    }
  }

  cout << result << endl;

  return 0;
}

int findLeastUsedProcessor(int *processorsWithAssignedProcessesLength, int arrLength)
{
  int currValue = processorsWithAssignedProcessesLength[0];
  int currValueIndex = 0;

  for (int i = 0; i < arrLength; i++)
  {
    if (currValue > processorsWithAssignedProcessesLength[i])
    {
      currValue = processorsWithAssignedProcessesLength[i];
      currValueIndex = i;
    }
  }

  return currValueIndex;
}
