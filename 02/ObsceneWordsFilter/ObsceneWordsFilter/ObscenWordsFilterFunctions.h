#pragma once
#include <string>
#include <set>
#include <fstream>


std::string FindWord(std::string& str, std::string const& delimetr);
std::set<std::string> FillSetFromFile(std::ifstream& inputFile);

