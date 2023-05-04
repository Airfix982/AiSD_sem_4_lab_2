#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include"sort_funcs.hpp"
using namespace std;

template<typename T>
stats shaker_sort(vector<T>& vec)
{
	stats statistic;
	auto left = vec.begin();
	auto right = vec.end()-1;
	bool swapped = true;
	while(swapped)
	{
		swapped = false;
		for (auto it = left; it != right; ++it)
		{
			statistic.comparison_count++;
			if (*it > *(it + 1))
			{
				statistic.copy_count++;
				iter_swap(it, it + 1);
				swapped = true;
			}
		}
		if (!swapped) break;
		--right;
		swapped = false;
		for (auto it = right; it != left; --it)
		{
			statistic.comparison_count++;
			if (*it < *(it - 1))
			{
				statistic.copy_count++;
				iter_swap(it, it - 1);
				swapped = true;
			}
		}
		left++;
	}
	return statistic;
};