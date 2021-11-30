cmake_minimum_required(VERSION 3.20)
project(put_ok)

set(CMAKE_CXX_STANDARD 14)

add_executable(put_ok
        Genetic/Genetic.cpp
        TestGenerator/TestGenerator.cpp Greedy/Greedy.cpp Greedy/Greedy.h Greedy/GreedyStack.cpp Greedy/GreedyStack.h Shared/InputData.cpp Shared/InputData.h Shared/Reader.cpp Shared/Reader.h)
