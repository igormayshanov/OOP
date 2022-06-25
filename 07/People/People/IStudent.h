#pragma once
#include "IPerson.h"
class IStudent : public IPerson
{
public:
	virtual ~IStudent() = default;
	virtual std::string GetUniversity() const;
	virtual unsigned int GetStudentTicketNumber() const;
};
