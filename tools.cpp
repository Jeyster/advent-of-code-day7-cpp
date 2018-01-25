#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include "tools.h"

using namespace std;

vector<string> importInput(string const &fileName)
{
    ifstream myStream(fileName);
    if(!myStream)
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        exit(0);
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
    string name;
    int weight;
    string holdingProgram;
    vector<string> holdingPrograms;

    istringstream iss(inputString);
    cout << "Position avant cout : " << iss.tellg() << endl;
    iss >> name;
    cout << "Position apres cout du nom : " << iss.tellg() << endl;
    iss.seekg(2, ios::cur);
    cout << "Position apres cout du nom : " << iss.tellg() << endl;
    iss >> weight;
    cout << "Position apres cout du poids : " << iss.tellg() << endl << endl;
    iss.seekg(5, ios::cur);
    iss >> holdingProgram;
    holdingPrograms.push_back(holdingProgram);
    iss >> holdingProgram;
    holdingPrograms.push_back(holdingProgram);
    iss >> holdingProgram;
    holdingPrograms.push_back(holdingProgram);

    Program program(name, weight, holdingPrograms);

    return program;
}
