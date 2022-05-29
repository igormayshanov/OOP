#pragma once
#include "stdafx.h"
#include "IShape.h"
#include "CPoint.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor);
	double GetArea() override;
	double GetPerimetr() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;

	CPoint GetStartPoint();
	CPoint GetEndPoint();
	
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	uint32_t m_outlineColor;
};