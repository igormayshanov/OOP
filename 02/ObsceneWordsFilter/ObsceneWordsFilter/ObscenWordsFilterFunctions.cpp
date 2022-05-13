#include <iostream>
#include <sstream>
#include <algorithm>
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

//больше подходит слово contains
bool IsObsceneWord(std::set<std::string> const& inputSet, std::string word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	//пожно упростить
	return (inputSet.find(word) != inputSet.end());
}

std::string EraseWordFromString(std::string& str, std::string const& word)
{
	return str.erase(str.find(word), word.length());
}

// для хранения делиметров оптимальнее использовать set
//алгоритм мудреный, можно придумать проще. Подумай про string.append()

//Второй вариант поиска слов
std::string FilterObsceneWord(std::set<std::string> const& obsceneWords, std::string& inputLine, std::unordered_set<char> const& delimetrs)
{
	std::string word;
	std::string outputLine = inputLine;
	for (auto& ch : inputLine)
	{
		if (delimetrs.find(ch) == delimetrs.end())
		{
			word.append(1, ch);
		}
		else if (IsObsceneWord(obsceneWords, word))
		{
			outputLine = EraseWordFromString(outputLine, word);
			word.clear();
		}
	    else
		{
		    word.clear();
		}
	}
	if (IsObsceneWord(obsceneWords, word))
	{
		outputLine = EraseWordFromString(outputLine, word);
	}
	return outputLine;
}