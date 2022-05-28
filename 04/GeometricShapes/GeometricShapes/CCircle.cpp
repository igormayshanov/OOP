#include "CCircle.h"
#include "stdafx.h"


CCircle::CCircle(double x, double y, double radius, uint32_t outlineColor, uint32_t fillColor)
	: m_centr({ x, y })
	, m_radius(radius)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CCircle::GetArea()
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimetr()
{
	return 2 * m_radius * M_PI;
}

std::string CCircle::ToString()
{
	return "Circle";
}

uint32_t CCircle::GetOutlineColor()
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor()
{
	return m_fillColor;
}

CPoint CCircle::GetCenter()
{
	return m_centr;
}

double CCircle::GetRadius()
{
	return m_radius;
}

