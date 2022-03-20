#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <optional>

using namespace std;
std::optional<std::vector<float>> GetSourceVector(const std::string& readingString);
std::vector<float> HandleVector(std::vector<float>& inputVector, float sum);
float CalculateSumOfThreeMinElements(std::vector<float>& inputVector, int numsOfMin);

int main()
{
	const int numsOfMin = 3;
	std::cout << "Enter " << numsOfMin << " and more float numbers separated by spaces :\n ";
	std::string readingString;
	getline(cin, readingString);
	auto sourceVector = GetSourceVector(readingString);
	if (!sourceVector)
	{
		std::cout << "Error, invalid input\n";
		return 1;
	}
	std::vector<float> originVector = *sourceVector;
	std::vector<float> resultVector;
	float sum = 0;
	if (originVector.size() >= numsOfMin)
	{
		sum = CalculateSumOfThreeMinElements(originVector, numsOfMin);
		resultVector = HandleVector(originVector, sum);
	}
	else
	{
		std::cout << "Error, less than " << numsOfMin << " numbers entered\n";
		return 1;
	}	
	sort(resultVector.begin(), resultVector.end());
	copy(resultVector.begin(), resultVector.end(), ostream_iterator<float>(cout, " "));
	return 0;
}

std::optional<std::vector<float>> GetSourceVector(const std::string& readingString)
{
	std::vector<float> sourceVector;
	std::stringstream stringStream;
	stringStream.str(readingString);
	float temp;
	while (!stringStream.eof())
	{
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

float CalculateSumOfThreeMinElements(std::vector<float>& inputVector, int numsOfMin)
{
	std::vector<float> tempVector = inputVector;
	float min;
	float sum = 0;
	for (int i=0;i<numsOfMin;i++)
	{
		min = *min_element(tempVector.begin(), tempVector.end());
		sum += min;
		tempVector.erase(min_element(tempVector.begin(), tempVector.end()));
	}
	return sum;
}

std::vector<float> HandleVector(std::vector<float>& inputVector, float sum)
{
	std::vector<float> resultVector = inputVector;
	for (auto& i : resultVector)
	{
		i += sum;
	}
	return resultVector;
}