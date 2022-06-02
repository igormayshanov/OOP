#include "CRectangle.h"
#include "CPoint.h"

CRectangle::CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop(leftTop)
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
	return "Rectangle, top left = "
		+ std::to_string(GetLeftTop().m_x) + ", "
		+ std::to_string(GetLeftTop().m_y)
		+ ", height = " + std::to_string(std::round(GetHeight()))
		+ ", width = " + std::to_string(GetWidth())
		+ ", fillColor = " + std::to_string(GetFillColor());
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