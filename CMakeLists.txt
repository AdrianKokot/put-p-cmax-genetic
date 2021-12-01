cmake_minimum_required(VERSION 3.20)
project(put_ok)

set(CMAKE_CXX_STANDARD 14)

add_executable(put_ok
        TestGenerator/TestGenerator.cpp Greedy/Greedy.cpp Greedy/Greedy.h Greedy/GreedyStack.cpp Greedy/GreedyStack.h Shared/InputData.cpp Shared/InputData.h Shared/Reader.cpp Shared/Reader.h Genetic/Genetic.cpp Genetic/Genetic.h Config.cpp Genetic/Random.cpp Genetic/Random.h main.cpp)
