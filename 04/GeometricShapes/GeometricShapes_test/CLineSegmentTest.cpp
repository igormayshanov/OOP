#include "stdafx.h"
#include "../GeometricShapes/CLineSegment.h"

struct CLineSegmentFixtureZero
{
	CLineSegmentFixtureZero()
		: line(
			{ 0, 0 }, { 0, 0 }, 0)
	{
	}
	CLineSegment line;
};
BOOST_FIXTURE_TEST_SUITE(LineZero, CLineSegmentFixtureZero)
	BOOST_AUTO_TEST_CASE(GetArea_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetPerimetr(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetOutlineColor(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetStartPoint_x_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetStartPoint().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetStartPoint_y_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetStartPoint().m_y, 0);
	}
	BOOST_AUTO_TEST_CASE(GetEndPoint_x_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetEndPoint().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetEndPoint_y_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetEndPoint().m_y, 0);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CLineSegmentFixture
{
	double EPSILON = 0.001;
	CLineSegmentFixture()
		: line({ 1, 1 }, { 4, 1 }, 1)
	{
	}
	CLineSegment line;
};
BOOST_FIXTURE_TEST_SUITE(line, CLineSegmentFixture)
	BOOST_AUTO_TEST_CASE(GetArea_equal_0)
	{
		BOOST_CHECK_EQUAL(line.GetArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_3)
	{
		BOOST_CHECK((line.GetPerimetr() - 3) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_1)
	{
		BOOST_CHECK_EQUAL(line.GetOutlineColor(), 1);
	}
	BOOST_AUTO_TEST_CASE(GetStartPoint_x_equal_1)
	{
		BOOST_CHECK((line.GetStartPoint().m_x - 1) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetStartPoint_y_equal_1)
	{
		BOOST_CHECK((line.GetStartPoint().m_y - 1) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetEndPoint_x_equal_4)
	{
		BOOST_CHECK((line.GetEndPoint().m_x - 4) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetEndPoint_y_equal_1)
	{
		BOOST_CHECK((line.GetEndPoint().m_y - 1) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(ToString_equal_test_string)
	{
		std::string test = "Line segment, start point = "
			+ std::to_string(line.GetStartPoint().m_x) + ", " + std::to_string(line.GetStartPoint().m_y)
			+ ", end point = " + std::to_string(line.GetEndPoint().m_x) + ", " + std::to_string(line.GetEndPoint().m_y);
		BOOST_CHECK_EQUAL(line.ToString(), test);
	}
BOOST_AUTO_TEST_SUITE_END()