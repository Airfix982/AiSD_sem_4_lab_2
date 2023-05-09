#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include"sort_funcs.hpp"
using namespace std;

template<typename T>
void merge(vector<T>& vec, int left, int mid, int right, stats& statistic)
{
	vector<T> left_array(mid - left + 1);
	vector<T> right_array(right - mid);
	for (int i = 0; i < left_array.size(); i++)
	{
		statistic.copy_count++;
		left_array[i] = vec[left + i];
	}
	for (int i = 0; i < right_array.size(); i++)
	{
		statistic.copy_count++;
		right_array[i] = vec[mid + i + 1];
	}
	int i = 0, j = 0, k = left;
	while (i < left_array.size() && j < right_array.size())
	{

		statistic.comparison_count++;
		if (left_array[i] < right_array[j])
		{
			statistic.copy_count++;
			vec[k++] = left_array[i++];
		}
		else
		{
			statistic.copy_count++;
			vec[k++] = right_array[j++];
		}
		while (i < left_array.size())
		{
			statistic.copy_count++;
			vec[k++] = left_array[i++];
		}
		while (j < right_array.size())
		{
			statistic.copy_count++;
			vec[k++] = left_array[j++];
		}
	}
}

template<typename T>
void merge_sort(vector<T>& vec, int left, int right, stats& statistic)
{

	statistic.comparison_count++;
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	merge_sort(vec, left, mid, statistic);
	merge_sort(vec, mid + 1, right, statistic);
	merge(vec, left, mid, right, statistic);
}

template<typename T>
stats merge_sort_a(vector<T>& vec)
{
	stats statistic;
	if(vec.begin() != vec.end())merge_sort(vec, 0, vec.size() - 1, statistic);
	return statistic;
}