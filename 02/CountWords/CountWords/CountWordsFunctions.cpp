#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include "CountWordsFunctions.h"

std::map<std::string, unsigned> FillMapAndCountWords(std::map<std::string, unsigned int> const& inputMap, std::string word)
{
	std::map<std::string, unsigned int> words = inputMap;
	std::map<std::string, unsigned int>::iterator it;
	if (!word.empty())
	{
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		it = words.find(word);
		if (it == words.end())
		{
			words.insert(make_pair(word, 1));
		}
		else
		{
			it->second++;
		}
		return words;
	}
	else
	{
		return {};
	}
}

void CountWordsInLines(std::map<std::string, unsigned int> &  words, std::string line)
{
	std::string word;
	std::stringstream stringStream(line);
	while (stringStream >> word)
	{
		words = FillMapAndCountWords(words, word);
	}
	return words;
}

void PrintMap(std::map<std::string, unsigned int> inputMap)
{
	std::map<std::string, unsigned int>::iterator it;
	for (it = inputMap.begin(); it != inputMap.end(); it++)
	{
		std::cout << it->first << "->" << it->second << "\n";
	}
}
