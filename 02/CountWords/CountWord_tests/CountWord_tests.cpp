#include <iostream>
#include <map>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../CountWords/CountWordsFunctions.h"

SCENARIO("FillMapAndCountWords")
{
	std::map<std::string, unsigned int> outputMap;
	WHEN("input word is empty")
	{
		std::map<std::string, unsigned int> inputMap;
		THEN("output map is also empty")
		{
			outputMap = FillMapAndCountWords(inputMap, "");
			CHECK(outputMap == inputMap);
		}
	}
	WHEN("input 1 word in empty map")
	{
		std::map<std::string, unsigned int> inputMap;
		std::map<std::string, unsigned int> resultMap = { { "word", 1 } };
		THEN("output map contain the key with word name and meaning 1")
		{
			outputMap = FillMapAndCountWords(inputMap, "word");
			CHECK(outputMap == resultMap);
		}
	}
	WHEN("input the word contained in map")
	{
		std::map<std::string, unsigned int> inputMap = { { "word", 1 } };
		std::map<std::string, unsigned int> resultMap = { { "word", 2 } };
		THEN("output map contain the key with word name and meaning 2")
		{
			outputMap = FillMapAndCountWords(inputMap, "word");
			CHECK(outputMap == resultMap);
		}
	}
	WHEN("input the word not contained in map")
	{
		std::map<std::string, unsigned int> inputMap = { { "line", 1 } };
		std::map<std::string, unsigned int> resultMap = { { "line", 1 }, { "word", 1 } };
		THEN("output map contain 2 key with words name and meaning 1")
		{
			outputMap = FillMapAndCountWords(inputMap, "word");
			CHECK(outputMap == resultMap);
		}
	}
}

SCENARIO("CountWordsInLines")
{
	std::map<std::string, unsigned int> outputMap;
	WHEN("input word is empty")
	{
		std::map<std::string, unsigned int> inputMap;
		THEN("output map is also empty")
		{
			outputMap = CountWordsInLines(inputMap, "");
			CHECK(outputMap == inputMap);
		}
	}
	WHEN("input 1 word in empty map")
	{
		std::map<std::string, unsigned int> inputMap;
		std::map<std::string, unsigned int> resultMap = { { "word", 1 } };
		THEN("output map contain the key with word name and meaning 1")
		{
			outputMap = CountWordsInLines(inputMap, "word");
			CHECK(outputMap == resultMap);
		}
	}
	WHEN("input the word contained in map")
	{
		std::map<std::string, unsigned int> inputMap = { { "word", 1 } };
		std::map<std::string, unsigned int> resultMap = { { "word", 2 } };
		THEN("output map contain the key with word name and meaning 2")
		{
			outputMap = FillMapAndCountWords(inputMap, "word");
			CHECK(outputMap == resultMap);
		}
	}
	WHEN("input the word not contained in map")
	{
		std::map<std::string, unsigned int> inputMap = { { "line", 1 } };
		std::map<std::string, unsigned int> resultMap = { { "line", 1 }, { "word", 1 } };
		THEN("output map contain 2 key with words name and meaning 1")
		{
			outputMap = FillMapAndCountWords(inputMap, "word");
			CHECK(outputMap == resultMap);
		}
	}
}