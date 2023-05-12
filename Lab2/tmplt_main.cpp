#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<ctime>
#include"sort_funcs.hpp"
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13
#define ACT_COL 11
#define DEF_COL 15
#define RED 12
#define GREEN 10
using namespace std;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);





void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int incorect_insert(const int mistake)
{
	ConsoleCursorVisible(false, 100);
	char ch1;
	int active_adding = 0;
	string adding[] = { "Попытаться снова", "Отмена (ESC)" };

	while (1)
	{

		SetConsoleTextAttribute(hStdOut, RED);
		system("cls");
		if (mistake == 1) cout << endl << endl << "\tВы ввели текст" << endl << endl;
		if (mistake == 2) cout << endl << endl << "\tВы ввели не целое число" << endl << endl;


		for (int i = 0; i < size(adding); i++)
		{
			if (i == active_adding) SetConsoleTextAttribute(hStdOut, ACT_COL);
			else SetConsoleTextAttribute(hStdOut, DEF_COL);
			cout << adding[i] << endl;

		}

		ch1 = _getch();
		if (ch1 == -32) ch1 = _getch();
		switch (ch1)
		{
		case ESC:
			system("cls");
			return 2;

		case UP:
			if (active_adding > 0) active_adding--;
			break;
		case DOWN:
			if (active_adding < size(adding) - 1) active_adding++;
			break;

		case ENTER:
			switch (active_adding)
			{
			case 0:
				system("cls");
				return 1;
			case 1:
				system("cls");
				return 2;
			}
		default:
			break;
		}
	}
}

template<typename T>
void print_vec(const vector<T>& vec)
{
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}

}

bool remove_element(vector<int>& vec)
{
		double value;
	
		system("cls");
		SetConsoleTextAttribute(hStdOut, DEF_COL);
		cout << "Введите значение: ";
		while (1)
		{
			ConsoleCursorVisible(true, 100);
			int choice = 0;
			cout << "Введите значение: ";
			while (!(cin >> value) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');

				choice = incorect_insert(1);

				break;
			}
			if (double(int(value)) != value) choice = incorect_insert(2);
			if (choice == 1) continue;
			else if (choice == 2) return false;
			else
			{
				for (auto iter = vec.begin(); iter != vec.end(); ++iter)
				{
					if (*iter == value)
					{
						vec.erase(iter);
						return true;
					}
				}
				return false;
			}
		}
}

bool remove_element(vector<float>& vec)
{
	float value;

	system("cls");
	SetConsoleTextAttribute(hStdOut, DEF_COL);
	cout << "Введите значение: ";
	while (1)
	{
		ConsoleCursorVisible(true, 100);
		int choice = 0;
		cout << "Введите значение: ";
		while (!(cin >> value) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');

			choice = incorect_insert(1);

			break;
		}
		if (choice == 1) continue;
		else if (choice == 2) return false;
		else
		{
			for (auto iter = vec.begin(); iter != vec.end(); ++iter)
			{
				if (*iter == value)
				{
					vec.erase(iter);
					return true;
				}
			}
			return false;
		}
	}
}

template<typename T>
bool remove_element(vector<T>& vec)
{
	string value;

	system("cls");
	ConsoleCursorVisible(true, 100);
	SetConsoleTextAttribute(hStdOut, DEF_COL);
	cout << "Введите значение: ";
	cin >> value;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
	{
		if (*iter == value)
		{
			vec.erase(iter);
			return true;
		}
	}
	return false;

}

bool add_element(vector<int>& vec)
{
	double value;
	system("cls");
	SetConsoleTextAttribute(hStdOut, DEF_COL);
	while (1)
	{
		ConsoleCursorVisible(true, 100);
		int choice = 0;
		cout << "Введите значение: ";
		while (!(cin >> value) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');

			choice = incorect_insert(1);

			break;
		}
		if (double(int(value)) != value && choice == 0) choice = incorect_insert(2);
		if (choice == 1) continue;
		else if (choice == 2) return false;
		else
		{
			vec.push_back(value);
			return true;
		}
	}
	
}

bool add_element(vector<float>& vec)
{
	float value;
	system("cls");
	SetConsoleTextAttribute(hStdOut, DEF_COL);
	while (1)
	{
		ConsoleCursorVisible(true, 100);
		int choice = 0;
		cout << "Введите значение: ";
		while (!(cin >> value) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');

			choice = incorect_insert(1);

			break;
		}
		if (choice == 1) continue;
		else if (choice == 2) return false;
		else
		{
			vec.push_back(value);
			return true;
		}
	}

}

template<typename T>
bool add_element(vector<T>& vec)
{
	T value;
	system("cls");
	ConsoleCursorVisible(true, 100);
	SetConsoleTextAttribute(hStdOut, DEF_COL);
	cout << "Введите значение: ";
	cin >> value;
	vec.push_back(value);
	return true;
}

void reverse_sort(vector<int>& vec)//from bigger to smaller
{
	auto left = vec.begin();
	auto right = vec.end() - 1;
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (auto it = left; it != right; ++it)
		{
			if (*it < *(it + 1))
			{
				iter_swap(it, it + 1);
				swapped = true;
			}
		}
		if (!swapped) break;
		--right;
		swapped = false;
		for (auto it = right; it != left; --it)
		{
			if (*it > *(it - 1))
			{
				iter_swap(it, it - 1);
				swapped = true;
			}
		}
		left++;
	}
}

void rig_sort(vector<int>& vec)//from smaller to bigger
{
	auto left = vec.begin();
	auto right = vec.end() - 1;
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (auto it = left; it != right; ++it)
		{
			if (*it > *(it + 1))
			{
				iter_swap(it, it + 1);
				swapped = true;
			}
		}
		if (!swapped) break;
		--right;
		swapped = false;
		for (auto it = right; it != left; --it)
		{
			if (*it < *(it - 1))
			{
				iter_swap(it, it - 1);
				swapped = true;
			}
		}
		left++;
	}
}

size_t Rand_val() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}











void tests()
{

	ofstream outfile_b1("bubble_sort_avg.csv");
	ofstream outfile_s1("shaker_sort_avg.csv");
	ofstream outfile_m1("merge_sort_avg.csv");
	ofstream outfile_b2("bubble_sort_sorted.csv");
	ofstream outfile_s2("shaker_sort_sorted.csv");
	ofstream outfile_m2("merge_sort_sorted.csv");
	ofstream outfile_b3("bubble_sort_reverse_sorted.csv");
	ofstream outfile_s3("shaker_sort_reverse_sorted.csv");
	ofstream outfile_m3("merge_sort_reverse_sorted.csv");
	for (int k = 1000; k < 20001; k += 1000)
	{
		cout << k << endl;
		double bbl_avg_cmpr = 0;
		double bbl_avg_copy = 0;
		double bbl_avg_time = 0;

		double bbl_srtd_cmpr = 0;
		double bbl_srtd_copy = 0;
		double bbl_srtd_time = 0;

		double bbl_rev_cmpr = 0;
		double bbl_rev_copy = 0;
		double bbl_rev_time = 0;


		double shk_avg_cmpr = 0;
		double shk_avg_copy = 0;
		double shk_avg_time = 0;

		double shk_srtd_cmpr = 0;
		double shk_srtd_copy = 0;
		double shk_srtd_time = 0;

		double shk_rev_cmpr = 0;
		double shk_rev_copy = 0;
		double shk_rev_time = 0;


		double mrg_avg_cmpr = 0;
		double mrg_avg_copy = 0;
		double mrg_avg_time = 0;

		double mrg_srtd_cmpr = 0;
		double mrg_srtd_copy = 0;
		double mrg_srtd_time = 0;

		double mrg_rev_cmpr = 0;
		double mrg_rev_copy = 0;
		double mrg_rev_time = 0;

		srand(time(0));
		vector<int> vec;
		for (int i = 0; i < k; i++)
		{
			vec.push_back((int)rand());
		}

		cout << "vec is filled" << endl;














		vector<int> sorting_vec = vec;


		clock_t start = clock();
		stats st = bubble_sort(sorting_vec);
		clock_t end = clock();
		bbl_avg_time += (double)(end - start) / CLOCKS_PER_SEC;
		bbl_avg_cmpr += (double)st.comparison_count;
		bbl_avg_copy += (double)st.copy_count;
		cout << "vec is bubble sorted" << endl;


		sorting_vec = vec;
		start = clock();
		st = shaker_sort(sorting_vec);
		end = clock();
		shk_avg_time += (double)(end - start) / CLOCKS_PER_SEC;
		shk_avg_cmpr += (double)st.comparison_count;
		shk_avg_copy += (double)st.copy_count;
		cout << "vec is shaker sorted" << endl;
		sorting_vec = vec;
		start = clock();
		st = merge_sort_a(sorting_vec);
		end = clock();
		mrg_avg_time += (double)(end - start) / CLOCKS_PER_SEC;
		mrg_avg_cmpr += (double)st.comparison_count;
		mrg_avg_copy += (double)st.copy_count;
		cout << "vec is merge sorted" << endl;

		sorting_vec = vec;
		rig_sort(sorting_vec);
		start = clock();
		st = bubble_sort(sorting_vec);
		end = clock();
		bbl_srtd_time += (double)(end - start) / CLOCKS_PER_SEC;
		bbl_srtd_cmpr += (double)st.comparison_count;
		bbl_srtd_copy += (double)st.copy_count;
		cout << "sorted vec is bubble sorted" << endl;


		sorting_vec = vec;
		rig_sort(sorting_vec);
		start = clock();
		st = shaker_sort(sorting_vec);
		end = clock();
		shk_srtd_time += (double)(end - start) / CLOCKS_PER_SEC;
		shk_srtd_cmpr += (double)st.comparison_count;
		shk_srtd_copy += (double)st.copy_count;
		cout << "sorted vec is shaker sorted" << endl;

		sorting_vec = vec;
		rig_sort(sorting_vec);
		start = clock();
		st = merge_sort_a(sorting_vec);
		end = clock();
		mrg_srtd_time += (double)(end - start) / CLOCKS_PER_SEC;
		mrg_srtd_cmpr += (double)st.comparison_count;
		mrg_srtd_copy += (double)st.copy_count;
		cout << "sorted vec is merge sorted" << endl;


		sorting_vec = vec;
		reverse_sort(sorting_vec);
		start = clock();
		st = bubble_sort(sorting_vec);
		end = clock();
		bbl_rev_time += (double)(end - start) / CLOCKS_PER_SEC;
		bbl_rev_cmpr += (double)st.comparison_count;
		bbl_rev_copy += (double)st.copy_count;
		cout << "reverse vec is bubble sorted" << endl;

		sorting_vec = vec;
		reverse_sort(sorting_vec);
		start = clock();
		st = shaker_sort(sorting_vec);
		end = clock();
		shk_rev_time += (double)(end - start) / CLOCKS_PER_SEC;
		shk_rev_cmpr += (double)st.comparison_count;
		shk_rev_copy += (double)st.copy_count;
		cout << "reverse vec is sheker sorted" << endl;

		sorting_vec = vec;
		reverse_sort(sorting_vec);
		start = clock();
		st = merge_sort_a(sorting_vec);
		end = clock();
		mrg_rev_time += (double)(end - start) / CLOCKS_PER_SEC;
		mrg_rev_cmpr += (double)st.comparison_count;
		mrg_rev_copy += (double)st.copy_count;
		cout << "reverse vec is merge sorted" << endl;

		outfile_b1 << bbl_avg_time/100 << "," << bbl_avg_cmpr/100 << "," << bbl_avg_copy/100 << "\n";
		cout << "bubble is written" << endl;

		outfile_s1 << shk_avg_time/100 << "," << shk_avg_cmpr/100 << "," << shk_avg_copy/100 << "\n";
		cout << "sh is written" << endl;

		outfile_m1 << mrg_avg_time/100 << "," << mrg_avg_cmpr/100 << "," << mrg_avg_copy/100 << "\n";
		cout << "mrg is written" << endl;

		outfile_b2 << bbl_srtd_time << "," << bbl_srtd_cmpr << "," << bbl_srtd_copy << "\n";
		cout << "bubble is written" << endl;

		outfile_s2 << shk_srtd_time << "," << shk_srtd_cmpr << "," << shk_srtd_copy << "\n";
		cout << "sh is written" << endl;

		outfile_m2 << mrg_srtd_time << "," << mrg_srtd_cmpr << "," << mrg_srtd_copy << "\n";
		cout << "mrg is written" << endl;

		outfile_b3 << bbl_rev_time << "," << bbl_rev_cmpr << "," << bbl_rev_copy << "\n";
		cout << "bubble is written" << endl;

		outfile_s3 << shk_rev_time << "," << shk_rev_cmpr << "," << shk_rev_copy << "\n";
		cout << "sh is written" << endl;

		outfile_m3 << mrg_rev_time << "," << mrg_rev_cmpr << "," << mrg_rev_copy << "\n";
		cout << "mrg is written" << endl;
	}

	outfile_b1.close();
	outfile_s1.close();
	outfile_m1.close();
	outfile_b2.close();
	outfile_s2.close();
	outfile_m2.close();
	outfile_b3.close();
	outfile_s3.close();
	outfile_m3.close();
}

template<typename T>
void main_menu_tmplt()
{
	
	string main_menu[] = { "Добавьть элемент","Удалить элемент","Сортировкка пузырьком","Шейкерная сортировка","Сортировка слиянием","Провести тесты","назад (ESC)" };
	int active_menu = 0;
	vector<T> vec;
	vector<T> sorted_vec;
	bool sort_flag = false;
	stats results;
	bool done;
	char ch;
	while (true)
	{

		system("cls");
		ConsoleCursorVisible(false, 100);

		if (vec.begin() == vec.end())
		{
			SetConsoleTextAttribute(hStdOut, RED);
			cout << "Вектор пуст" << endl << endl;
			SetConsoleTextAttribute(hStdOut, DEF_COL);
		}
		else
		{
			SetConsoleTextAttribute(hStdOut, GREEN);
			cout << "Вектор: ";
			print_vec(vec);
			cout << endl;
			if (sort_flag)
			{
				SetConsoleTextAttribute(hStdOut, GREEN);
				cout << "Отсортированный вектор: ";
				print_vec(sorted_vec);
				cout << endl << endl;
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, RED);
				cout << "Вектор пока не отсортирован";
				cout << endl << endl;
			}
			SetConsoleTextAttribute(hStdOut, DEF_COL);
		}

		for (int i = 0; i < size(main_menu); i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, ACT_COL);
			else SetConsoleTextAttribute(hStdOut, DEF_COL);
			cout << main_menu[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch();

		switch (ch)
		{
		case ESC:
			SetConsoleTextAttribute(hStdOut, DEF_COL);
			return;


		case UP:
			if (active_menu > 0) active_menu--;
			system("cls");
			break;
		case DOWN:
			if (active_menu < size(main_menu) - 1) active_menu++;
			system("cls");
			break;


		case ENTER:
			switch (active_menu)
			{
			case 0:
				done = add_element(vec);
				if (done) sort_flag = false;
				break;
			case 1:
				done = remove_element(vec);
				if (done) sort_flag = false;
				break;
			case 2:
				sorted_vec = vec;
				results = bubble_sort(sorted_vec);
				sort_flag = true;
				break;
			case 3:
				sorted_vec = vec;
				results = shaker_sort(sorted_vec);
				cout << results.copy_count;
				sort_flag = true;
				break;
			case 4:
				sorted_vec = vec;
				results = merge_sort_a(sorted_vec);
				sort_flag = true;
				break;
			case 5:
				tests();

				break;
			case 6:
				return;
			}
			break;
		default:
			system("cls");
			break;
		}
	}
}

int main()
{
	setlocale(0, "Rus");
	string main_menu[] = { "int","float","std::string","Test class","закончить (ESC)"};
	int active_menu = 0;
	char ch;
	while (true)
	{

		system("cls");
		ConsoleCursorVisible(false, 100);
		SetConsoleTextAttribute(hStdOut, DEF_COL);


		for (int i = 0; i < size(main_menu); i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, ACT_COL);
			else SetConsoleTextAttribute(hStdOut, DEF_COL);
			cout << main_menu[i] << endl;
		}

		ch = _getch();
		if (ch == -32) ch = _getch();

		switch (ch)
		{
		case ESC:
			SetConsoleTextAttribute(hStdOut, DEF_COL);
			exit(0);


		case UP:
			if (active_menu > 0) active_menu--;
			system("cls");
			break;
		case DOWN:
			if (active_menu < size(main_menu) - 1) active_menu++;
			system("cls");
			break;


		case ENTER:
			switch (active_menu)
			{
			case 0:
				main_menu_tmplt<int>();
				break;
			case 1:
				main_menu_tmplt<float>();
				break;
			case 2:
				main_menu_tmplt<string>();
				break;
			case 3:
				main_menu_tmplt<Test_class>();
				break;
			case size(main_menu)-1:
				exit(0);
			}
			break;
		default:
			system("cls");
			break;
		}
	}
}