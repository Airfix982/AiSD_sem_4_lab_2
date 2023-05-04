#pragma once
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;
struct stats
{

	size_t comparison_count = 0;
	size_t copy_count = 0;

};

template<typename T>
stats bubble_sort(vector<T>& vec);

template<typename T>
stats shaker_sort(vector<T>& vec);

template stats bubble_sort(vector<int>& vec);
template stats bubble_sort(vector<float>& vec);
template stats bubble_sort(vector<string>& vec);

template stats shaker_sort(vector<int>& vec);
template stats shaker_sort(vector<float>& vec);
template stats shaker_sort(vector<string>& vec);