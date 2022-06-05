#include "stdafx.h"
#include "../Time/CTime.h"

struct CTimeFixtureZero
{
	CTimeFixtureZero()
		: time(0, 0, 0)
	{
	}
	CTime time;
};
BOOST_FIXTURE_TEST_SUITE(TimeZero, CTimeFixtureZero)

	BOOST_AUTO_TEST_CASE(hours_init_0_equal_0)
	{
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(minutes_init_0_equal_0)
	{
		BOOST_CHECK_EQUAL(time.GetMinutes(), 0);
	}
	BOOST_AUTO_TEST_CASE(seconds_init_0_equal_0)
	{
		BOOST_CHECK_EQUAL(time.GetSeconds(), 0);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CTimeFixture
{
	CTimeFixture()
		: time(1, 2, 3)
	{
	}
	CTime time;
};
BOOST_FIXTURE_TEST_SUITE(Time, CTimeFixture)

	BOOST_AUTO_TEST_CASE(hours_init_1_equal_1)
	{
		BOOST_CHECK_EQUAL(time.GetHours(), 1);
	}
	BOOST_AUTO_TEST_CASE(minutes_init_2_equal_2)
	{
		BOOST_CHECK_EQUAL(time.GetMinutes(), 2);
	}
	BOOST_AUTO_TEST_CASE(seconds_init_3_equal_3)
	{
		BOOST_CHECK_EQUAL(time.GetSeconds(), 3);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CTimeFixtureOneArg
{
	CTimeFixtureOneArg()
		: time(1000)
	{
	}
	CTime time;
};
BOOST_FIXTURE_TEST_SUITE(Time_from_one_argument, CTimeFixtureOneArg)

	BOOST_AUTO_TEST_CASE(hours_in_1000sec_equal_0)
	{
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(minutes_in_1000sec_equal_16)
	{
		BOOST_CHECK_EQUAL(time.GetMinutes(), 16);
	}
	BOOST_AUTO_TEST_CASE(seconds_in_1000sec_equal_40)
	{
		BOOST_CHECK_EQUAL(time.GetSeconds(), 40);
	}
BOOST_AUTO_TEST_SUITE_END()

struct CTimeFixtureTwoArg
{
	CTimeFixtureTwoArg()
		: time(10, 10)
	{
	}
	CTime time;
};
BOOST_FIXTURE_TEST_SUITE(Time_from_two_argument, CTimeFixtureTwoArg)

	BOOST_AUTO_TEST_CASE(hours_in_10h_10m_0s_equal_10)
	{
		BOOST_CHECK_EQUAL(time.GetHours(), 10);
	}
	BOOST_AUTO_TEST_CASE(minutes_in_10h_10m_0s_equal_10)
	{
		BOOST_CHECK_EQUAL(time.GetMinutes(), 10);
	}
	BOOST_AUTO_TEST_CASE(seconds_in_10h_10m_0s_equal_0)
	{
		BOOST_CHECK_EQUAL(time.GetSeconds(), 0);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(hour_more_than_23_should_throw_an_exception_out_of_range)
{
	BOOST_CHECK_THROW(CTime time(25, 0, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(minutes_more_than_59_should_throw_an_exception_out_of_range)
{
	BOOST_CHECK_THROW(CTime time(21, 60, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(seconds_more_than_59_should_throw_an_exception_out_of_range)
{
	BOOST_CHECK_THROW(CTime time(21, 59, 60), std::out_of_range);
}
// argumet less_than_0
BOOST_AUTO_TEST_CASE(hour_less_than_0_should_throw_an_exception_out_of_range)
{
	BOOST_CHECK_THROW(CTime time(-25, 0, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(minutes_less_than_0_should_throw_an_exception_out_of_range)
{
	BOOST_CHECK_THROW(CTime time(21, -1, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(seconds_less_than_0_should_throw_an_exception_out_of_range)
{
	BOOST_CHECK_THROW(CTime time(21, 59, -1), std::out_of_range);
}

BOOST_FIXTURE_TEST_SUITE(Increment_decremet_operator, CTimeFixture)
	BOOST_AUTO_TEST_CASE(prefix_increment_3sec_equal_4)
	{
		++time;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 4);
	}
	BOOST_AUTO_TEST_CASE(postfix_increment_3sec_sec_equal_3)
	{
		CTime time1 = time++;
		BOOST_CHECK_EQUAL(time1.GetSeconds(), 3);
	}
	BOOST_AUTO_TEST_CASE(prefix_decrement_3sec_equal_2)
	{
		--time;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 2);
	}
	BOOST_AUTO_TEST_CASE(postfix_decrement_3sec_equal_3)
	{
		CTime time1 = time--;
		BOOST_CHECK_EQUAL(time1.GetSeconds(), 3);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(Decrement_zero_argument, CTimeFixtureZero)
	BOOST_AUTO_TEST_CASE(prefix_decrement_0sec_equal_59sec)
	{
		--time;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 59);
	}
	BOOST_AUTO_TEST_CASE(postfix_decrement_0sec_equal_0sec)
	{
		CTime time1 = time--;
		BOOST_CHECK_EQUAL(time1.GetSeconds(), 0);
	}
BOOST_AUTO_TEST_SUITE_END()
//написать тест на инкремент макс секондс
struct CTimeFixtureMaxSec
{
	CTimeFixtureMaxSec()
		: time(86399)
	{
	}
	CTime time;
};
BOOST_FIXTURE_TEST_SUITE(increment_max_argument, CTimeFixtureMaxSec)
	BOOST_AUTO_TEST_CASE(prefix_increment_86399sec_equal_0sec)
	{
		++time;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 0);
	}
	BOOST_AUTO_TEST_CASE(postfix_increment_86399sec_equal_59sec)
	{
		CTime time1 = time++;
		BOOST_CHECK_EQUAL(time1.GetSeconds(), 59);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(binary_operators, CTimeFixtureOneArg)
	BOOST_AUTO_TEST_CASE(_1000sec_plus_1_equal_0h_16min_41sec)
	{
		CTime time1(1);
		CTime result = time + time1;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 41);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 16);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(reduced_plus_1000sec_whith_1_equal_0h_16min_41sec)
	{
		CTime time1(1);
		time += time1;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 41);
		BOOST_CHECK_EQUAL(time.GetMinutes(), 16);
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_minus_1_equal_0h_16min_39sec)
	{
		CTime time1(1);
		CTime result = time - time1;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 39);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 16);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_reduced_minus_1000sec_minus_1_equal_0h_16min_39sec)
	{
		CTime time1(1);
		time -= time1;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 39);
		BOOST_CHECK_EQUAL(time.GetMinutes(), 16);
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_plus_85401_equal_0h_0min_0sec)
	{
		CTime time1(85401);
		CTime result = time + time1;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 1);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_minus_1000sec_minus_1001_equal_0h_0min_1sec)
	{
		CTime time1(1001);
		CTime result = time - time1;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 1);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_reduced_plus_1000sec_plus_85401_equal_0h_0min_0sec)
	{
		CTime time1(85401);
		time += time1;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 1);
		BOOST_CHECK_EQUAL(time.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_reduced_minus_1000sec_minus_1001_equal_0h_0min_1sec)
	{
		CTime time1(1001);
		time -= time1;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 1);
		BOOST_CHECK_EQUAL(time.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_multiply_3_equal_0h_50min_0sec)
	{
		CTime result = time * 3;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 50);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_multiply_minus_3_equal_0h_50min_0sec)
	{
		CTime result = time * -3;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 10);
		BOOST_CHECK_EQUAL(result.GetHours(), 23);

	}
	BOOST_AUTO_TEST_CASE(_1000sec_multiply_90_equal_1h_00min_00sec)
	{
		CTime result = time * 90;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(result.GetHours(), 1);
	}
	BOOST_AUTO_TEST_CASE(_3_multiply_1000sec_equal_0h_50min_0sec)
	{
		CTime result = 3 * time;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 50);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_90_multiply_1000sec_equal_1h_00min_00sec)
	{
		CTime result = 90 * time;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(result.GetHours(), 1);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_reduced_multiply_3_equal_0h_50min_0sec)
	{
		time *= 3;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(time.GetMinutes(), 50);
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_reduced_multiply_90_equal_1h_00min_00sec)
	{
		time *= 90;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(time.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(time.GetHours(), 1);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_reduced_multiply_0_equal_0h_00min_00sec)
	{
		time *= 0;
		BOOST_CHECK_EQUAL(time.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(time.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(time.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_divided_by_5_equal_0h_3min_20sec)
	{
		CTime result = time / 5;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 20);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 3);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_divided_by_2000_equal_0h_0min_0sec)
	{
		CTime result = time / 2000;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_divided_by_0_must_throw_exception_division_by_zero)
	{
		BOOST_CHECK_THROW(CTime result = time / 0, std::invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_divided_by_200sec_equal_0h_0min_5sec)
	{
		CTime divisor(200);
		CTime result = time / divisor;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 5);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_divided_by_2000sec_equal_0h_0min_0sec)
	{
		CTime divisor(2000);
		CTime result = time / divisor;
		BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
		BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
		BOOST_CHECK_EQUAL(result.GetHours(), 0);
	}
	BOOST_AUTO_TEST_CASE(_1000sec_divided_by_0sec_must_throw_exception)
	{
		CTime divisor(0);
		BOOST_CHECK_THROW(CTime result = time / divisor, std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()
