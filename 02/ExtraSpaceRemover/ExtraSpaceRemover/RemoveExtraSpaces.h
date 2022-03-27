#pragma once
#include <string>

std::string RemoveExtraSpaces(std::string const& arg);
void RemoveExtraSpacesFromLines(std::istream& input, std::ostream& output);
