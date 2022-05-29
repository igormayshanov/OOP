#pragma once
#include "stdafx.h"
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint centr, double radius, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() override;
	double GetPerimetr() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;

	uint32_t GetFillColor() override;

	CPoint GetCenter();
	double GetRadius();

private:
	CPoint m_centr;
	double m_radius;
	uint32_t m_outlineColor, m_fillColor;
};