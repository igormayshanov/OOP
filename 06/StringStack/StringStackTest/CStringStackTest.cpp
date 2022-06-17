#include "stdafx.h"
#include "../StringStack/CStringStack.h"
#include <math.h>

using namespace std;

struct CStringStackEmpty
{
	CStringStackEmpty()
		: stack()
	{
	}
	CStringStack stack;
};

BOOST_FIXTURE_TEST_SUITE(Stack, CStringStackEmpty)

	BOOST_AUTO_TEST_CASE(empty_stack_return)
	{
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(push_string_ONE_must_return_from_top_string_ONE)
	{
		stack.Push("ONE");
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_CHECK_EQUAL(stack.Top(), "ONE");
	}
	BOOST_AUTO_TEST_CASE(pop_element_from_stack_with_one_element_must_return_empty_stack)
	{
		stack.Push("ONE");
		stack.Pop();
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(print_element_from_stack_with_tree_elements_TREE_TWO_ONE)
	{
		stack.Push("ONE");
		stack.Push("TWO");
		stack.Push("THREE");
		std::stringstream stream;
		std::stringstream comparisonOutputStream;
		comparisonOutputStream << "THREE\nTWO\nONE\n";
		stack.Print(stream);
		BOOST_CHECK_EQUAL(stack.Top(), "THREE");
		BOOST_CHECK_EQUAL(stream.str(), comparisonOutputStream.str());
	}
	BOOST_AUTO_TEST_CASE(erase_stack_with_tree_elements_TREE_TWO_ONE)
	{
		stack.Push("ONE");
		stack.Push("TWO");
		stack.Push("THREE");
		stack.Erase();
		BOOST_CHECK(stack.IsEmpty());
	}
BOOST_AUTO_TEST_SUITE_END()