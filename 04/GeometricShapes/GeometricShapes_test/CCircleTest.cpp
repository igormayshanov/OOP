#include "stdafx.h"
#include "../OOP/04/GeometricShapes/GeometricShapes/CCircle.h"

struct CCircleFixtureZero
{
	CCircleFixtureZero()
		: circle({ 0, 0 }, 0, 0, 0)
	{
	}
	CCircle circle;
};
BOOST_FIXTURE_TEST_SUITE(CircleZero, CCircleFixtureZero)

	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_0)
	{
		BOOST_CHECK_EQUAL(circle.GetPerimetr(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetCentr_x_equal_0)
	{
		BOOST_CHECK_EQUAL(circle.GetCenter().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetCentr_y_equal_0)
	{
		BOOST_CHECK_EQUAL(circle.GetCenter().m_y, 0);
	}
	BOOST_AUTO_TEST_CASE(GetFillColor_equal_0)
	{
		BOOST_CHECK_EQUAL(circle.GetFillColor(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_0)
	{
		BOOST_CHECK_EQUAL(circle.GetOutlineColor(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetRadius_equal_0)
	{
		BOOST_CHECK_EQUAL(circle.GetRadius(), 0);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CCircleFixture
{
	double EPSILON = 0.001;
	CCircleFixture()
		: circle({ 1, 1 }, 1, 2, 3)
	{
	}
	CCircle circle;
};

BOOST_FIXTURE_TEST_SUITE(Circle, CCircleFixture)

	BOOST_AUTO_TEST_CASE(GetArea_equal_pi)
	{
		BOOST_CHECK(std::fabs(circle.GetArea() - 3.14159) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_2piR)
	{
		BOOST_CHECK(std::fabs(circle.GetPerimetr() - 6.28318) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetCentr_x_equal_1)
	{
		BOOST_CHECK_EQUAL(circle.GetCenter().m_x, 1);
	}
	BOOST_AUTO_TEST_CASE(GetCentr_y_equal_1)
	{
		BOOST_CHECK_EQUAL(circle.GetCenter().m_y, 1);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_2)
	{
		BOOST_CHECK_EQUAL(circle.GetOutlineColor(), 2);
	}
	BOOST_AUTO_TEST_CASE(GetFillColor_equal_3)
	{
		BOOST_CHECK_EQUAL(circle.GetFillColor(), 3);
	}

BOOST_AUTO_TEST_SUITE_END()