#include <iostream>
#include <sstream>
#include <iterator>
#include "tools.h"
#include "include/Program.h"

using namespace std;

int main()
{
    vector<string> input = importInput("input.txt");
    //displayVector(input);

    vector<Program> programs(createProgsListFromInput(input));
    setAllHoldingPrograms(programs);

    vector<Program> holdingPrograms(getAllTheHoldingPrograms(programs));
    Program fatherProgram(getTheFatherProgram(programs, holdingPrograms));
    cout << "Nom du programme pere : " << fatherProgram.getName() << endl;

    return 0;
}
