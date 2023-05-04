#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include"sort_funcs.hpp"
using namespace std;

template<typename T>
stats bubble_sort(vector<T>& vec)
{
	stats statistic;
	for (int i = 0; i < vec.size(); i++)
	{
		for (auto it = vec.begin(); it < vec.end() - 1; it++)
		{
			statistic.comparison_count++;
			if (*it > *(it + 1))
			{
				statistic.copy_count++;
				swap(*it, *(it + 1));
			}
		}
	}
	return statistic;
};