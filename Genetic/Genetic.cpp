#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int processes, processors;

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

  cout << "To implement.";

  return 0;
}
