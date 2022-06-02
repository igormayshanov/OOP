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
		//добавь более понятную подсказку для пользователя
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
		m_shapeStorage.push_back(circle);
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
		m_shapeStorage.push_back(triangle);
		m_output << "Triangle added"
				 << "\n";
	}
	else
	{
		m_output << "Invalid parametrs\n";
	}
	return true;
}

//можно выделить фабрику 
bool CShapeStorage::AddLine(std::istream& args)
{
	CPoint startPoint;
	CPoint endPoint;
	uint32_t outlineColor = 0;
	args >> startPoint.m_x >> startPoint.m_y >> endPoint.m_x >> endPoint.m_y >> outlineColor;
	if (!args.fail())
	{
		auto line = std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
		m_shapeStorage.push_back(line);
		m_output << "Line segment added"
				 << "\n";
	}
	else
	{
		m_output << "Invalid parametrs\n";
	}
	return true;
}

std::string CShapeStorage::GetMaxAreaShape() const
{
	if (m_shapeStorage.empty())
	{
		return "Storage is empty\n";
	}
	auto maxAreaShape = m_shapeStorage[0];
	for (auto& shape : m_shapeStorage)
	{
		maxAreaShape = maxAreaShape->GetArea() > shape->GetArea() ? maxAreaShape : shape;
	}
	// 1. логику с получением строки с площадью и периметром можно перенести
	// в toString родительского класса

	// 2.(проще) можно в main возвращать фигуру а собирать сроку будет код который его печатает
	return maxAreaShape->ToString()
		+ "\n" + "Outline color = "
		+ std::to_string(maxAreaShape->GetOutlineColor()) + "\n"
		+ "Area = " + std::to_string(maxAreaShape->GetArea())
		+ ", " + "Perimetr = " + std::to_string(maxAreaShape->GetPerimetr()) + "\n";
}

std::string CShapeStorage::GetMinPerimetrShape() const
{
	if (m_shapeStorage.empty())
	{
		return "Storage is empty\n";
	}
	auto minPerimetrShape = m_shapeStorage[0];
	for (auto& shape : m_shapeStorage)
	{
		minPerimetrShape = minPerimetrShape->GetPerimetr() > shape->GetPerimetr() ? shape : minPerimetrShape;
	}
	return minPerimetrShape->ToString() 
		+ "\n" + "Outline color = " 
		+ std::to_string(minPerimetrShape->GetOutlineColor()) + "\n"
		 + "Area = " + std::to_string(minPerimetrShape->GetArea()) 
		+ ", " + "Perimetr = " + std::to_string(minPerimetrShape->GetPerimetr()) + "\n";
}