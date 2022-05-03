#include <iostream>   
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../ExtraSpaceRemover/RemoveExtraSpaces.h"

SCENARIO("Remove extra spaces of empty string gives an empty string")
{
	REQUIRE(RemoveExtraSpaces("").empty());
}
SCENARIO("Remove extra spaces from strig contains only spaces")
{
	REQUIRE(RemoveExtraSpaces("     ").empty());
}
SCENARIO("Remove spaces from string whithout spaces is the string itself")
{
	REQUIRE(RemoveExtraSpaces("abbbc") == "abbbc");
}
SCENARIO("Remove spaces from string with one character is the string itself")
{
	REQUIRE(RemoveExtraSpaces("A") == "A");
}
SCENARIO("Remove spaces from the beginning of the string")
{
	REQUIRE(RemoveExtraSpaces("  abc") == "abc");
}
SCENARIO("Remove spaces from the end of the string")
{
	REQUIRE(RemoveExtraSpaces("abc  ") == "abc");
}
SCENARIO("Remove extra spaces between the strings")
{
	REQUIRE(RemoveExtraSpaces("  a  b  c  ") == "a b c");
}

SCENARIO("RemoveExtraSpacesFromLines")
{
	std::ostringstream output;
	WHEN("input stream is empty")
	{
		std::istringstream input("");
		THEN("output stream is also empty")
		{
			RemoveExtraSpacesFromLines(input, output);
			CHECK(output.str().empty());
			CHECK(input.eof());
		}
	}
	WHEN("input stream contains one line")
	{
		std::istringstream input("  1   line");
		THEN("output stream contains the line reversed")
		{
			RemoveExtraSpacesFromLines(input, output);
			CHECK(output.str() == "1 line");
			CHECK(input.eof());
		}
	}
	WHEN("input stream contains several lines")
	{
		std::istringstream input(" 1  line\n 2   line");
		THEN("output stream contains the line reversed")
		{
			RemoveExtraSpacesFromLines(input, output);
			CHECK(output.str() == "1 line\n2 line");
			CHECK(input.eof());
		}
	}
	WHEN("input stream contain EOL in the end")
	{
		std::istringstream input("  1   line  \n  2   line\n");
		THEN("output stream contains EOL in the end well")
		{
			RemoveExtraSpacesFromLines(input, output);
			CHECK(output.str() == "1 line\n2 line\n");
			CHECK(input.eof());
		}
	}
	WHEN("input stream contain empty line")
	{
		std::istringstream input("  1   line  \n\n  2   line");
		THEN("output stream contains empty line well")
		{
			RemoveExtraSpacesFromLines(input, output);
			CHECK(output.str() == "1 line\n\n2 line");
			CHECK(input.eof());
		}
	}
}