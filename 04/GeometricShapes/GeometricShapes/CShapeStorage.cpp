#include "stdafx.h"
#include "CShapeStorage.h"
#include "CCircle.h"
#include "CRectangle.h"

using namespace std;
using namespace std::placeholders;

CShapeStorage::CShapeStorage(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "rectangle", bind(&CShapeStorage::AddRectangle, this, _1) },
		  { "circle", bind(&CShapeStorage::AddCircle, this, _1) },
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
	double x = 0, y = 0, width = 0, height = 0;
	uint32_t outlineColor, fillColor;
	args >> x >> y >> width >> height >> outlineColor >> fillColor;
	if (!args.fail())
	{
		CRectangle rect(x, y, width, height, outlineColor, fillColor);
		m_shapeStorage.push_back(&rect);
		m_output << "Rectangle added"
				 << "\n";
	}
	else
	{
		return false;
	}
	return true;
}

bool CShapeStorage::AddCircle(std::istream& args)
{
	double x = 0, y = 0, radius = 0;
	uint32_t outlineColor = 0, fillColor = 0;
	args >> x >> y >> radius >> outlineColor >> fillColor;
	if (!args.fail())
	{
		CCircle circle(x, y, radius, outlineColor, fillColor);
		m_shapeStorage.push_back(&circle);
		m_output << "Circle added"
				 << "\n";
	}
	else
	{
		return false;
	}
	return true;
}