#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include "tools.h"

using namespace std;

vector<string> importInput(string fileName)
{
    ifstream myStream(fileName.c_str());
    if(!myStream)
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        //exit(0);
    }

    string line;
    vector<string> input;
    while(getline(myStream, line))
    {
        input.push_back(line);
    }

    return input;
}

void displayVector(vector<string> tab)
{
    vector<string>::iterator itTab;
    for(itTab = tab.begin(); itTab != tab.end(); ++itTab)
    {
        cout << *itTab << endl;
    }
    cout << endl;
}

Program createProgFromInput(string inputString)
{
    istringstream iss(inputString.c_str());
    vector<string> progVector(istream_iterator<string>{iss}, istream_iterator<string>());

    string name(progVector[0]);
    string weightStr = progVector[1].substr(1,progVector[1].size());
    int weight(atoi(weightStr.c_str()));
    vector<string> holdingPrograms;
    if(progVector.size() > 2)
    {
        for(int i(3); i != progVector.size()-1; ++i)
        {
            holdingPrograms.push_back(progVector[i].substr(0,progVector[i].size()-1));
        }
        holdingPrograms.push_back(progVector[progVector.size()-1]);
    }

    Program program(name, weight, holdingPrograms);

    return program;
}

vector<Program> createProgsListFromInput(vector<string> input)
{
    vector<Program> progVector;
    for(int i(0); i != input.size(); ++i)
    {
        progVector.push_back(createProgFromInput(input[i]));
    }
    return progVector;
}

Program findProgramByName(vector<Program> &programs, string const &name)
{
    for(int i(0); i != programs.size(); ++i)
    {
        if(programs[i].getName() == name)
        {
            return programs[i];
        }
    }
    return Program();
}

void setAllHoldingPrograms(vector<Program> &programs)
{
    for(int i(0); i != programs.size(); ++i)
    {
        vector<string> holdingProgramsStr = programs[i].getHoldingProgramsStr();
        if(holdingProgramsStr.size() > 0)
        {
            vector<Program> holdingPrograms;
            for(int j(0); j != holdingProgramsStr.size(); ++j)
            {
                holdingPrograms.push_back(findProgramByName(programs, holdingProgramsStr[j]));
            }

            programs[i].setHoldingPrograms(holdingPrograms);
        }
    }
}

vector<Program> getAllTheHoldingPrograms(vector<Program> programs)
{
    vector<Program> allTheHoldingPrograms;
    for(int i(0); i != programs.size(); ++i)
    {
        vector<Program> holdingPrograms(programs[i].getHoldingPrograms());
        if(holdingPrograms.size() > 0)
        {
            for(int j(0); j != holdingPrograms.size(); ++j)
            {
                Program currentHoldingProgram = findProgramByName(allTheHoldingPrograms, holdingPrograms[j].getName());
                if(currentHoldingProgram.getWeight() == 0)
                {
                    allTheHoldingPrograms.push_back(holdingPrograms[j]);
                }
            }
        }
    }

    return allTheHoldingPrograms;
}

Program getTheFatherProgram(vector<Program> &programs, vector<Program> &holdingPrograms)
{
    for(int i(0); i != programs.size(); ++i)
    {
        Program program = findProgramByName(holdingPrograms, programs[i].getName());
        if(program.getWeight() == 0)
        {
            return programs[i];
        }
    }
}

void sumHoldingProgramsWeight(Program &program, vector<int> &weights)
{
    vector<Program> holdingPrograms(program.getHoldingPrograms());
    int holdingProgramsSize(holdingPrograms.size());
    for(int i(0); i != holdingProgramsSize; ++i)
    {
        weights.push_back(0);
        sumWeightRecursively(holdingPrograms[i], weights[i]);
        cout << "Poids total du programme " << holdingPrograms[i].getName() << " : " << weights[i] << endl << endl;
    }
}

void sumWeightRecursively(Program &program, int &weight)
{
    weight += program.getWeight();

    vector<Program> holdingPrograms(program.getHoldingPrograms());
    int holdingProgramsSize(holdingPrograms.size());

    if(holdingProgramsSize > 0)
    {
        for(int i(0); i != holdingProgramsSize; ++i)
        {
            sumWeightRecursively(holdingPrograms[i], weight);
        }
    }
}
