#pragma once
#include <map>
#include <string>


std::map<std::string, unsigned int> CountWords(std::map<std::string, unsigned int> const& inputMap, std::string line);
void PrintMap(std::map<std::string, unsigned int> inputMap);
