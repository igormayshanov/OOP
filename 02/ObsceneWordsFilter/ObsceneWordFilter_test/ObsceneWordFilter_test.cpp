#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../ObsceneWordsFilter/ObscenWordsFilterFunctions.h"
#include "../ObsceneWordsFilter/OpenFile.h"
#include "../ObsceneWordsFilter/ParseArgs.h"


SCENARIO("OpenFile")
{
	std::string fileName;
	std::ifstream inputFile;
	WHEN("input missing file")
	{
		fileName = "abc.txt";
		THEN("the output will be nullopt")
		{
			CHECK(OpenFile(fileName) == std::nullopt);
		}
	}
	WHEN("input existing file")
	{
		fileName = "emptyFile.txt";
		THEN("the output will be not nullopt")
		{
			CHECK(OpenFile(fileName) != std::nullopt);
		}
	}
}

SCENARIO("FillSetFromFile")
{
	std::set<std::string> outputSet;
	WHEN("input word is empty")
	{
		std::string filename = "emptyFile.txt";
		std::ifstream input(filename);
		THEN("output set is also empty")
		{
			outputSet = FillSetFromFile(input);
			CHECK(outputSet.empty());
		}
	}
	WHEN("input file contain one row")
	{
		std::string filename = "1row.txt";
		std::ifstream input(filename);
		THEN("output set contain 1 element")
		{
			outputSet = FillSetFromFile(input);
			std::string testString = "abc";
			CHECK(outputSet.find(testString) != outputSet.end());
		}
	}
	WHEN("input file contain two row")
	{
		std::string filename = "2row.txt";
		std::ifstream input(filename);
		THEN("output set contain 2 element")
		{
			outputSet = FillSetFromFile(input);
			std::string testString = "abc";
			std::string testString1 = "def";
			CHECK(outputSet.find(testString) != outputSet.end());
			CHECK(outputSet.find(testString1) != outputSet.end());
		}
	}
}
//проверить на конкретное количество слов

SCENARIO("FilterObsceneWord")
{
	std::unordered_set<char> delimetrs = { ' ', '\"', '+', '-', '=', '#', '*', '\\', '{', '}', '(', ')', '[', ']', '\'', ':', ';',
		',', '.', '!', '&' };
	std::set<std::string> obsceneWords = {
		"shit",
		"bitch",
		"дура"
	};
	std::string resultString;
	WHEN("input word is empty")
	{
		std::string str = "";
		THEN("output is also empty")
		{
			CHECK(FilterObsceneWord(obsceneWords, str, delimetrs).empty());
		}
	}
	WHEN("input string is empty")
	{
		std::string str = "";
		THEN("output is also empty")
		{
			CHECK(FilterObsceneWord(obsceneWords, str, delimetrs).empty());
		}
	}
	WHEN("input string contains one swear word")
	{
		std::string str = "shit";
		THEN("output is empty")
		{
			resultString = "";
			CHECK(FilterObsceneWord(obsceneWords, str, delimetrs) == resultString);
		}
	}
	WHEN("input string contains one not swear word")
	{
		std::string str = "abc";
		THEN("output string equals input")
		{
			resultString = "abc";
			CHECK(FilterObsceneWord(obsceneWords, str, delimetrs) == resultString);
		}
	}
	WHEN("the input string contains delimiter before swear word")
	{
		std::string str = ",shit";
		THEN("output string contains only delimetr")
		{
			resultString = ",";
			CHECK(FilterObsceneWord(obsceneWords, str, delimetrs) == resultString);
		}
	}
	WHEN("the input string contains delimiter after swear word")
	{
		std::string str = "shit,";
		THEN("output string contains only delimetr")
		{
			resultString = ",";
			CHECK(FilterObsceneWord(obsceneWords, str, delimetrs) == resultString);
		}
	}
	WHEN("input string contains multiple delimited words and swear words")
	{
		std::string str = "!ShIt,you,bitch!";
		THEN("output string does not contain swear words")
		{
			resultString = "!,you,!";
			CHECK(FilterObsceneWord(obsceneWords, str, delimetrs) == resultString);
		}
	}
}