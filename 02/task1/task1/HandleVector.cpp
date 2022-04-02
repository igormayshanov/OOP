#include "HandleVector.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <optional>


std::optional<std::vector<float>> FillVector(const std::string& readingString)
{
	std::vector<float> sourceVector;
	std::stringstream stringStream;
	stringStream.str(readingString);
	stringStream.setf(std::ios::fixed, std::ios::floatfield);
	stringStream.precision(3);
	float temp;
	while (!stringStream.eof())
	{
		// 1. из задания: Числа с плавающей точкой с точностью до 3х знаков
		stringStream >> temp;
		if (stringStream.fail())
		{
			return std::nullopt;
		}
		else
		{
			sourceVector.push_back(temp);
		}
	}
	return sourceVector;
}

float CalculateSumOfMinElements(std::vector<float>& inputVector, int numsOfMin)
{
	std::vector<float> tempVector = inputVector;
	float min;
	float sum = 0;
	for (int i = 0; i < numsOfMin; i++)
	{
		min = *min_element(tempVector.begin(), tempVector.end());
		sum += min;
		tempVector.erase(min_element(tempVector.begin(), tempVector.end()));
	}
	return sum;
}

// 2. либо исправить название, либо (более дорогой вариант) добавить в параметры функцию которая будет бра функциональность по суммированию
void AddNumberToVectorElements(std::vector<float>& inputVector, float sum)
{
	for (auto& i : inputVector)
	{
		i += sum;
	}
}