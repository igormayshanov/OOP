#include <iostream>
#include <sstream>
#include "ObscenWordsFilterFunctions.h"

std::string FindWord(std::string& str, std::string const& delimetr)
{
	std::string word;
	std::size_t pos;
	std::size_t previos = 0;
	while ((pos = str.find_first_of(delimetr, previos)) != std::string::npos)
	{
		if (pos > previos)
		{
			return word = str.substr(previos, pos - previos);
		}
		previos = pos + 1;
	}
	if (previos < str.length())
	{
		return word = str.substr(previos, std::string::npos);
	}
}

std::set<std::string> FillSetFromFile(std::ifstream& inputFile) 
{
	std::set<std::string> words;
	std::string word;
	std::string stringFromFile;
	while (std::getline(inputFile, stringFromFile))
	{
		std::stringstream stringStream(stringFromFile);
		while (stringStream >> word)
		{
			words.insert(word);
		}
	}
	return words;
}
