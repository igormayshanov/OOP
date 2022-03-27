#pragma once
#include <map>
#include <string>

std::map<std::string, unsigned> FillMapAndCountWords(std::map<std::string, unsigned int> const& inputMap, std::string word);
std::map<std::string, unsigned int> CountWordsInLines(std::map<std::string, unsigned int> const& inputMap, std::string line);
void PrintMap(std::map<std::string, unsigned int> inputMap);
