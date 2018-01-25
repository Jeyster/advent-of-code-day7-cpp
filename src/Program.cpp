#include "Program.h"
#include <iostream>

using namespace std;

Program::Program(string name, int weight, vector<string> holdingPrograms) : m_name(name), m_weight(weight), m_holdingPrograms(holdingPrograms)
{
}

Program::Program(string name, int weight) : m_name(name), m_weight(weight)
{
}

Program::Program(string name) : m_name(name)
{
}

void Program::display()
{
    cout << "Nom : " << this->m_name << endl;
    cout << "Poids : " << this->m_weight << endl;

    cout << "Programmes fils : ";
    vector<string>::iterator itProgs;
    for (itProgs = this->m_holdingPrograms.begin(); itProgs != this->m_holdingPrograms.end(); ++itProgs)
    {
        cout << *itProgs << " ";
    }
    cout << endl << endl;
}
