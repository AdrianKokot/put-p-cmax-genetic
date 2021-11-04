#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

class TestGenerator
{
    int processors = (rand() % 90) + 10;
    int processes = 10 * processors;

public:
    TestGenerator();
    void testgenerator() const;

};

TestGenerator::TestGenerator(){
    testgenerator();
}
void TestGenerator::testgenerator() const{
    fstream input;
    input.open("wyniki.txt", ios::out);
    input << processors << endl;
    input << processes << endl;


    for (int i = 2; i < processes + 2; i++)
    {
        input << (rand() % 990) + 10 << endl;
    }
}

int main()
{
    srand(time(NULL));
    TestGenerator test;
    test.testgenerator();
}