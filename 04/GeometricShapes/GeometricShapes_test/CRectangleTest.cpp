#include "stdafx.h"
#include "../GeometricShapes/CRectangle.h"

struct CRectangleFixtureZero
{
	CRectangleFixtureZero()
		: rect({ 0, 0 }, 0, 0, 0, 0)
	{
	}
	CRectangle rect;
};
BOOST_FIXTURE_TEST_SUITE(RectangleZero, CRectangleFixtureZero)
	BOOST_AUTO_TEST_CASE(GetArea_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetPerimetr(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetLeftTop_x_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetLeftTop().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetLeftTop_y_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetLeftTop().m_y, 0);
	}
	BOOST_AUTO_TEST_CASE(GetRightBottom_x_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetRightBottom().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetRightBottom_y_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetRightBottom().m_y, 0);
	}
	BOOST_AUTO_TEST_CASE(GetFillColor_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetFillColor(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_0)
	{
		BOOST_CHECK_EQUAL(rect.GetOutlineColor(), 0);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CRectangleFixture
{
	double EPSILON = 0.001;
	CRectangleFixture()
		: rect({ 1, 1 }, 5, 5, 1, 2)
	{
	}
	CRectangle rect;
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, CRectangleFixture)
	BOOST_AUTO_TEST_CASE(GetArea_equal_25)
	{
		BOOST_CHECK(std::fabs(rect.GetArea() - 25) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_20)
	{
		BOOST_CHECK(std::fabs(rect.GetPerimetr() - 20) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetLeftTop_x_equal_1)
	{
		BOOST_CHECK_EQUAL(rect.GetLeftTop().m_x, 1);
	}
	BOOST_AUTO_TEST_CASE(GetLeftTop_y_equal_1)
	{
		BOOST_CHECK_EQUAL(rect.GetLeftTop().m_y, 1);
	}
	BOOST_AUTO_TEST_CASE(GetRightBottom_x_equal_6)
	{
		BOOST_CHECK_EQUAL(rect.GetRightBottom().m_x, 6);
	}
	BOOST_AUTO_TEST_CASE(GetRightBottom_y_equal_6)
	{
		BOOST_CHECK_EQUAL(rect.GetRightBottom().m_y, 6);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_1)
	{
		BOOST_CHECK_EQUAL(rect.GetOutlineColor(), 1);
	}
	BOOST_AUTO_TEST_CASE(ToString_equal_test_string)
	{
		std::string test = "Rectangle, top left = "
			+ std::to_string(rect.GetLeftTop().m_x) + ", " 
			+ std::to_string(rect.GetLeftTop().m_y) 
			+ ", height = " + std::to_string(rect.GetHeight()) 
			+ ", width = " + std::to_string(rect.GetWidth()) 
			+ ", fillColor = " + std::to_string(rect.GetFillColor());
		BOOST_CHECK_EQUAL(rect.ToString(), test);
	}
BOOST_AUTO_TEST_SUITE_END()