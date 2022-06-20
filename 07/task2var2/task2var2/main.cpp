#include <iostream>
#include "CMyStack.h"
#include "stdafx.h"

using namespace std;

int main()
{
	CMyStack<int> stack;
	stack.Push(1);
	stack.Push(2);
	cout << stack.Top() << "\n";
	stack.Print(cout);

	CMyStack<string> stack1;
	stack1.Push("Hello");
	stack1.Push("World");
	cout << stack1.Top() << "\n";
	stack1.Print(cout);
}
