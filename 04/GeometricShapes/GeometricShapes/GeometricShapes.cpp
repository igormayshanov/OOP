#include "stdafx.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CShapeStorage.h"
#include "CTriangle.h"

using namespace std;

int main()
{
	CShapeStorage shapes(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!shapes.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	cout << "Max area shape:\n";
	shapes.GetMaxAreaShape();
	cout << "Min perimetr shape:\n";
	shapes.GetMinPerimetrShape();
	return 0;
}