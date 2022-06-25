#pragma once
#include "stdafx.h"

template <class Base>
class CPersonImpl:public Base
{
public:
	CPersonImpl(std::string surname, std::string name, std::string patronimic, std::string address)
		: m_name(name)
		, m_patronimic(patronimic)
		, m_surname(surname)
		, m_address(address)
	{
	}
	std::string GetName() const override
	{
		return m_name;
	}
	std::string GetPatronimic() const override
	{
		return m_patronimic;
	}
	std::string GetSurname() const override
	{
		return m_surname;
	}
	std::string GetAddress() const override
	{
		return m_address;
	}

private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronimic;
	std::string m_address;
};
