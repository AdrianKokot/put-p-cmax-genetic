#include "GreedyStack.cpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int processes = 10, processors = 5;

  fstream input;

  if (argc > 1)
  {
    input.open(argv[1], ios::in);
  }
  else
  {
    input.open("wyniki.txt", ios::in);
  }

  if (!input)
  {
    cout << "File doesn't exist." << endl;
    return 0;
  }

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
