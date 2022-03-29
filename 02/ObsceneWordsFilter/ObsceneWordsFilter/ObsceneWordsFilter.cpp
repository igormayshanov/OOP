#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>

#include "ObscenWordsFilterFunctions.h"
#include "OpenFile.h"
#include "ParseArgs.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	const string DELIMETR = " ';,.:!?";

	auto inputFileName = ParseArgs(argc, argv);
	if (!inputFileName)
	{
		cout << "Invalid argument count\n";
		cout << "Usage: ObsceneWordsFilter.exe <inputFileName>\n";
		return 1;
	}
	auto inputFile = OpenFile(*inputFileName);
	if (!inputFile)
	{
		cout << "Filed to open '" << *inputFileName << "' for reading\n";
		return 1;
	}

	set<string> obsceneWords = FillSetFromFile(*inputFile);
	for (auto& i : obsceneWords)
	{
		cout << i << "\n";
	}
	cout << "Enter the line:\n";
	string inputString;
	string outputString;
	getline(cin, inputString);
	stringstream stringStream;
	stringStream.str(inputString);
	cout << inputString << "\n";
	string line;
	vector<string> wordVector;
	while (stringStream >> line)
	{
		size_t wordBeginPos = 0;
		size_t delimetrPos;
		string wordBeforDelim;
		string wordAfterDelim;
		while ((delimetrPos = line.find_first_of(DELIMETR, wordBeginPos)) != std::string::npos)
		{
			if (delimetrPos > wordBeginPos)
			{
				wordAfterDelim = line.substr(wordBeginPos, delimetrPos - wordBeginPos);	
			}
			cout << "wordAfterDelim " << wordAfterDelim << "\n";
			wordBeginPos = delimetrPos + 1;
			if (obsceneWords.find(wordAfterDelim) != obsceneWords.end())
			{
				outputString = inputString.erase(inputString.find(wordAfterDelim), wordAfterDelim.length());
			}
		}
		if (wordBeginPos < line.length())
		{
			wordBeforDelim = line.substr(wordBeginPos, std::string::npos);
		}
		cout << "wordBeforDelim " << wordBeforDelim << "\n";
		if (obsceneWords.find(wordBeforDelim) != obsceneWords.end())
		{
			outputString = inputString.erase(inputString.find(wordBeforDelim), wordBeforDelim.length());
		}
	}
	cout << "Print input string without obscene words: \n";
	cout << outputString << "\n";
	for (auto& i : wordVector)
	{
		cout << i << "\n";
	}
}