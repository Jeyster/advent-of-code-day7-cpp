#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "Program.h"
#include <string>
#include <vector>

std::vector<std::string> importInput(std::string const &fileName);
void displayVector(std::vector<std::string> tab);
Program createProgFromInput(std::string inputString);

#endif // TOOLS_H_INCLUDED
