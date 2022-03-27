#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include "CountWordsFunctions.h"


std::map<std::string, unsigned int> CountWords(std::map<std::string, unsigned int> const& inputMap, std::string line)
{
	std::map<std::string, unsigned int> words = inputMap;
	std::map<std::string, unsigned int>::iterator it;
	std::string word;
	std::stringstream stringStream;
	stringStream.str(line);
	while (stringStream >> word)
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
