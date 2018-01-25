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
    setHoldingPrograms(programs);
    cout << "Nombre total de progs : " << programs.size() << endl;
    /*
    for(int i(0); i != programs.size(); ++i)
    {
        programs[i].display();
    }
    */

    vector<Program> holdingPrograms(getAllTheHoldingPrograms(programs));
    cout << "Nombre total de progs fils : " << holdingPrograms.size() << endl;

    cout << "Nom du programme pere : " << getTheFatherProgram(programs, holdingPrograms).getName() << endl;

    for (int i(0); i != 10; ++i)
    {
        holdingPrograms[i].display();
    }

    return 0;
}
