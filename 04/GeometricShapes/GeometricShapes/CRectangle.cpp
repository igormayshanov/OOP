#include "CRectangle.h"

CRectangle::CRectangle(double x, double y, double width, double height, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop({ x, y })
	, m_width(width)
	, m_height(height)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CRectangle::GetArea()
{
	return m_height * m_width;
}

double CRectangle::GetPerimetr()
{
	return 2 * m_height + 2 * m_width;
}

std::string CRectangle::ToString()
{
	return "Rectangle";
}

uint32_t CRectangle::GetOutlineColor()
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor()
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop()
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom()
{
	return { m_leftTop.m_x + m_width, m_leftTop.m_y + m_height };
}

double CRectangle::GetWidth()
{
	return m_width;
}

double CRectangle::GetHeight()
{
	return m_height;
}