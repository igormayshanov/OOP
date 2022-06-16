#include "stdafx.h"
#include "../Triangle/CTriangle.h"

struct CTriangleFixtureZero
{
	CTriangleFixtureZero()
		: triangle(0, 0, 0)
	{
	}
	CTriangle triangle;
};

BOOST_FIXTURE_TEST_SUITE(TriangleZero, CTriangleFixtureZero)

	BOOST_AUTO_TEST_CASE(triangle_sides_init_0_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetSide1(), 0);
		BOOST_CHECK_EQUAL(triangle.GetSide2(), 0);
		BOOST_CHECK_EQUAL(triangle.GetSide3(), 0);
	}
	BOOST_AUTO_TEST_CASE(triangle_perimetr_init_0_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetPerimeter(), 0);
	}
	BOOST_AUTO_TEST_CASE(triangle_area_init_0_equal_0)
	{
		BOOST_CHECK_EQUAL(triangle.GetArea(), 0);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CTriangleFixtureEquilateral
{
	double EPSILON = 0.001;
	CTriangleFixtureEquilateral()
		: triangle(2, 2, 2)
	{
	}
	CTriangle triangle;
};

BOOST_FIXTURE_TEST_SUITE(TriangleEquilateral, CTriangleFixtureEquilateral)
	BOOST_AUTO_TEST_CASE(equilateral_triangle_with_side_equal_2_perimetr_equal_6)
	{
		BOOST_CHECK(std::fabs(triangle.GetPerimeter() - 6) < EPSILON);
	}
	BOOST_AUTO_TEST_CASE(equilateral_triangle_with_side_equal_2_area_equal_1_732)
	{
		BOOST_CHECK(std::fabs(triangle.GetArea() - 1.7320508) < EPSILON);
	}

	BOOST_AUTO_TEST_CASE(triangle_sides_init_2_equal_2)
	{
		BOOST_CHECK_EQUAL(triangle.GetSide1(), 2);
		BOOST_CHECK_EQUAL(triangle.GetSide2(), 2);
		BOOST_CHECK_EQUAL(triangle.GetSide3(), 2);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(triangle_sides_init_negative_value_should_throw_an_exception_invalid_argument)
{
	BOOST_CHECK_THROW(CTriangle triangle(-1, -2, -3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(triangle_sides_init_uncorrect_value_should_throw_an_exception_domain_error)
{
	BOOST_CHECK_THROW(CTriangle triangle(6, 2, 3), std::domain_error);
}