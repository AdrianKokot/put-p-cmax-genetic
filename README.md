# p-cmax-genetic
Solution for P||Cmax problem using genetic metaheuristic written in C++.

This solution is the assignment written for the "Combinatorial Optimization" course at Poznan University of Technology.

## How to use

When running compiled file you have to pass as a first parameter path to the file with the data.
Data should be in the following format:

```txt
n - number of processors
m - number of tasks
m lines with duration of the given task
```

### How to compile

```bash
g++ -I./Genetic -I./Shared -I./Greedy .\Shared\*.cpp .\Greedy\*.cpp .\Genetic\*.cpp main.cpp Config.cpp
```

or use Make

### run-xxx.ps1

Files called `run-ranking.ps1` and `run-benchmark.ps1` are powershell scripts that run all instances in `instances` or `instances/report` directories.