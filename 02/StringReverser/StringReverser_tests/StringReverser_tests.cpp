#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "Reverse.h"

SCENARIO("Reversing of empty string gives an empty string")
{
	REQUIRE(Reverse("").empty());
}
SCENARIO("Reverse of 1 character string is the string itself")
{
	REQUIRE(Reverse("a") == "a");
}
SCENARIO("Reverse of string longer than 1 character")
{
	REQUIRE(Reverse("abc") == "cba");
}
SCENARIO("ReverseLines")
{
	std::ostringstream output;
	WHEN("input stream is empty")
	{
		std::istringstream input("");
		THEN("output stream is also empty")
		{
			ReverseLines(input, output);
			CHECK(output.str().empty());
			CHECK(input.eof());
		}
	}
	WHEN("input stream contains one line")
	{
		std::istringstream input("1 line");
		THEN("output stream contains the line reversed")
		{
			ReverseLines(input, output);
			CHECK(output.str() == "enil 1");
			CHECK(input.eof());
		}
	}
	WHEN("input stream conteins several lines")
	{
		std::istringstream input("1 line\n2 line");
		THEN("output stream contains the line reversed")
		{
			ReverseLines(input, output);
			CHECK(output.str() == "enil 1\nenil 2");
			CHECK(input.eof());
		}
	}
	WHEN("input stream contein EOL in the end")
	{
		std::istringstream input("1 line\n2 line\n");
		THEN("output stream contains EOL in the end well")
		{
			ReverseLines(input, output);
			CHECK(output.str() == "enil 1\nenil 2\n");
			CHECK(input.eof());
		}
	}
}