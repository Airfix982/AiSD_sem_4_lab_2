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
	int left = 0;
	int right = vec.size()-1;
	bool swapped = true;
	while(swapped)
	{
		swapped = false;
		for (int i = left; i < right; i++)
		{
			statistic.comparison_count++;
			if (vec[i] > vec[i + 1])
			{
				statistic.copy_count++;
				swap(vec[i], vec[i+1]);
				swapped = true;
			}
		}
		if (!swapped) break;
		swapped = false;
		for (int i = right-1; i>=left;i--)
		{
			statistic.comparison_count++;
			if (vec[i] > vec[i + 1])
			{
				statistic.copy_count++;
				swap(vec[i], vec[i + 1]);
				swapped = true;
			}
		}
		left++;
		right--;
	}
	return statistic;
};