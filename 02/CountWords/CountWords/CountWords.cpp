#include <iostream>
#include <map>
#include <Windows.h>
#include "CountWordsFunctions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	cout << "Enter text: \n";
	string line;
	map<string, unsigned int> words;
	while (getline(cin, line))
	{
		words = CountWordsInLines(words, line);
	}
	PrintMap(words);
}