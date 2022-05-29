#include "stdafx.h"
#include "CTriangle.h"
#include "CLineSegment.h"

CTriangle::CTriangle(double x1, double y1, double x2, double y2, double x3, double y3,
	uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1({ x1, y1 })
	, m_vertex2({ x2, y2 })
	, m_vertex3({ x3, y3 })
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CTriangle::GetArea()
{
	double p = GetPerimetr() / 2;
	return sqrt(p * (p - GetSides()[0]) * (p - GetSides()[1]) * (p - GetSides()[2]));
}

double CTriangle::GetPerimetr()
{
	double p = 0;
	for (auto& i : GetSides())
	{
		p += i;
	}
	return p;
}

std::vector<double> CTriangle::GetSides()
{
	CLineSegment a(m_vertex1, m_vertex2, m_outlineColor);
	CLineSegment b(m_vertex2, m_vertex3, m_outlineColor);
	CLineSegment c(m_vertex1, m_vertex3, m_outlineColor);
	std::vector<double> sides{ a.GetPerimetr(), b.GetPerimetr(), c.GetPerimetr() };
	return sides;
}

std::string CTriangle::ToString()
{
	return "CTriangle";
}

uint32_t CTriangle::GetOutlineColor()
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor()
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1()
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2()
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3()
{
	return m_vertex3;
}