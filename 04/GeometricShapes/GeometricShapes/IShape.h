#pragma once
#include "stdafx.h"

class IShape
{
public:
	virtual ~IShape(){};
	virtual double GetArea() = 0;
	virtual double GetPerimetr() = 0;
	virtual std::string ToString() = 0;
	virtual uint32_t GetOutlineColor() = 0;
};
