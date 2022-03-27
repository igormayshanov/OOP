#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

std::string RemoveExtraSpaces(std::string const& arg)
{
	std::string outputStr;
	size_t strBegin = arg.find_first_not_of(' ');
	size_t strEnd = arg.find_last_not_of(' ');
	std::unique_copy(arg.begin() + strBegin, arg.begin() + strEnd + 1, std::back_inserter(outputStr),
		[](char c1, char c2)
		{
			return c1 == ' ' && c2 == ' ';
		});
	return outputStr;
}

void RemoveExtraSpacesFromLines(std::istream& input, std::ostream& output)
{
	std::string line;
	while (std::getline(input, line))
	{
		output << RemoveExtraSpaces(line);
		if (output.good())
		{
			output << "\n";
		}
	}
}
