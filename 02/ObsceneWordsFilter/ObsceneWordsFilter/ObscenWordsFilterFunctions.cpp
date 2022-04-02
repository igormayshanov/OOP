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

//больше подходит слово contains
bool IsObsceneWord(std::set<std::string> const& inputSet, std::string const& word)
{
	//пожно упростить
	return (inputSet.find(word) != inputSet.end());
}

std::string EraseWordFromInputLine(std::string& inputLine, std::string const& word)
{
	return inputLine.erase(inputLine.find(word), word.length());
}

// для хранения делиметров оптимальнее использовать set
//алгоритм мудреный, можно придумать проще. Подумай про string.append()
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
		delimetrPos = line.find_first_of(DELIMETR, wordBeginPos);
		while (delimetrPos != std::string::npos)
		{
			std::cout << "delimetrPos " << delimetrPos << "\n";
			if (delimetrPos > wordBeginPos)
			{
				wordAfterDelim = line.substr(wordBeginPos, delimetrPos - wordBeginPos);
			}
			wordBeginPos = delimetrPos + 1;
			if (IsObsceneWord(inputSet, wordAfterDelim))
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
		if (IsObsceneWord(inputSet, wordBeforDelim))
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


//Второй вариант поиска слов
std::string FilterObsceneWord(std::set<std::string> const& obsceneWords, std::string& inputLine, std::unordered_set<char> const& delimetrs)
{
	std::stringstream stringStream(inputLine);
	std::string outputLine;
	std::string line;
	while (stringStream >> line)
	{
		size_t wordBeginPos = 0;
		size_t delimetrPos;
		std::string word;
		std::string wordAfterDelim;
		for (auto& ch : line)
		{
			std::cout << "ch: " << ch << "\n";
			if (delimetrs.find(ch) == delimetrs.end() && ch != '\n')
			{
				std::cout << "ch not delimetr: " << ch << "\n";
				word.append(1, ch);
			}
			else
			{
				std::cout << "word: " << word << "\n";
				if (IsObsceneWord(obsceneWords, word))
				{
					outputLine = EraseWordFromInputLine(inputLine, word);
				}
				else
				{
					outputLine = inputLine;
				}
				word.clear();
			}
		}
		return outputLine;
	}
}