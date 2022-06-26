#pragma once
#include <algorithm>
#include <vector>

struct Sportsman
{
	std::string name;
	unsigned short height;
	unsigned short weight;
};

template <class T>
class CComparator
{
public:
	bool operator()(T const& a, T const& b) const
	{
		return a < b;
	}
};

template <>
class CComparator<const char*>
{
public:
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};

class CWeightComparator
{
public:
	bool operator()(const Sportsman& s1, const Sportsman& s2) const
	{
		return s1.weight < s2.weight;
	}
};

class CHeightComparator
{
public:
	bool operator()(const Sportsman& s1, const Sportsman& s2) const
	{
		return s1.height < s2.height;
	}
};

template <typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}
	//реализовать своими силами
	auto max = arr.begin();
	auto i = arr.begin();
	++i;
	for (; i != arr.end(); ++i)
	{
		if (less(*max, *i))
		{
			max = i;
		}
	}
	maxValue = *max;
	return true;
}