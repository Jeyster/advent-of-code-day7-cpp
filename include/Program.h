#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <vector>


class Program
{
    public:
        Program(std::string name, int weight, std::vector<std::string> holdingProgramsStr);
        Program(std::string name, int weight);
        Program(std::string name);
        Program();
        const std::string getName();
        const int getWeight();
        const std::vector<std::string> getHoldingProgramsStr();
        const std::vector<Program> getHoldingPrograms();
        void setHoldingPrograms(std::vector<Program> holdingPrograms);
        void display();

    protected:

    private:
        std::string m_name;
        int m_weight;
        std::vector<std::string> m_holdingProgramsStr;
        std::vector<Program> m_holdingPrograms;
};

#endif // PROGRAM_H
