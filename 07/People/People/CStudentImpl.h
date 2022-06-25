#pragma once
#include "CPersonImpl.h"
template <class Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	CStudentImpl(std::string university, unsigned int studentTicketNumber)
		: m_university(university)
		, m_studentTicketNumber(studentTicketNumber)
	{
	}
	std::string GetUniversity() const override
	{
		return m_university;
	}
	unsigned int GetStudentTicketNumber() const override
	{
		return m_studentTicketNumber;
	}

private:
	std::string m_university;
	unsigned int m_studentTicketNumber;
};
