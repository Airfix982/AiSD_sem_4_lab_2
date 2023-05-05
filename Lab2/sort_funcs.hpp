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

class Test_class
{
private:
	string str;
	float num;

public:
	Test_class(string str = " ", float num = 0);
	bool operator == (const Test_class& new_one) const;
	bool operator > (const Test_class& new_one) const;
	bool operator < (const Test_class& new_one) const;
	string get_str() const;
	float get_float() const;
	void set_str(string str);// cout << отдельно перегружать
	void set_float(float fl);
	friend istream& operator >> (istream& input, Test_class& new_one)
	{
		system("cls");
		cout << "Введите строку: ";
		input >> new_one.str;
		float temp;
		bool correct;
		while (1)
		{
			correct = true;
			cout << "Введите float: ";
			while (!(cin >> temp) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');

				cout << "Вы ввели текст, попытайтесь снова." << endl;
				correct = false;
				break;
			}
			if (correct == true) break;
			else continue;
		}
		new_one.num = temp;
		return input;
	}
	friend ostream& operator << (ostream& output, const Test_class& new_one)
	{
		output << "[" << new_one.str << " ; " << new_one.num << "]";
		return output;
	}
};

template stats bubble_sort(vector<int>& vec);
template stats bubble_sort(vector<float>& vec);
template stats bubble_sort(vector<string>& vec);
template stats bubble_sort(vector<Test_class>& vec);

template stats shaker_sort(vector<int>& vec);
template stats shaker_sort(vector<float>& vec);
template stats shaker_sort(vector<string>& vec);
template stats shaker_sort(vector<Test_class>& vec);