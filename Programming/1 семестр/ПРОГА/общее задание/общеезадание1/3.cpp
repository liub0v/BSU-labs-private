/*поиск вещественных чисел в строке. сортировка по младшей цифре целой части. большая дробная часть*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <locale>
#include <cmath>
using namespace std;

void qs(int *items, int left, int right)
{
	register int i, j;
	int x, y;

	i = left; j = right;
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
void quick(int *items, int count)
{
	qs(items, 0, count - 1);
}

void sort(double*mas)
{
	int *mas1;
	mas1 = new int[sizeof(mas)];
	for (int i = 0; i < sizeof(mas); i++)
		mas1[i] = 0;
	double integer;
	double maxfr = modf(fabs(mas[0]), &integer);
	for (int i = 0; i < sizeof(mas); ++i)
	{
		if (modf(fabs(mas[i]), &integer) > maxfr)
			maxfr = modf(fabs(mas[i]), &integer);
		mas1[i] = integer;
	}
	cout << "Maximum fractional part: " << maxfr << endl;
	int *mas2;
	mas2 = new int[sizeof(mas1)];
	for (int i = 0; i < sizeof(mas1); ++i)
		mas2[i] = mas1[i] % 10;
	quick(mas2, sizeof(mas1));
	cout << "Numbers sorted by lower integer part: ";
	for (int i = 0; i < sizeof(mas2); ++i)
		cout << mas2[i] << " ";
	cout << endl;
	delete[]mas1;
	delete[]mas2;
}
void find_sort(char *str)
{
	char *numbers;
	int count = 0;
	double*mas = new double[80];
	numbers = strtok(str, " ,");
	for (int i = 0; i <= 80; i++)
		mas[i] = 0;
	int num = 0;
	while (numbers)
	{
		double num = atof(numbers);
		if (num != 0)
		{
			mas[count] = num;
			++count;
		}
		numbers = strtok(NULL, " ,");
	}
	cout << "Array of numbers from string: ";
	for (int i = 0; i < count; ++i)
		cout << mas[i] << " ";
	cout << endl;
	sort(mas);
	
}

void main()
{
	ifstream file("chisla.txt");
	if (!file)
	{
		cout << "no such file\n";
		exit(0);
	}
	char str[80];
	file.getline(str, 80);
	find_sort(str);

	system("pause");
}