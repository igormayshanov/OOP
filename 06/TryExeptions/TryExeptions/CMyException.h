#pragma once
#include "stdafx.h"

class CMyException
{
public:
	CMyException()
		: m_copy(0)
	{
		std::cout << "CMyException is being created\n";
	}

	int GetCopyIndex() const
	{
		return m_copy;
	}

	// конструктор копирования будет создавать не совсем точную копию, т.к.
	// еще отслеживает и номер копии
	CMyException(CMyException const& e)
		: m_copy(e.m_copy + 1)
	{
		std::cout << "CMyException copy #" << m_copy << " is being created\n";
	}

	~CMyException()
	{
		std::cout << "CMyException copy #" << m_copy << " is being destroyed\n";
	}

private:
	int m_copy;
};
