#pragma once
#include "stdafx.h"
class CFunctionCall
{
public:
	CFunctionCall(std::string const& functionName)
		: m_functionName(functionName)
	{
		std::cout << "Entering " << m_functionName << "\n";
	}
	~CFunctionCall()
	{
		{
			std::cout << "Exiting " << m_functionName << "\n";
		}
	}

private:
	std::string const m_functionName;
};

void SayHello();
