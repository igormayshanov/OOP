#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "ObscenWordsFilterFunctions.h"
#include "OpenFile.h"
#include "ParseArgs.h"

using namespace std;

int main(int argc, char* argv[])
{
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


	cout << "Enter the line:\n";
	string inputString;
	getline(cin, inputString);
	stringstream stringStream;
	stringStream.str(inputString);
	cout << inputString << "\n";
	string line;
	string word;
	vector<string> wordVector;
	while (stringStream >> line)
	{
		word = FindWord(line, DELIMETR);
		wordVector.push_back(word);
	}
	for (auto& i : wordVector)
	{
		cout << i << "\n";
	}
}