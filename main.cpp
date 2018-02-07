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
    setAllHoldingPrograms(programs);
    setAllHoldingPrograms(programs);
    setAllHoldingPrograms(programs);
    setAllHoldingPrograms(programs);
    setAllHoldingPrograms(programs);

    vector<Program> holdingPrograms(getAllTheHoldingPrograms(programs));
    Program fatherProgram(getTheFatherProgram(programs, holdingPrograms));
    cout << "Nom du programme pere : " << fatherProgram.getName() << endl << endl;
    fatherProgram.display();

    vector<int> weights;
    sumHoldingProgramsWeight(fatherProgram, weights);

    Program aazgvmc(findProgramByName(programs, "aazgvmc"));
    aazgvmc.display();
    vector<int> weights2;
    sumHoldingProgramsWeight(aazgvmc, weights2);

    Program zuahdoy(findProgramByName(programs, "zuahdoy"));
    zuahdoy.display();
    vector<int> weights3;
    sumHoldingProgramsWeight(zuahdoy, weights3);

    Program mfzpvpj(findProgramByName(programs, "mfzpvpj"));
    mfzpvpj.display();
    vector<int> weights4;
    sumHoldingProgramsWeight(mfzpvpj, weights4);

    return 0;
}
