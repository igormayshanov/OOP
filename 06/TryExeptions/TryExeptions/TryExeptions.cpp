#include "stdafx.h"
#include "CFunctionCall.h"
#include "CObject.h"
#include "CMyException.h"
#include <iostream>

void Function2()
{
	CFunctionCall fn("Function2()");

	CObject obj4("obj4");

	CObject* pobj5 = new CObject("pObj5");

	std::cout << "Throwing an exception\n";
	throw CMyException();
}

void Function1()
{
	CFunctionCall fn("Function1()");

	CObject obj2("obj2");
	{
		CObject obj3("obj3");
	}

	Function2();
}


int main(int argc, char* argv[])
{
	/*CObject object1("object1");
	{
		CObject object2("object2");
		CObject object3("object3");
	}
	CObject object4("object4");
	CObject* pObject5 = new CObject("pObject5");

	CFunctionCall main("main()");
	SayHello();*/

	CFunctionCall fn("main()");

	try
	{
		CObject obj1("obj1");
		Function1();
	}
	catch (CMyException const& e)
	{
		std::cout << "CMyException is caught. Copy # " << e.GetCopyIndex() << "\n";
	}

	return 0;
}
