#include <fstream>
#include <iostream>
#include "GreedyStack.cpp"

using namespace std;

int main()
{
  int processes = 10, processors = 5;

  fstream input;
  input.open("wyniki.txt", ios::in);

  input >> processors >> processes;

  auto stack = new GreedyStack(processors);

  int currentProcessLength;
  for (int i = 0; i < processes; i++)
  {
    input >> currentProcessLength;

    stack->addProcessAt(0, currentProcessLength);
  }

  cout << stack->valueAt(processors - 1) << endl;

  return 0;
}
