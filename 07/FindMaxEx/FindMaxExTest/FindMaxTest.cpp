#include "stdafx.h"
#include "../FindMaxEx/FindMaxEx.h"

using namespace std;

struct FindMaxExFixture
{
	vector<int> emptyArr;
	vector<int> intArr{ 1, 2, 3, 4, 5 };
	vector<float> floatArr{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	vector<string> stringArr{ "one", "two", "three", "four" };
	vector<const char*> charArr{ "one", "two", "three", "four" };
	vector<Sportsman> sportsmanArr
	{
		{ "John", 180, 60 },
		{ "Doe", 170, 70 },
		{ "Jane", 160, 80 },
	};
};

BOOST_FIXTURE_TEST_SUITE(Find_max, FindMaxExFixture)
	BOOST_AUTO_TEST_SUITE(test_empty_array)
		BOOST_AUTO_TEST_CASE(empty_array_return_false)
		{
			int max = 0;
			BOOST_CHECK(!FindMax(emptyArr, max, CComparator<int>()));
			BOOST_CHECK_EQUAL(max, 0);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(return_max_from_int_array_equal_5)
	{
		int max = 0;
		BOOST_CHECK(FindMax(intArr, max, CComparator<int>()));
		BOOST_CHECK_EQUAL(max, 5);
	}
	BOOST_AUTO_TEST_CASE(return_max_from_float_array_equal_5_5)
	{
		float max = 0;
		BOOST_CHECK(FindMax(floatArr, max, CComparator<float>()));
		BOOST_CHECK_EQUAL(max, 5.5);
	}
	BOOST_AUTO_TEST_CASE(return_max_from_string_array_equal_two)
	{
		string max;
		BOOST_CHECK(FindMax(stringArr, max, CComparator<float>()));
		BOOST_CHECK_EQUAL(max, "two");
	}
	BOOST_AUTO_TEST_CASE(return_max_from_char_array_equal_two)
	{
		const char* max;
		BOOST_CHECK(FindMax(charArr, max, CComparator<const char*>()));
		BOOST_CHECK_EQUAL(max, "two");
	}
	BOOST_AUTO_TEST_CASE(return_max_weight_sportsman_from_sportsmans_array)
	{
		Sportsman max;
		BOOST_CHECK(FindMax(sportsmanArr, max, CWeightComparator()));
		BOOST_CHECK_EQUAL(max.name, "Jane");
	}
	BOOST_AUTO_TEST_CASE(return_max_height_sportsman_from_sportsmans_array)
	{
		Sportsman max;
		BOOST_CHECK(FindMax(sportsmanArr, max, CHeightComparator()));
		BOOST_CHECK_EQUAL(max.name, "John");
	}

BOOST_AUTO_TEST_SUITE_END()