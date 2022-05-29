#include "stdafx.h"
#include "CShapeStorage.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"

using namespace std;
using namespace std::placeholders;

CShapeStorage::CShapeStorage(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "rectangle", bind(&CShapeStorage::AddRectangle, this, _1) },
		  { "circle", bind(&CShapeStorage::AddCircle, this, _1) },
		  { "triangle", bind(&CShapeStorage::AddTriangle, this, _1) },
		  { "line", bind(&CShapeStorage::AddLine, this, _1) },
	  })
{
}

bool CShapeStorage::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);
	string action;
	strm >> action;
	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

bool CShapeStorage::AddRectangle(std::istream& args)
{
	CPoint leftTop;
	double width = 0, height = 0;
	uint32_t outlineColor, fillColor;
	args >> leftTop.m_x >> leftTop.m_y >> width >> height >> outlineColor >> fillColor;
	if (!args.fail())
	{
		auto rect = std::make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
		m_shapeStorage.emplace_back(std::move(rect));
		m_output << "Rectangle added"
				 << "\n";
	}
	else
	{
		m_output << "Invalid parametrs\n";
	}
	return true;
}

bool CShapeStorage::AddCircle(std::istream& args)
{
	CPoint centr;
	double radius = 0;
	uint32_t outlineColor = 0, fillColor = 0;
	args >> centr.m_x >> centr.m_y >> radius >> outlineColor >> fillColor;
	if (!args.fail())
	{
		auto circle = std::make_shared<CCircle>(centr, radius, outlineColor, fillColor);
		m_shapeStorage.emplace_back(std::move(circle));
		m_output << "Circle added"
				 << "\n";
	}
	else
	{
		m_output << "Invalid parametrs\n";
	}
	return true;
}

bool CShapeStorage::AddTriangle(std::istream& args)
{
	CPoint p1, p2, p3;
	uint32_t outlineColor = 0, fillColor = 0;
	args >> p1.m_x >> p1.m_y >> p2.m_x >> p2.m_y >> p3.m_x >> p3.m_y >> outlineColor >> fillColor;
	if (!args.fail())
	{
		auto triangle = std::make_shared<CTriangle>(p1, p2, p3, outlineColor, fillColor);
		m_shapeStorage.emplace_back(std::move(triangle));
		m_output << "Triangle added"
				 << "\n";
	}
	else
	{
		m_output << "Invalid parametrs\n";
	}
	return true;
}

bool CShapeStorage::AddLine(std::istream& args)
{
	CPoint startPoint;
	CPoint endPoint;
	uint32_t outlineColor = 0;
	args >> startPoint.m_x >> startPoint.m_y >> endPoint.m_x >> endPoint.m_y >> outlineColor;
	if (!args.fail())
	{
		auto line = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
		m_shapeStorage.emplace_back(std::move(line));
		m_output << "Line segment added"
				 << "\n";
	}
	else
	{
		m_output << "Invalid parametrs\n";
	}
	return true;
}

void CShapeStorage::GetMaxAreaShape() const
{
	if (m_shapeStorage.empty())
	{
		std::cout << "Storage is empty\n";
		return;
	}
	auto maxAreaShape = m_shapeStorage[0];
	for (auto& shape : m_shapeStorage)
	{
		maxAreaShape = maxAreaShape->GetArea() > shape->GetArea() ? maxAreaShape : shape;
	}
	std::cout << maxAreaShape->ToString() << "\n"
			  << "Outline color = " << maxAreaShape->GetOutlineColor() << "\n"
			  << "Area = " << maxAreaShape->GetArea() << ", "
			  << "Perimetr = " << maxAreaShape->GetPerimetr() << "\n";
}

void CShapeStorage::GetMinPerimetrShape() const
{
	if (m_shapeStorage.empty())
	{
		std::cout << "Storage is empty\n";
		return;
	}
	auto minPerimetrShape = m_shapeStorage[0];
	for (auto& shape : m_shapeStorage)
	{
		minPerimetrShape = minPerimetrShape->GetPerimetr() > shape->GetPerimetr() ? shape : minPerimetrShape;
	}
	std::cout << minPerimetrShape->ToString() << "\n"
			  << "Outline color = " << minPerimetrShape->GetOutlineColor() << "\n"
			  << "Area = " << minPerimetrShape->GetArea() << ", "
			  << "Perimetr = " << minPerimetrShape->GetPerimetr() << "\n";
}