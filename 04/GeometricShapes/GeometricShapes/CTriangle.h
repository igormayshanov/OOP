#pragma once
#include "stdafx.h"
#include "ISolidShape.h"
#include "CPoint.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(double x1, double y1,
			double x2, double y2,
			double x3, double y3,
			uint32_t outlineColor, uint32_t fillColor);
	double GetArea() override;
	double GetPerimetr() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;
	uint32_t GetFillColor() override;

	CPoint GetVertex1();
	CPoint GetVertex2();
	CPoint GetVertex3();

private:
	std::vector<double> GetSides();
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	uint32_t m_outlineColor, m_fillColor;
};