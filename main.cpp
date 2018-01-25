#include <iostream>
#include "tools.h"
#include "Program.h"

using namespace std;

int main()
{
    vector<string> input = importInput("input.txt");
    displayVector(input);

    Program prog = createProgFromInput(input[1]);
    prog.display();

    return 0;
}
