#pragma once
#include <string>
#include <set>
#include <fstream>


std::string FindWord(std::string& str, std::string const& delimetr);
std::set<std::string> FillSetFromFile(std::ifstream& inputFile);

bool FindObsceneWordInSet(std::set<std::string> const& inputMap, std::string const& word);
std::string EraseWordFromInputLine(std::string& inputLine, std::string const& word);