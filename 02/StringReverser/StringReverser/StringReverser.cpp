#include <iostream>
#include "Reverse.h"

using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		cout << Reverse(line) << "\n";
	}
}

