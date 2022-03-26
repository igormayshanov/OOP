#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <optional>

#include "HandleVector.h"

using namespace std;

int main()
{
	const int numsOfMin = 3;
	std::cout << "Enter " << numsOfMin << " and more float numbers separated by spaces :\n";
	std::string readingString;
	getline(cin, readingString);

	auto sourceVector = FillVector(readingString);
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
		sum = CalculateSumOfMinElements(originVector, numsOfMin);
		resultVector = AddNumberToVectorElements(originVector, sum);
	}
	else
	{
		std::cout << "Error, less than " << numsOfMin << " numbers entered\n";
		return 1;
	}	
	sort(resultVector.begin(), resultVector.end());
	cout.setf(std::ios::fixed);
	cout.precision(3);
	copy(resultVector.begin(), resultVector.end(), ostream_iterator<float>(cout, " "));
	return 0;
}

