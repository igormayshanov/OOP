#pragma once

#include <string>
#include <vector>
#include <optional>

std::optional<std::vector<float>> FillVector(const std::string& readingString);
std::vector<float> AddNumberToVectorElements(std::vector<float>& inputVector, float sum);
float CalculateSumOfMinElements(std::vector<float>& inputVector, int numsOfMin);