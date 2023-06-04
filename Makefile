# FLAGS=-DCSV
FLAGS=-O3
FILE=./instances/1m25.txt
THREADS=1

main:	clean
	g++ -I./Genetic -I./Shared -I./Greedy ./Shared/*.cpp ./Greedy/*.cpp ./Genetic/*.cpp main.cpp Config.cpp -o main.out $(FLAGS)

main-s: clean
	g++ -I./Genetic -I./Shared -I./Greedy ./Shared/*.cpp ./Greedy/*.cpp ./Genetic/*.cpp main.cpp Config.cpp -o main.out $(FLAGS) -fopenmp

clean:
	rm -f main.out

run-s: main-s run-main

run: main run-main

run-main:
	./main.out $(FILE) $(THREADS)