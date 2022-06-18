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
	std::stringstream stream;
	std::stringstream comparisonStream;
};

void InitStackThreeElems(CStringStack& stack)
{
	stack.Push("ONE");
	stack.Push("TWO");
	stack.Push("THREE");
}

BOOST_FIXTURE_TEST_SUITE(Stack, CStringStackEmpty)

	BOOST_AUTO_TEST_CASE(empty_stack_return_empty)
	{
		BOOST_CHECK(stack.IsEmpty());
		BOOST_CHECK_EQUAL(stack.Size(), 0);
	}
	BOOST_AUTO_TEST_CASE(push_string_ONE_must_return_from_top_string_ONE)
	{
		stack.Push("ONE");
		BOOST_CHECK(!stack.IsEmpty());
		BOOST_CHECK_EQUAL(stack.Top(), "ONE");
		BOOST_CHECK_EQUAL(stack.Size(), 1);
	}
	BOOST_AUTO_TEST_CASE(pop_element_from_stack_with_one_element_must_return_empty_stack)
	{
		stack.Push("ONE");
		stack.Pop();
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(print_element_from_stack_with_tree_elements_TREE_TWO_ONE)
	{
		InitStackThreeElems(stack);
		comparisonStream << "THREE\nTWO\nONE\n";
		stack.Print(stream);
		BOOST_CHECK_EQUAL(stack.Top(), "THREE");
		BOOST_CHECK_EQUAL(stream.str(), comparisonStream.str());
	}
	BOOST_AUTO_TEST_CASE(clear_stack_with_tree_elements_TREE_TWO_ONE_stack_must_be_empty)
	{
		InitStackThreeElems(stack);
		stack.Clear();
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(copy_stack_with_tree_elements_TREE_TWO_ONE_to_stack2_stack_must_be_equal_stack2)
	{
		InitStackThreeElems(stack);
		CStringStack stack2 = stack;
		stack2.Print(stream);
		stack.Print(comparisonStream);
		BOOST_CHECK_EQUAL(stack2.Top(), "THREE");
		BOOST_CHECK_EQUAL(stack2.Size(), stack.Size());
		BOOST_CHECK_EQUAL(stream.str(), comparisonStream.str());
	}
	BOOST_AUTO_TEST_CASE(copy_stack_with_tree_elements_delete_original_stack_the_copied_object_must_not_destroy)
	{
		InitStackThreeElems(stack);
		CStringStack stack2 = stack;
		stack.Clear();
		comparisonStream << "THREE\nTWO\nONE\n";
		stack2.Print(stream);
		BOOST_CHECK(stack.IsEmpty());
		BOOST_CHECK(!stack2.IsEmpty());
		BOOST_CHECK_EQUAL(stream.str(), comparisonStream.str());
	}
	BOOST_AUTO_TEST_CASE(move_stack_with_tree_elements_original_stack_must_be_destroyed)
	{
		InitStackThreeElems(stack);
		CStringStack stack2 = std::move(stack);
		comparisonStream << "THREE\nTWO\nONE\n";
		stack2.Print(stream);
		BOOST_CHECK(stack.IsEmpty());
		BOOST_CHECK(!stack2.IsEmpty());
		BOOST_CHECK_EQUAL(stack2.Size(), 3);
		BOOST_CHECK_EQUAL(stream.str(), comparisonStream.str());
	}
	BOOST_AUTO_TEST_CASE(test_self_assignment_with_copy_assignment_operator)
	{
		InitStackThreeElems(stack);
		stack = stack;
		comparisonStream << "THREE\nTWO\nONE\n";
		stack.Print(stream);
		BOOST_CHECK_EQUAL(stream.str(), comparisonStream.str());
		BOOST_CHECK_NO_THROW(stack = stack, exception);
	}
	BOOST_AUTO_TEST_CASE(test_self_move_with_move_assignment_operator)
	{
		InitStackThreeElems(stack);
		stack = std::move(stack);
		comparisonStream << "THREE\nTWO\nONE\n";
		stack.Print(stream);
		BOOST_CHECK_EQUAL(stream.str(), comparisonStream.str());
		BOOST_CHECK_NO_THROW(stack = std::move(stack), exception);
	}

BOOST_AUTO_TEST_SUITE_END()

template <typename Ex, typename Fn>
void ExpectException(Fn&& fn, const string& expectedDescription)
{
	// Проверяем, что вызов fn() выбросит исключение типа Ex
	// с описанием, равным expectedDescription
	BOOST_CHECK_EXCEPTION(fn(), Ex, [&](const Ex& e) {
		return e.what() == expectedDescription;
	});
}

BOOST_FIXTURE_TEST_SUITE(TestStackExeptions, CStringStackEmpty)
	BOOST_AUTO_TEST_CASE(can_not_remove_an_element_from_an_empty_stack)
	{
		ExpectException<logic_error>([&] {
			stack.Pop();
		},
			"Stack is empty");
	}
	BOOST_AUTO_TEST_CASE(can_not_take_top_element_from_an_empty_stack)
	{
		ExpectException<logic_error>([&] {
			stack.Top();
		},
			"Stack is empty");
	}
BOOST_AUTO_TEST_SUITE_END()