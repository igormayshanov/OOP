#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	cout << "Enter the line:\n";
	string inputString;
	getline(cin, inputString);
	std::stringstream stringStream;
	stringStream.str(inputString);
	cout << inputString << "\n";
	std::string line;
	vector<string> wordVector;
	string delimetr = " ';,:";
	while (stringStream >> line)
	{
		cout << "output " << line << "\n";
		std::size_t prev = 0, pos;
		while ((pos = line.find_first_of(delimetr, prev)) != std::string::npos)
		{
			if (pos > prev)
				wordVector.push_back(line.substr(prev, pos - prev));
			prev = pos + 1;
		}
		if (prev < line.length())
			wordVector.push_back(line.substr(prev, std::string::npos));
	}
	for (auto& i : wordVector)
	{
		cout << i << "\n";
	}
}