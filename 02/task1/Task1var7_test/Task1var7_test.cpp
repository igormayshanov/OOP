#include <string>
#include <vector>
#include <optional>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../task1/HandleVector.h"


SCENARIO("FillVector")
{
	WHEN("input is empty")
	{
		std::string str = "";
		THEN("output must be nullopt")
		{
			auto output = FillVector(str);
			CHECK(output == std::nullopt);
		}
	}
	WHEN("input string contains one number")
	{
		std::string str = "1";
		std::vector<float> input = { 1 };
		THEN("output string must contains one number")
		{
			auto output = FillVector(str);
			CHECK(output == input);
		}
	}
	WHEN("input string contains more than one numbers")
	{
		std::string str = "1.111 2.001 3.2222";
		std::vector<float> input = {1.111f, 2.001f, 3.222f};
		THEN("output string must contains all input numbers")
		{
			auto output = FillVector(str);
			CHECK(output == input);
		}
	}
	WHEN("input string contains non-numeric characters")
	{
		std::string str = "a1.111 2.001 3.2222";
		THEN("output must be nullopt")
		{
			auto output = FillVector(str);
			CHECK(output == std::nullopt);
		}
	}
}

SCENARIO("CalculateSumOfMinElements")
{
	WHEN("input vector is empty")
	{
		std::vector<float> input = {};
		THEN("sum is equal null")
		{
			CHECK(CalculateSumOfMinElements(input, 0) == 0);
		}
	}
	WHEN("input vector contain one number")
	{
		std::vector<float> input = {1};
		float result = 1;
		THEN("sum is equal to the number itself")
		{
			CHECK(CalculateSumOfMinElements(input, 1) == result);
		}
	}
	WHEN("input vector contain several numbers")
	{
		std::vector<float> input = { 1.1f, 2.2f, 3.3f, 4.4f };
		float result = 6.6;
		THEN("sum == 6.6")
		{
			CHECK(CalculateSumOfMinElements(input, 3) == result);
		}
	}
}

SCENARIO("AddNumberToVectorElements")
{
	WHEN("input vector is empty and added number = 0")
	{
		std::vector<float> input = {};
		float number = 0;
		THEN("output vector is empty")
		{
			AddNumberToVectorElements(input, number);
			CHECK(input.empty());
		}
	}
	WHEN("input vector contain 1 number")
	{
		std::vector<float> input = {1.1f};
		float number = 2.1f;
		std::vector<float> correctOutput = {3.2f};
		THEN("output vector {3.2}")
		{
			AddNumberToVectorElements(input, number);
			CHECK(input == correctOutput);
		}
	}
	WHEN("input vector contain several numbers")
	{
		std::vector<float> input = { 1.1, 1.1, 1.1 };
		float number = 2;
		std::vector<float> correctOutput = { 3.1, 3.1, 3.1 };
		THEN("output vector {3.1, 3.1, 3.1}")
		{
			AddNumberToVectorElements(input, number);
			CHECK(input == correctOutput);
		}
	}
}
