#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <vector>


class Program
{
    public:
        Program(std::string name, int weight, std::vector<std::string> holdingPrograms);
        Program(std::string name, int weight);
        Program(std::string name);
        void display();

    protected:

    private:
        std::string m_name;
        int m_weight;
        std::vector<std::string> m_holdingPrograms;
};

#endif // PROGRAM_H
