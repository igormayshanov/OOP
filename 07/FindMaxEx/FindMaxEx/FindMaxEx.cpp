#include <iostream>
#include "FindMaxEx.h"

using namespace std;

int main()
{
	vector<Sportsman> arr{
		{ "John", 180, 60 },
		{ "Doe", 170, 70 },
		{ "Jane", 160, 80 },
	};

	Sportsman sportsman;
	cout << "Find max weight sportsman\n";
	FindMax(arr, sportsman, CWeightComparator());
	cout << sportsman.name << ", height = " << sportsman.height << ", weight = " << sportsman.weight << "\n";
	cout << "Find max height sportsman\n";
	FindMax(arr, sportsman, CHeightComparator());
	cout << sportsman.name << ", height = " << sportsman.height << ", weight = " << sportsman.weight << "\n";
	return 0;
}
