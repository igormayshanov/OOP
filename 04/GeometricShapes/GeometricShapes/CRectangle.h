#pragma once
#include "stdafx.h"
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double height, uint32_t outlineColor, uint32_t fillColor);
	double GetArea() override;
	double GetPerimetr() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;

	uint32_t GetFillColor() override;

	CPoint GetLeftTop();
	CPoint GetRightBottom();
	double GetWidth();
	double GetHeight();

private:
	CPoint m_leftTop;
	double m_width, m_height;
	uint32_t m_outlineColor, m_fillColor;
};
