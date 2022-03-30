#pragma once
#include <string>
#include <set>
#include <fstream>

std::set<std::string> FillSetFromFile(std::ifstream& inputFile);
bool FindObsceneWordInSet(std::set<std::string> const& inputSet, std::string const& word);
std::string EraseWordFromInputLine(std::string& inputLine, std::string const& word);
std::string FindAndEraseObsceneWord(std::set<std::string> const& inputSet, std::string& inputLine, std::string const& DELIMETR);