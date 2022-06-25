#pragma once
#include "stdafx.h"

class IPerson
{
public:
	virtual ~IPerson() = default;
	virtual std::string GetName() const;
	virtual std::string GetSurname() const;
	virtual std::string GetPatronimic() const;
	virtual std::string GetAddress() const;
};
