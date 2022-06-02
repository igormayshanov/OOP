#include "stdafx.h"
#include "../GeometricShapes/CTriangle.h"

struct CTriangleFixtureZero
{
	CTriangleFixtureZero()
		: triangle(
			{ 0, 0 }, { 0, 0 }, { 0, 0 }, 0, 0)
	{
	}
	CTriangle triangle;
};
BOOST_FIXTURE_TEST_SUITE(TriangleZero, CTriangleFixtureZero)
// добавить понятные описания, что проверяет тест, какой результат ожидается
	BOOST_AUTO_TEST_CASE(GetArea_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetPerimetr(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetFillColor_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetFillColor(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), 0);
	}
	BOOST_AUTO_TEST_CASE(GetVertex1_x_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex1().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetVertex1_y_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex1().m_y, 0);
	}
	BOOST_AUTO_TEST_CASE(GetVertex2_x_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex2().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetVertex2_y_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex2().m_y, 0);
	}
	BOOST_AUTO_TEST_CASE(GetVertex3_x_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex3().m_x, 0);
	}
	BOOST_AUTO_TEST_CASE(GetVertex3_y_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex3().m_y, 0);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CTriangleFixture
{
	double EPSILON = 0.001;
	CTriangleFixture()
		: triangle(
			{ 1, 1 }, { 3, 1 }, { 6, 6 }, 1, 2)
	{
	}
	CTriangle triangle;
};
BOOST_FIXTURE_TEST_SUITE(Triangle, CTriangleFixture)
	BOOST_AUTO_TEST_CASE(GetArea_equal_5)
	{
		BOOST_CHECK((triangle.GetArea() - 5) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetPerimetr_equal_14_9)
	{
		BOOST_CHECK((triangle.GetPerimetr() - 14.902) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(GetFillColor_equal_2)
	{
		BOOST_CHECK_EQUAL(triangle.GetFillColor(), 2);
	}
	BOOST_AUTO_TEST_CASE(GetOutlineColor_equal_1)
	{
		BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), 1);
	}
	BOOST_AUTO_TEST_CASE(GetVertex1_x_equal_1)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex1().m_x, 1);
	}
	BOOST_AUTO_TEST_CASE(GetVertex1_y_equal_1)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex1().m_y, 1);
	}
	BOOST_AUTO_TEST_CASE(GetVertex2_x_equal_3)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex2().m_x, 3);
	}
	BOOST_AUTO_TEST_CASE(GetVertex2_y_equal_1)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex2().m_y, 1);
	}
	BOOST_AUTO_TEST_CASE(GetVertex3_x_equal_6)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex3().m_x, 6);
	}
	BOOST_AUTO_TEST_CASE(GetVertex3_y_equal_6)
	{
		BOOST_CHECK_EQUAL(triangle.GetVertex3().m_y, 6);
	}
	BOOST_AUTO_TEST_CASE(ToString_equal_test_string)
	{
		std::string test = "Triangle, vertex1 = "
			+ std::to_string(triangle.GetVertex1().m_x) + ", " + std::to_string(triangle.GetVertex1().m_y)
			+ ", vertex2 = " + std::to_string(triangle.GetVertex2().m_x) + ", " + std::to_string(triangle.GetVertex2().m_y)
			+ ", vertex3 = " + std::to_string(triangle.GetVertex3().m_x) + ", " + std::to_string(triangle.GetVertex3().m_y)
			+ ", fillColor = " + std::to_string(triangle.GetFillColor());
		BOOST_CHECK_EQUAL(triangle.ToString(), test);
	}
BOOST_AUTO_TEST_SUITE_END()
