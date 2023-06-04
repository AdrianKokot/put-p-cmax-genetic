#include <iostream>
#include "Greedy/Greedy.h"
#include "Shared/Reader.h"
#include "Genetic/Genetic.h"
#include <omp.h>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <limits>
#include <numbers>

using namespace std;

pair<int, double> run_for_threads_num(InputData *inputData, int threads_num)
{
#if defined(_OPENMP)
  omp_set_num_threads(threads_num);
#endif

  auto genetic = new Genetic(inputData);

  auto start = chrono::high_resolution_clock::now();
  int geneticResult = genetic->getResult();
  auto end = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000000000.0;

  return make_pair(geneticResult, duration);
}

int main(int argc, char *argv[])
{
  auto inputData = Reader::readInput(argc, argv);

  cout << "| " << setw(10) << "Threads"
       << " | " << setw(10) << "Time"
       << " | " << setw(10) << "Result"
       << " | " << setw(10) << "Speedup"
       << " |" << endl
       << "| ---------- | ---------- | ---------- | ---------- |" << endl;

  auto sec = run_for_threads_num(inputData, 1);

  cout << "| " << setw(10) << "1"
       << " | " << setw(10) << fixed << setprecision(7) << sec.second << " | " << setw(10) << sec.first << " | " << setw(10) << fixed << setprecision(7) << 1.0 << " |" << endl;

  for (int threads = 2; threads <= 12; threads++)
  {
    auto par = run_for_threads_num(inputData, threads);
    cout << "| " << setw(10) << threads << " | " << setw(10) << fixed << setprecision(7) << par.second << " | " << setw(10) << par.first << " | " << setw(10) << fixed << setprecision(7) << sec.second / par.second << " |" << endl;
  }

  return 0;
}
