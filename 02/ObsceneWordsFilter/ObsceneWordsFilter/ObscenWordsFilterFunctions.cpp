#include <iostream>
#include <sstream>
#include "ObscenWordsFilterFunctions.h"

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

bool FindObsceneWordInSet(std::set<std::string> const& inputSet, std::string const& word)
{
	if (inputSet.find(word) != inputSet.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string EraseWordFromInputLine(std::string& inputLine, std::string const& word)
{
	return inputLine.erase(inputLine.find(word), word.length());
}

std::string FindAndEraseObsceneWord(std::set<std::string> const& inputSet, std::string& inputLine, std::string const& DELIMETR)
{
	std::stringstream stringStream(inputLine);
	std::string outputLine;
	std::string line;
	while (stringStream >> line)
	{
		size_t wordBeginPos = 0;
		size_t delimetrPos;
		std::string wordBeforDelim;
		std::string wordAfterDelim;
		while ((delimetrPos = line.find_first_of(DELIMETR, wordBeginPos)) != std::string::npos)
		{
			if (delimetrPos > wordBeginPos)
			{
				wordAfterDelim = line.substr(wordBeginPos, delimetrPos - wordBeginPos);
			}
			wordBeginPos = delimetrPos + 1;
			if (FindObsceneWordInSet(inputSet, wordAfterDelim))
			{
				outputLine = EraseWordFromInputLine(inputLine, wordAfterDelim);
			}
			else
			{
				outputLine = inputLine;
			}
		}
		if (wordBeginPos < line.length())
		{
			wordBeforDelim = line.substr(wordBeginPos, std::string::npos);
		}
		if (FindObsceneWordInSet(inputSet, wordBeforDelim))
		{
			outputLine = EraseWordFromInputLine(inputLine, wordBeforDelim);
		}
		else
		{
			outputLine = inputLine;
		}
	}
	return outputLine;
}