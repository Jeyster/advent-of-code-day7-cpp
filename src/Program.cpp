#include "../include/Program.h"
#include <iostream>

using namespace std;

Program::Program(string name, int weight, vector<string> holdingProgramsStr) : m_name(name), m_weight(weight), m_holdingProgramsStr(holdingProgramsStr)
{
}

Program::Program(string name, int weight) : m_name(name), m_weight(weight)
{
}

Program::Program(string name) : m_name(name)
{
}

Program::Program() : m_name(""), m_weight(0)
{
}

const string Program::getName()
{
    return this->m_name;
}

const int Program::getWeight()
{
    return this->m_weight;
}

const vector<string> Program::getHoldingProgramsStr()
{
    return this->m_holdingProgramsStr;
}

const vector<Program> Program::getHoldingPrograms()
{
    return this->m_holdingPrograms;
}

void Program::setHoldingPrograms(vector<Program> holdingPrograms)
{
    this->m_holdingPrograms = holdingPrograms;
}

void Program::display()
{
    cout << "Nom : " << this->m_name << endl;
    cout << "Poids : " << this->m_weight << endl;

    cout << "Programmes fils : ";
    vector<Program>::iterator itProgs;
    for (itProgs = this->m_holdingPrograms.begin(); itProgs != this->m_holdingPrograms.end(); ++itProgs)
    {
        cout << itProgs->getName() << " ";
    }
    cout << endl << endl;
}
