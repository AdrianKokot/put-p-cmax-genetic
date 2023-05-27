FILENAME = $(shell ls instances/*.txt | grep -v _best.txt$ | head -1)

main:	clean
	g++ -I./Genetic -I./Shared -I./Greedy ./Shared/*.cpp ./Greedy/*.cpp ./Genetic/*.cpp main.cpp Config.cpp -o main

clean:
	rm -f main

run: main
	./main $(FILENAME)