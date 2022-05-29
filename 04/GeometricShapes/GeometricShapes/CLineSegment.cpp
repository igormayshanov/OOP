#include "CLineSegment.h"
#include "CPoint.h"
#include "stdafx.h"

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea()
{
	return 0;
}

double CLineSegment::GetPerimetr()
{
	return sqrt(pow((m_endPoint.m_x - m_startPoint.m_x), 2) + pow((m_endPoint.m_y - m_startPoint.m_y), 2));
}

std::string CLineSegment::ToString()
{
	return "LineSegment";
}

uint32_t CLineSegment::GetOutlineColor()
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint()
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint()
{
	return m_endPoint;
}