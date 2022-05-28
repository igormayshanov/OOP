#include "stdafx.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CShapeStorage.h"

using namespace std;

int main()
{
	/*CRectangle rect(10, 10, 20, 30, 123, 321);
	cout << rect.ToString() << ", " << rect.GetLeftTop().m_x << ", " << rect.GetLeftTop().m_y << ", " << rect.GetHeight() << "\n";
	
	CCircle circle(1, 1, 30, 123, 321);
	cout << M_PI << ", " << circle.GetRadius() << ", " << circle.GetArea() << ", " << circle.GetFillColor() << "\n";
	vector<IShape*> v;

	v.push_back(&rect);
	v.push_back(&circle);
	for (auto& i : v)
	{
		cout << i->GetArea() << "\n";
	}*/

	CShapeStorage shapes(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!shapes.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}