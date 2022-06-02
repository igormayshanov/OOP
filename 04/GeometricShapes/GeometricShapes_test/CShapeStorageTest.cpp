#include "stdafx.h"
#include "../GeometricShapes/CCircle.h"
#include "../GeometricShapes/CLineSegment.h"
#include "../GeometricShapes/CPoint.h"
#include "../GeometricShapes/CRectangle.h"
#include "../GeometricShapes/CShapeStorage.h"
#include "../GeometricShapes/CTriangle.h"
#include <boost/optional.hpp>
#include <sstream>

using namespace std;
using boost::none;
using boost::optional;

// «ависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструировани€ самого remote-контрола
struct ShapeStorageDependencies
{
	// CCircle circle;
	stringstream input;
	stringstream output;
};

struct ShapeStorageFixture : ShapeStorageDependencies
{
	CShapeStorage shapes;

	ShapeStorageFixture()
		: shapes(input, output)
	{
	}
	// ¬спомогательна€ функци€ дл€ проверки работы команды command
	// ќна принимает ожидаемый номер канала expectedChannel и expectedOutput

	//нехватает проверки на реакцию на незнакомые команды
	void VerifyCommandHandling(const string& command, const string& expectedOutput)
	{
		// ѕредварительно очищаем содержимое выходного потока
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(shapes.HandleCommand());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Shape_Storage, ShapeStorageFixture)
	BOOST_AUTO_TEST_CASE(handle_add_rectangle_with_correct_params)
	{
		VerifyCommandHandling("rectangle 1 1 10 22 1 3", "Rectangle added\n");
	}
	BOOST_AUTO_TEST_CASE(handle_add_rectangle_without_all_param)
	{
		VerifyCommandHandling("rectangle 1 1 10 22 1", "Invalid parametrs\n");
	}
	BOOST_AUTO_TEST_CASE(handle_add_circle_with_correct_params)
	{
		VerifyCommandHandling("circle 1 1 1 2 3", "Circle added\n");
	}
	BOOST_AUTO_TEST_CASE(handle_add_circle_without_all_param)
	{
		VerifyCommandHandling("circle 1 1 1 2", "Invalid parametrs\n");
	}
	BOOST_AUTO_TEST_CASE(handle_add_triangle_with_correct_params)
	{
		VerifyCommandHandling("triangle 1 1 3 1 6 6 1 2", "Triangle added\n");
	}
	BOOST_AUTO_TEST_CASE(handle_add_triangle_without_all_param)
	{
		VerifyCommandHandling("triangle 1 1 3 1 6 6 1", "Invalid parametrs\n");
	}

	BOOST_AUTO_TEST_CASE(GetMaxAreaShape_equal_test_string)
	{
		VerifyCommandHandling("triangle 1 1 3 1 6 6 1 2", "Triangle added\n");
		VerifyCommandHandling("circle 1 1 3 1 2", "Circle added\n");
		VerifyCommandHandling("rectangle 1 1 10 11 1 2", "Rectangle added\n");
		std::string test = "Rectangle, top left = 1.000000, 1.000000, height = 11.000000, width = 10.000000, fillColor = 2\nOutline color = 1\nArea = 110.000000, Perimetr = 42.000000\n";
		BOOST_CHECK_EQUAL(shapes.GetMaxAreaShape(), test);
	}
	BOOST_AUTO_TEST_CASE(GetMinAreaShape_equal_test_string)
	{
		VerifyCommandHandling("triangle 1 1 3 1 8 8 1 2", "Triangle added\n");
		VerifyCommandHandling("circle 1 1 3 1 2", "Circle added\n");
		VerifyCommandHandling("rectangle 1 1 10 11 1 2", "Rectangle added\n");
		std::string test = "Circle, centr = 1.000000, 1.000000, radius = 3.000000, fill color = 2\nOutline color = 1\nArea = 28.274334, Perimetr = 18.849556\n";
		BOOST_CHECK_EQUAL(shapes.GetMinPerimetrShape(), test);
	}
	BOOST_AUTO_TEST_CASE(GetMinAreaShape_in_empty_storage)
	{
		std::string test = "Storage is empty\n";
		BOOST_CHECK_EQUAL(shapes.GetMinPerimetrShape(), test);
	}

BOOST_AUTO_TEST_SUITE_END()