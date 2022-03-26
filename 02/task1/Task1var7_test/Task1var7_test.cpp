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
		std::vector<float> input = {1.111, 2.001, 3.2222};
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
		std::vector<float> input = {0, 0, 0};
		float sum = 0;
		THEN("sum is equal null")
		{
			sum = CalculateSumOfMinElements(input, 3) == 0;
		}
	}
	WHEN("input vector contain one number")
	{
		std::vector<float> input = {1};
		float sum = 0;
		THEN("sum is equal to the number itself")
		{
			sum = CalculateSumOfMinElements(input, 1) == 1;
		}
	}
	WHEN("input vector contain several numbers")
	{
		std::vector<float> input = { 1.1, 2.2, 3.3, 4.4 };
		float sum = 0;
		THEN("sum = 6.6")
		{
			sum = CalculateSumOfMinElements(input, 3) == 6.6;
		}
	}
}

SCENARIO("AddNumberToVectorElements")
{
	WHEN("input vector is empty and added number = 0")
	{
		std::vector<float> input = {};
		float sum = 0;
		std::vector<float> output = {};
		THEN("output vector is empty")
		{
			output = AddNumberToVectorElements(input, sum);
			output.empty();
		}
	}
	WHEN("input vector contain 1 number")
	{
		std::vector<float> input = {1.1};
		float sum = 2.1;
		std::vector<float> correctOutput = { input[0] + sum };
		std::vector<float> output;
		THEN("output vector {3.2}")
		{
			output = AddNumberToVectorElements(input, sum);
			output == correctOutput;
		}
	}
	WHEN("input vector contain several numbers")
	{
		std::vector<float> input = { 1.1, 1.1, 1.1 };
		float sum = 2;
		std::vector<float> correctOutput = { input[0] + sum, input[1] + sum, input[2] + sum };
		std::vector<float> output;
		THEN("output vector {3.1, 3.1, 3.1}")
		{
			output = AddNumberToVectorElements(input, sum);
			output == correctOutput;
		}
	}
}
