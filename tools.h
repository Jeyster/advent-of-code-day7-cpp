#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "include/Program.h"
#include <string>
#include <vector>

std::vector<std::string> importInput(std::string fileName);
void displayVector(std::vector<std::string> tab);
Program createProgFromInput(std::string inputString);
std::vector<Program> createProgsListFromInput(std::vector<std::string> input);
Program findProgramByName(std::vector<Program> const &programs, std::string const &name);
void setAllHoldingPrograms(std::vector<Program> &programs);
std::vector<Program> getAllTheHoldingPrograms(std::vector<Program> programs);
Program getTheFatherProgram(std::vector<Program> &programs, std::vector<Program> &holdingPrograms);

#endif // TOOLS_H_INCLUDED
