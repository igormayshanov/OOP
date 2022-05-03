#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

std::string RemoveExtraSpaces(std::string const& str)
{
	//1. 
	if (!str.empty())
	{
		std::string outputStr;
		size_t strBegin = str.find_first_not_of(' ');
		size_t strEnd = str.find_last_not_of(' ');
		if (strBegin != std::string::npos && strEnd != std::string::npos)
		{
			std::unique_copy(str.begin() + strBegin, str.begin() + strEnd + 1, std::back_inserter(outputStr),
				[](char c1, char c2) {
					return c1 == ' ' && c2 == ' ';
				});
			return outputStr;
		}
		else
			return "";
	}
	else
	{
		return "";
	}
}

void RemoveExtraSpacesFromLines(std::istream& input, std::ostream& output)
{
	std::string line;
	while (std::getline(input, line))
	{
		output << RemoveExtraSpaces(line);
		if (input.good())
		{
			output << "\n";
		}
	}
}