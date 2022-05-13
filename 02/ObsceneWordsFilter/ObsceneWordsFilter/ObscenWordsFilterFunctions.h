#pragma once
#include <string>
#include <set>
#include <unordered_set>
#include <fstream>

std::set<std::string> FillSetFromFile(std::ifstream& inputFile);
bool IsObsceneWord(std::set<std::string> const& inputSet, std::string const& word);
std::string EraseWordFromString(std::string& str, std::string const& word);
std::string FilterObsceneWord(std::set<std::string> const& obsceneWords, std::string& inputLine, std::unordered_set<char> const& delimetrs);
