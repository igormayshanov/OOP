#include "stdafx.h"
#include "CTriangle.h"
#include <iostream>

using namespace std;

vector<double> GetSidesFromInput(istream& cin)
{
	vector<double> sides(3, 0);
	string inputLine;
	getline(cin, inputLine);
	istringstream strm(inputLine);
	for (int i = 0; i < 3; ++i)
	{
		double side;
		strm >> side;
		sides[i] = side;
		if (strm.fail())
		{
			throw std::invalid_argument("Invalid argument in position " + to_string(i+1));
		}
	}
	return sides;	
}

int main()
{
	vector<double> sides;
	while (!cin.eof() && !cin.fail())
	{
		cout << "Enter the sides of triangle > ";
		try
		{
			vector<double> sides(3, 0);
			sides = GetSidesFromInput(cin);
			CTriangle triangle(sides[0], sides[1], sides[2]);
			cout << "Perimetr = " << triangle.GetPerimeter() << ", "
				 << "area = " << triangle.GetArea() << "\n";
		}
		catch (logic_error const& e)
		{
			cout << e.what() << "\n";
		}
	}
	return 0;
}