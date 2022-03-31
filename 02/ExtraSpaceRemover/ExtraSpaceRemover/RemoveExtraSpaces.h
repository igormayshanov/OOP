#pragma once
#include <string>

std::string RemoveExtraSpaces(std::string const& str);
void RemoveExtraSpacesFromLines(std::istream& input, std::ostream& output);
