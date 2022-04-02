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
	const std::string DELIMETR = "\" +-=#*{}[]<>()';,.:!?&@\t";
	std::unordered_set<char> delimetrs = { '\"', '+', '-', '=', '#', '*', '\\', '{', '}', '(', ')', '[', ']', '\'', ':', ';',
	',', '.' };
	for (auto& i:delimetrs)
	{
		cout << i << ", ";
	}
	cout << "\n";
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
	string inputLine;
	getline(cin, inputLine);
	string workingLine = inputLine;
	//подумай над названием

	//cout << FindAndEraseObsceneWord(obsceneWords, workingLine, DELIMETR) << "\n";
	cout << FilterObsceneWord(obsceneWords, workingLine, delimetrs) << "\n";
}