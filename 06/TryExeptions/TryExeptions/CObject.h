#pragma once
#include "stdafx.h"
class CObject
{
public:
	CObject(std::string const& objectName)
		: m_objectName(objectName)
	{
		std::cout << m_objectName << " is being created\n";
	}
	~CObject()
	{
		std::cout << m_objectName << " is being destroyed\n";
	}
private:
	std::string const m_objectName;
};
