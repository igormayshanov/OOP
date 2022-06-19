#pragma once
#include <algorithm>
#include <vector>

struct Sportsman
{
	std::string name;
	unsigned short height;
	unsigned short weight;
};

//template <typename T>
//bool FindMax(std::vector<T> const& arr, T& maxValue)
//{
//	if (arr.empty())
//	{
//		return false;
//	}
//	auto result = std::max_element(arr.begin(), arr.end());
//	maxValue = *result;
//	return true;
//}
//
//template <>
//bool FindMax<const char*>(std::vector<const char*> const& arr,
//	const char*& maxValue)
//{
//	if (arr.empty())
//	{
//		return false;
//	}
//	auto result = std::max_element(arr.begin(), arr.end(),
//		[](const char* s1, const char* s2) { return (strcmp(s1, s2) < 0) ? true : false; });
//	maxValue = *result;
//	return true;
//}
//
//template <typename T>
//bool Maximum(T const& a, T const& b)
//{
//	return a > b;
//}

template <class T>
class CComparator
{
public:
	bool operator()(T const& a, T const& b) const
	{
		return a > b;
	}
};

template <>
class CComparator<const char*>
{
public:
	bool operator()(const char* s1, const char* s2) const
	{
		return (strcmp(s1, s2) < 0) ? true : false;
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
	auto result = std::max_element(arr.begin(), arr.end(), less);
	maxValue = *result;
	return true;
}