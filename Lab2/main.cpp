#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
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

void print_vec(const vector<int>& vec)
{
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}

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

void add_element(vector<int>& vec)
{
	double value;
	while (1)
	{
		system("cls");
		ConsoleCursorVisible(true, 100);
		SetConsoleTextAttribute(hStdOut, DEF_COL);
		cout << "Введите значение: ";
		int choice = 0;
		while (!(cin >> value) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');

			choice = incorect_insert(1);

			break;
		}
		if (double(int(value)) != value) choice = incorect_insert(2);
		if (choice == 1) continue;
		else if (choice == 2) return;
		else vec.push_back(value);
		return;
	}


}

int main()
{
	setlocale(0, "Rus");
	string main_menu[] = { "Добавьть элемент","Удалить элемент","Сортировкка пузырьком","Шейкерная сортировка","Закончить (ESC)" };
	int active_menu = 0;
	ConsoleCursorVisible(false, 100);
	vector<int> vec;
	char ch;
	while (true)
	{
		
		system("cls");

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
			cout << endl << endl;
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
				add_element(vec);
				break;
			case 1:
				//Speed_test_menu();
				break;
			case 2:
				//Task_menu();
				break;
			case 3:
				SetConsoleTextAttribute(hStdOut, DEF_COL);
				exit(0);
			}
			break;
		default:
			system("cls");
			break;


		}


	}


}